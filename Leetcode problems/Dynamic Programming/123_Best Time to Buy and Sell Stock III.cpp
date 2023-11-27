// MEMOISATION
class Solution {
public:
    int solve(vector<int>& prices, int i, int buy, int limit, vector<vector<vector<int>>>&dp){
        if(i >= prices.size() || limit == 0){
            return 0;
        }

        if(dp[i][buy][limit] != -1){
            return dp[i][buy][limit];
        }

        int ans = 0;
        if(buy){
            int buy = -prices[i] + solve(prices, i+1, 0, limit, dp);
            // if we choose to not buy that day
            int notBuy = solve(prices, i+1, 1, limit, dp);
            ans = max(buy, notBuy);
        }
        else{
            int sell = prices[i] + solve(prices, i+1, 1, limit-1, dp);
            // if we choose to not sell that day
            int notSell = solve(prices, i+1, 0, limit, dp);
            ans = max(sell, notSell);
        }
        return dp[i][buy][limit] = ans;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(prices, 0, 1, 2, dp);
    }
};

//TABULATION
class Solution {
public:
    int solveTab(vector<int>& prices, vector<vector<vector<int>>>&dp){
        for(int i=prices.size()-1; i>=0; i--){
            for(int buy=0; buy<2; buy++){
                for(int limit=1; limit<=2; limit++){
                    int ans = 0;
                    if(buy){
                        int buy = -prices[i] + dp[i+1][0][limit];
                        // if we choose tonot buy that day
                        int notBuy = dp[i+1][1][limit];
                        ans = max(buy, notBuy);
                    }
                    else{
                        int sell = prices[i] + dp[i+1][1][limit-1];
                        // if we choose tonot sell that day
                        int notSell = dp[i+1][0][limit];
                        ans = max(sell, notSell);
                    }
                    dp[i][buy][limit] = ans;
                }
                
            }
        }
        return dp[0][1][2];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2, vector<int>(3, 0)));
        return solveTab(prices, dp);
    }
};

// SPACE OPTIMISATION
class Solution {
public:
    int solveSO(vector<int>& prices, vector<vector<vector<int>>>&dp){
        for(int i=prices.size()-1; i>=0; i--){
            for(int buy=0; buy<2; buy++){
                for(int limit=1; limit<=2; limit++){
                    int ans = 0;
                    if(buy){
                        int buy = -prices[i] + dp[1][0][limit];
                        // if we choose tonot buy that day
                        int notBuy = dp[1][1][limit];
                        ans = max(buy, notBuy);
                    }
                    else{
                        int sell = prices[i] + dp[1][1][limit-1];
                        // if we choose tonot sell that day
                        int notSell = dp[1][0][limit];
                        ans = max(sell, notSell);
                    }
                    dp[0][buy][limit] = ans;
                }
                
            }
            dp[1] = dp[0];
        }
        return dp[0][1][2];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(2, vector<int>(3, 0)));
        return solveSO(prices, dp);
    }
};