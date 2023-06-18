class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, int start){
        if(start >= nums.size()){
            ans.push_back(nums);
            return;
        } 
        
        unordered_map<int, bool> mp;
        for(int i=start;i<nums.size();i++){
            if(mp.find(nums[i]) != mp.end()){
                continue;
            }
            mp[nums[i]] = true;
            swap(nums[i],nums[start]);
            solve(nums, ans, start+1);
            swap(nums[i],nums[start]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,ans, 0);
        return ans;
    }
};