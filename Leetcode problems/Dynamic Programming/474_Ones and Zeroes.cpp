class Solution
{
public:
    void convertToV(vector<string> &strs, vector<pair<int, int>> &v)
    {
        for (auto i : strs)
        {
            int zeroes = 0, ones = 0;
            for (auto ch : i)
            {
                if (ch == '0')
                    zeroes++;
                if (ch == '1')
                    ones++;
            }
            v.push_back({zeroes, ones});
        }
    }

    // MEMOISATION
    int solve(int start, vector<pair<int, int>> &v, int m, int n, vector<vector<vector<int>>> &dp)
    {
        if (start >= v.size())
            return 0;

        if (dp[start][m][n] != -1)
            return dp[start][m][n];
        int include = 0, exclude = 0;

        int zeroes = v[start].first;
        int ones = v[start].second;

        if (m - zeroes >= 0 && n - ones >= 0)
        {
            include = 1 + solve(start + 1, v, m - zeroes, n - ones, dp);
        }
        exclude = solve(start + 1, v, m, n, dp);

        dp[start][m][n] = max(include, exclude);
        return dp[start][m][n];
    }

    // TABULATION
    int solveTab(vector<pair<int, int>> &v, int m, int n)
    {
        vector<vector<vector<int>>> dp(v.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        for (int s = v.size() - 1; s >= 0; s--)
        {
            for (int i = 0; i <= m; i++)
            {
                for (int j = 0; j <= n; j++)
                {
                    int include = 0, exclude = 0;

                    int zeroes = v[s].first;
                    int ones = v[s].second;

                    if (i - zeroes >= 0 && j - ones >= 0)
                    {
                        include = 1 + dp[s + 1][i - zeroes][j - ones];
                    }
                    exclude = dp[s + 1][i][j];

                    dp[s][i][j] = max(include, exclude);
                }
            }
        }

        return dp[0][m][n];
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<pair<int, int>> v; // stores number or zeroes and ones in a particular string
        convertToV(strs, v);
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        // return solve(0, v, m ,n, dp);
        return solveTab(v, m, n);
    }
};