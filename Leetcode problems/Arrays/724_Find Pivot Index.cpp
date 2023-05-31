class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightSideSum= accumulate(nums.begin(),nums.end(),0);
        int leftSideSum = 0;
        for(int i=0;i<nums.size();i++){
            leftSideSum += nums[i];
            
            if(rightSideSum==leftSideSum)
                return i;
            
            rightSideSum -= nums[i];
        }
        return -1;
    }
};