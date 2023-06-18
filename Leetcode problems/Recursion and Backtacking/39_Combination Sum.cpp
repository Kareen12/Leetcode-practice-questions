class Solution {
public:
    void solve(vector<int>& candidates, vector<vector<int>> &ans, vector<int> &v, int target, int index ){
        //Base case
        if(target == 0){
            ans.push_back(v);
            return;
        }
        if(target < 0){
            return;
        }
        
        for(int i=index; i<candidates.size();i++){
            v.push_back(candidates[i]);
            solve(candidates, ans, v, target-candidates[i], i);
            //Backtracking
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> ans;
         vector<int> v;
         solve(candidates, ans, v, target, 0);
         return ans;
    }
};