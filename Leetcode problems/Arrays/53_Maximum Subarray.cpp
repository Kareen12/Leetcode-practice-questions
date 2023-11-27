class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxx=INT_MIN;
        for(auto it : nums)
        {
            sum+=it;
            maxx=max(sum,maxx);
            if(sum<0) sum=0;
        }
        return maxx;
    }
};

// In case ques asks to print the subarray 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        int n = nums.size();
        int ansStart = -1;
        int start = -1;
        int end = -1;
        for(int i=0; i<n; i++){
            if(sum == 0) start = i;
            sum += nums[i];

            if(sum > maxi) {
                maxi = sum;
                ansStart = start;
                end = i;
            }

            if(sum < 0) sum = 0;
        }

        vector<int> v;
        for(int j=ansStart; j<=end; j++){
            v.push_back(nums[j]);
            cout<<v[j]<<" "; // this line is giving error on leetcode
        }

        // This works
         for(int j=ansStart; j<=end; j++){
            cout<<nums[j]<<" ";
        }

        return maxi;
    }
};