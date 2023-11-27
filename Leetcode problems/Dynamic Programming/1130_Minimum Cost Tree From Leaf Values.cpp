// MEMOISATION
class Solution {
    int solve(vector<int>& arr, map< pair<int, int> , int >&mp, int left, int right,  vector<vector<int> > &dp){
        // leaf node
        if(left == right){
            return 0;
        }
        int ans = INT_MAX;

        if( dp[left][right] != -1){
            return  dp[left][right];
        }

        for(int i=left; i<right; i++){
            ans = min(ans, mp[{left, i}]*mp[{i+1, right}] + solve(arr, mp, left, i, dp) + solve(arr, mp, i+1, right, dp));
        }
        dp[left][right] = ans;
        return  dp[left][right];
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
        map< pair<int, int> , int> mp;
         for(int i=0; i<n; i++){
           mp[{i,i}] = arr[i];
           for(int j=i+1; j<n; j++){
               mp[{i,j}] = max(arr[j], mp[{i,j-1}]);
           }
        }
        return solve(arr, mp, 0, n-1, dp);
    }
};

// TABULATION
class Solution {
    int solveUsingTab(vector<int>& arr, map< pair<int, int> , int >&mp){
        int n = arr.size();
         vector<vector<int> > dp(n+1, vector<int>(n+1, 0));

         for(int left=n-1; left>=0; left--){
             for(int right=0; right<=n-1; right++){
                    if(left >= right){
                        continue;
                    }
                    else{
                        int ans = INT_MAX;
                        for(int i=left; i<right; i++){
                            ans = min(ans, 
                            mp[{left, i}]*mp[{i+1, right}] + 
                            dp[left][i]+ 
                            dp[i+1][right]);
                        }
                        dp[left][right] = ans;
                    }
            }
        }
        return dp[0][n-1];
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        map< pair<int, int> , int> mp;
         for(int i=0; i<n; i++){
           mp[{i,i}] = arr[i];
           for(int j=i+1; j<n; j++){
               mp[{i,j}] = max(arr[j], mp[{i,j-1}]);
           }
        }
        return solveUsingTab(arr, mp);
    }
};