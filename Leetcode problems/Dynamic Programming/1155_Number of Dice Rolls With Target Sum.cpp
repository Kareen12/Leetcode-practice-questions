// MEMOISATION
class Solution {
    int M = 1000000007;
    int solve(int n, int k, int target, vector<vector<int> > &dp){
        if(n < 0) return 0;
        if(n == 0 && target != 0) return 0;
        if(n != 0 && target == 0) return 0;
        if(n == 0 && target == 0) return 1;

        if(dp[n][target] != -1){
            return dp[n][target];
        }
        
        long long int ans = 0;
        for(int i=1;i<=k;i++){
            if(target-i >= 0)
                ans = (ans%M + solve(n-1, k, target-i, dp)%M) % M;
        }

        return dp[n][target] = ans;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int> >dp(n+1, vector<int>(target+1, -1));
        return solve(n, k, target, dp);
    }
};

// TABULATION
class Solution {
    int M = 1000000007;
    int solveUsingTab(int n, int k, int target){
        vector<vector<int> >dp(n+1, vector< int>(target+1, 0));

        dp[0][0] = 1;
        for(int in=1; in<=n; in++){
            for(int j=1; j<=target; j++){
                int ans = 0;
                for(int i=1;i<=k;i++){
                    int recAns = 0;
                    if(j-i >= 0)
                        recAns = dp[in-1][j-i];
                        ans = (ans%M + recAns%M) % M;
                }
                dp[in][j] = ans;
            }
        }
        return dp[n][target];
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        return solveUsingTab(n, k, target);
    }
};

// SPACE OPTMISATION
class Solution {
    int M = 1000000007;
    int solveUsingSO(int n, int k, int target){
        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);

        prev[0] =  1;

        for(int in=1; in<=n; in++){
            for(int j=1; j<=target; j++){
                int ans = 0;
                for(int i=1;i<=k;i++){
                    //int recAns = 0;
                    if(j-i >= 0)
                        //recAns = dp[in-1][j-i];
                        ans = (ans % M + prev[j-i] % M) % M;
                        curr[j] = ans;
                }
            }
             prev = curr;
        }
        return prev[target];
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        return solveUsingSO(n, k, target);
    }
};