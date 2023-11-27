// SOLUTION TYPE 1: RECURSION + MEMOISATION
class Solution {
    int solve(int n, vector<int> &dp){
        if(n == 1 || n == 0){
            return n;
        }

        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = solve(n-1, dp) + solve(n-2, dp);
        return dp[n];
    }
public:
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};

// SOLUTION TYPE 2: BOTTOM UP OR ITERATIVE 
class Solution {
    int bottomUpSolve(int n){
        vector<int> dp(n+1, -1);

        dp[0] = 0;
        if(n == 0) return dp[0];
        dp[1] = 1;

        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
public:
    int fib(int n) {
        return bottomUpSolve(n);
    }
};

// SOLUTION TYPE 3: SPACE OPTIMISED
class Solution {
    // }
    int spaceOptSol(int n){
        int prev2 = 0;
        int prev1 = 1;

        if(n == 0) return prev2;
        if(n == 1) return prev1;

        int curr;
        for(int i=2; i<=n; i++){
            curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
public:
    int fib(int n) {
        // vector<int> dp(n+1, -1);
        return spaceOptSol(n);
    }
};