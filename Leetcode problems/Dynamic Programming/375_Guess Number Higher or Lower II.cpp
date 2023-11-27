// MEMOISATION
class Solution {
    int solve(int start, int end, vector<vector<int> > &dp){
        if(start >= end){
            return 0;
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }

        int ans = INT_MAX;
        for(int i=start; i<=end; i++){
            ans = min(ans, i + max( solve(start, i-1, dp), solve(i+1, end, dp) ) );
        }
        dp[start][end] = ans;
        return ans;
    }
public:
    int getMoneyAmount(int n) {
        vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
        return solve(1,n, dp);
    }
};

// TABULATION
class Solution {
    int solveUsingTab(int n){
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int i=n; i>=1; i--){
            for(int j=1; j<=n; j++){
                if(i >= j){
                    continue;
                }
                else{
                    int ans = INT_MAX;
                    for(int x=i; x<=j; x++){
                        ans = min(ans, x + max( dp[i][x-1], dp[x+1][j] ) );
                    }
                    dp[i][j] = ans;
                }
            }
        }
        return dp[1][n];
    }
public:
    int getMoneyAmount(int n) {
        return solveUsingTab(n);
    }
};