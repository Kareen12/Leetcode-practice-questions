// VERY BAD SOLUTION 
class Solution {
    int solve(int left, int right){
        if(left >= right){
            return 1;
        }
        int ans = 0;
        for(int i=left; i<=right; i++){
            ans += solve(left, i-1)*solve(i+1, right);
        }
        return ans;
    }
public:
    int numTrees(int n) {
        if(n==0 || n==1){
            return 1;
        }
        return solve(1, n);
    }
};

// MEMOISATION
class Solution {
    int solve(int left, int right, vector<vector<int> > &dp){
        if(left >= right){
            return 1;
        }

        if(dp[left][right] != -1){
            return dp[left][right] ;
        }

        int ans = 0;
        for(int i=left; i<=right; i++){
            ans += solve(left, i-1, dp)*solve(i+1, right, dp);
        }
        dp[left][right] = ans;
        return dp[left][right] ;
    }
public:
    int numTrees(int n) {
        vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
        if(n==0 || n==1){
            return 1;
        }
        return solve(1, n, dp);
    }
};

// TABULATION
int solution2(int n){
        vector<int>dp(n+1,0);
        dp[0]=dp[1]=1;
        //in this approach i is working as n and j is working as i
        for (int i = 2; i <=n; i++)
        {
            int ans=0;
            for (int j = 1; j <=i; j++)
            {
                ans+=dp[j-1]*dp[i-j];
            }
            dp[i]=ans;
        }
        return dp[n];
    }