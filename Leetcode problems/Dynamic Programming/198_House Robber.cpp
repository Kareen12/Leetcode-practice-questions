// RECURSION + MEMOISATION
class Solution {
    int solve(vector<int>& nums, int n, vector<int> &dp){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return nums[0];
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int include = solve(nums, n-2, dp) + nums[n];
        int exclude = solve(nums, n-1, dp);

        dp[n] = max(include, exclude);
        return dp[n];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int> dp(n+1, -1);
        return solve(nums, n,dp);
    }
};

// TABULATION METHOD
class Solution {
    int solveUsingTabulation(vector<int>& nums, int n){
        vector<int> dp(n+1, 0);

        dp[0] = nums[0];

        for(int i=1; i<=n; i++){
            int temp = 0;
            if(i-2 >= 0){
                temp = dp[i-2];
            }
            int include = temp + nums[i];
            int exclude = dp[i-1];
            dp[i] = max(include, exclude);
        }
        return dp[n];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        return solveUsingTabulation(nums, n);
    }
};

// SPACE OPTIMISATION 
class Solution {
    int spaceOptimisedSol(vector<int>& nums, int n){
        int curr = 0;
        int prev2 = 0;
        int prev1 = nums[0];

        for(int i=1; i<=n; i++){
            int temp = 0;
            if(i-2 >= 0){
                temp = prev2;
            }
            int include = temp + nums[i];
            int exclude = prev1;
            curr = max(include, exclude);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        return spaceOptimisedSol(nums, n);
    }
};
