class Solution {
    int solve(vector<int>& nums, int l, int h){
        int curr = 0;
        int prev2 = 0;
        int prev1 = nums[l];

        for(int i=l+1; i<=h; i++){
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
        int n = nums.size(); 
        // if (n < 2) return n ? nums[0] : 0;
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));
    }
};

// ANOTHER SOLUTION
class Solution {
    int solve(vector<int>& nums, int l, int h){
        int curr = 0;
        int prev2 = 0;
        int prev1 = nums[l];

        for(int i=l+1; i<=h; i++){
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
        int n = nums.size(); 
        if (n < 2) return n ? nums[0] : 0;
        // if (nums.size() == 0) return 0;
        // if (nums.size() == 1) return nums[0];
        // if (nums.size() == 2) return max(nums[0], nums[1]);
        return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));
    }
};