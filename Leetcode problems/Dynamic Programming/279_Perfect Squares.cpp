// MEMOISATION
class Solution {
public:
    int findingAns(int n, vector<int> &dp){
        if(n == 0) return 1;
        if(n < 1) return 0;
        int i = 1;
        int end = sqrt(n);
        int ans = INT_MAX;

        if(dp[n] != -1){
            return dp[n];
        }
        while(i <= end){
            int perfSq = i*i;
            int noOfPerfSq = 1 + findingAns(n-perfSq, dp);
            if(noOfPerfSq < ans){
                ans = noOfPerfSq;
            }
            i++;
        }
        return dp[n] = ans;
    }
    
    int numSquares(int n) {
        vector<int> dp(n+1, -1);;
        return findingAns(n, dp)-1;
    }
};

//TABULATION
class Solution {
public:
    int solveUsingTab(int n){
        vector<int> dp(n+1, INT_MAX);

        dp[0] = 0;
        int i = 1;
        int end = sqrt(n);
        for(int j=1; j<=n; j++){
           for(int i=1; i*i<=n; i++){
                int perfSq = i*i;
                if(j-perfSq >= 0){
                    dp[j] = min(dp[j], 1 + dp[j-perfSq]);
                }
                // i++;
            }
        }
        return dp[n];
    }
    
    int numSquares(int n) {
        // vector<int> dp(n+1, -1);
        return solveUsingTab(n);
    }
};

// SOLUTION 2 USING TABULTION METHOD
class Solution {
public:
    int solveUsingTab(int n){
        vector<int> dp(n+1, INT_MAX);

        dp[0] = 1;
        for(int j=1; j<=n; j++){
            int i = 1;
            int end = sqrt(j);
            int ans = INT_MAX;
            while(i <= end){
                int perfSq = i*i;
                int noOfPerfSq = 1 + dp[j-perfSq];
                if(noOfPerfSq < ans){
                    ans = noOfPerfSq;
                }
                i++;
            }
            dp[j] = ans;
        }
        return dp[n];
    }
    
    int numSquares(int n) {
        return solveUsingTab(n)-1;
    }
};