// MEMOISATION
class Solution {
    int solve(vector<int>& nums, int curr, int prev,  vector<vector<int> > &dp){
        if(curr >= nums.size()){
            return 0;
        }

        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }

        // include case
        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solve(nums, curr+1, curr, dp);
        }

        // exclude case
        int exclude = solve(nums, curr+1, prev, dp);

        return dp[curr][prev+1] = max(include, exclude);
    } 
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
        int curr = 0;
        int prev = -1;
        return solve(nums, curr, prev, dp);
    }
};

// TABULATION
class Solution {
    int solveUsingTab(vector<int>& nums){
        int n = nums.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));

        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    include = 1 + dp[curr+1][curr+1];
                }

                // exclude case
                int exclude = dp[curr+1][prev+1];

                dp[curr][prev+1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        return solveUsingTab(nums);
    }
};

// SPACE OPTIMISATION
class Solution {
    int solveUsingSO(vector<int>& nums){
        int n = nums.size();
        vector<int> curr1(n+1, 0);
        vector<int> next(n+1, 0);

        
        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    include = 1 + next[curr+1];
                }

                // exclude case
                int exclude = next[prev+1];

               curr1[prev+1] = max(include, exclude);
            }
            next = curr1;
        }
        return next[0];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        return solveUsingSO(nums);
    }
};

// USING BINARY SEARCH
class Solution {
int dpInStrings(vector<int>& nums){
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i=1; i<n; i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                //just bada element dhundenge
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        return dpInStrings(nums);
    }
};