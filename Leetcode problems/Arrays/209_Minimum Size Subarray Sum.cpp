class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s = 0, e = 0;
        int sum = 0;
        int len = INT_MAX;
        while(e < nums.size()){
            sum += nums[e];

            while(sum >= target){
                int l = e-s+1;
                len = min(len, l);
                sum = sum - nums[s];
                s++;
            }
            e++;
        }
        if(len == INT_MAX){
            return 0;
        }else{
            return len;
        }
    }
};