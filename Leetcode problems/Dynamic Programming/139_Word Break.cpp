class Solution
{
public:
    bool checkValid(string s, vector<string> &wordDict)
    {
        for (auto i : wordDict)
        {
            if (s == i)
            {
                return true;
            }
        }
        return false;
    }

    bool solve(string s, vector<string> &wordDict, int start, vector<int> &dp)
    {
        if (start == s.size())
            return 1;

        bool flag = 0;
        string word = "";

        if (dp[start] != -1)
            return dp[start];
        for (int i = start; i < s.size(); i++)
        {
            word += s[i];
            if (checkValid(word, wordDict))
                flag = flag || solve(s, wordDict, i + 1, dp);
        }

        dp[start] = flag;
        return dp[start];
    }

    bool solveTab(string s, vector<string> &wordDict)
    {
        vector<int> dp(s.size() + 1, -1);

        dp[s.size()] = 1;
        for (int start = s.size() - 1; start >= 0; start--)
        {
            bool flag = 0;
            string word = "";
            for (int i = start; i < s.size(); i++)
            {
                word += s[i];
                if (checkValid(word, wordDict))
                    flag = flag || dp[i + 1];
            }
            dp[start] = flag;
        }

        return dp[0];
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        return solveTab(s, wordDict);
    }
};