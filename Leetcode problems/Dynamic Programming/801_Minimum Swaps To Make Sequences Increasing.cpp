class Solution
{
public:
    // MEMOISATION
    int solve(vector<int> &nums1, vector<int> &nums2, int i, int p1, int p2, vector<vector<int>> &dp, bool isSwap)
    {
        if (i >= nums1.size())
            return 0;

        if (dp[i][isSwap] != -1)
            return dp[i][isSwap];
        int swap = INT_MAX;
        if (p1 < nums2[i] && p2 < nums1[i])
        {
            swap = 1 + solve(nums1, nums2, i + 1, nums2[i], nums1[i], dp, 1);
        }
        int noSwap = INT_MAX;
        if (p1 < nums1[i] && p2 < nums2[i])
        {
            noSwap = solve(nums1, nums2, i + 1, nums1[i], nums2[i], dp, 0);
        }

        dp[i][isSwap] = min(swap, noSwap);
        return dp[i][isSwap];
    }

    // TABULATION
    int solveTab(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, 0));

        for (int i = nums1.size() - 1; i >= 01; i--)
        {
            for (int j = 1; j >= 0; j--)
            {
                int p1 = nums1[i - 1];
                int p2 = nums2[i - 1];
                if (j)
                {
                    swap(p1, p2);
                }
                int swap = INT_MAX;
                if (p1 < nums2[i] && p2 < nums1[i])
                {
                    swap = 1 + dp[i + 1][1];
                }
                int noSwap = INT_MAX;
                if (p1 < nums1[i] && p2 < nums2[i])
                {
                    noSwap = dp[i + 1][0];
                }
                dp[i][j] = min(swap, noSwap);
            }
        }
        return dp[1][0];
    }

    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, -1));
        //    return solve(nums1, nums2, 0, -1, -1, dp, 0);
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        return solveTab(nums1, nums2);
    }
};