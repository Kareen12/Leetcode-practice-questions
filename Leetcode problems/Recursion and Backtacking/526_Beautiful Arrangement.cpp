class Solution {
public:
    void solve( vector<int> &v, int &n, int &ans, int start){
        //Base case
        if(start>=n+1){
            ans+=1;
            return;
        }
        
        for(int i=1;i<=n;i++){
            if(v[i]==0 && (start%i==0 || i%start==0)){
                v[i] = start;
                solve(v, n, ans, start+1);
                v[i] = 0;
            }
        }
    }
    int countArrangement(int n) {
        vector<int> v(n+1);
        int ans = 0;
        solve(v, n, ans, 1);
        return ans;
    }
};