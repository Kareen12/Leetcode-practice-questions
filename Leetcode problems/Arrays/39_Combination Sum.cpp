//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void solve(vector<int> &q, vector<vector<int> > &ans, vector<int> &v, int target, int index){
        //Base case
        if(target==0){
            // sort(v.begin(), v.end());
            ans.push_back(v);
            return;
        }
        if(target < 0){
            return;
        }
        
        for(int i=index;i<q.size();i++){
            v.push_back(q[i]);
            solve(q, ans, v, target-q[i], i);
            //Backtracking
            v.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int> > ans;
        vector<int> v;
        
        set<int> st;
        for(auto i: A){
            st.insert(i);
        }
        vector<int> q;
        for(auto j: st){
            q.push_back(j);
        }
        
        solve(q, ans, v, B, 0);
        // sort(ans.begin(),ans.end());
        return ans;
    }
};