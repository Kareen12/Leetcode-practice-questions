class Solution {
public:
    void solve(int n, int open, int close,  vector<string> &ans, string output){
        // Base Case
        if(open == 0 && close == 0){
            ans.push_back(output);
            return;
        }
        
        // including open brackets
        if(open > 0){
            output.push_back('(');
            solve(n, open-1, close, ans, output);
            //backtracking
            output.pop_back();
        }
        // including closing bracket only if number of closing brackets are more than number           of opening brackets left
        if(close > open){
            output.push_back(')');
            solve(n, open, close-1, ans, output);
            //backtracking
            output.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output = "";
        int open = n;
        int close = n;
        solve(n, open, close, ans, output);
        return ans;
    }
};