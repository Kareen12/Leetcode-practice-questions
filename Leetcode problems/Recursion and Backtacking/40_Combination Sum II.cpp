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
            if(i > index && candidates[i] == candidates[i-1] ){
                continue;
            }
            v.push_back(candidates[i]);
            solve(candidates, ans, v, target-candidates[i], i+1);
            //Backtracking
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
         vector<vector<int>> ans;
         vector<int> v;
         solve(candidates, ans, v, target, 0);
         return ans;
    }
};