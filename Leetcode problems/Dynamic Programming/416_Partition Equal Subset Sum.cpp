    // USING MEMOISATION
    class Solution {
    bool solve(vector<int> &nums, int target, int n, vector<vector<int>> &dp){
        if(n == 0){
            return target == nums[n];
        }

        if(target < 0){
            return 0;
        }

        if(target == 0){
            return 1;
        }

        if(dp[n][target] != -1){
            return dp[n][target];
        }

        bool include = 0;
        if(target >= nums[n]){
            include = solve(nums, target - nums[n], n-1, dp);
        }
        bool exclude = solve(nums, target, n-1, dp);

        dp[n][target] = include || exclude;
        return dp[n][target];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i: nums){
            sum += i;
        }
        if(sum & 1) return 0;
        int n = nums.size();
        int target = sum/2;
        vector<vector<int> > dp(n, vector<int>(target + 1, -1));
        return solve(nums, target, n-1, dp);
    }
};

// ANOTHER WAY FOR ABOVE SOLUTION
class Solution {
    bool solve(vector<int> &nums, int target, int n, vector<vector<int>> &dp){
        int size = nums.size();
        if(n >= size){
            return 0;
        }

        if(target < 0){
            return 0;
        }

        if(target == 0){
            return 1;
        }

        if(dp[n][target] != -1){
            return dp[n][target];
        }

        bool include = solve(nums, target - nums[n], n+1, dp);
        bool exclude = solve(nums, target, n+1, dp);

        dp[n][target] = include || exclude;
        return dp[n][target];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i: nums){
            sum += i;
        }
        if(sum & 1) return 0;
        int n = nums.size();
        int target = sum/2;
        vector<vector<int> > dp(n, vector<int>(target + 1, -1));
        return solve(nums, target, 0, dp);
    }
};

//TABULATION METHOD
class Solution {
    bool solveUsingTab(vector<int> &nums, int target, int n){
        vector<vector<int> > dp(n+1, vector<int>(target + 1, 0));

        for(int i=0; i<n; i++){
            dp[i][0] = 1;
        }

        for(int i=n-1; i>=0; i--){
            for(int j=1; j<=target; j++){
                bool include = 0;
                if(j-nums[i] >= 0){
                    include = dp[i+1][j-nums[i]];
                }
                bool exclude = dp[i+1][j];
                dp[i][j] = include || exclude;
            }
        }
        return dp[0][target];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i: nums){
            sum += i;
        }
        if(sum & 1) return 0;
        int n = nums.size();
        int target = sum/2;
        return solveUsingTab(nums, target, n);
    }
};