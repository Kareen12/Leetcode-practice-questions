// SPACE OPTIMISED SOLUTION
class Solution {
public:
    int solveSO(vector<int>& prices, int k, vector<vector<vector<int>>>&dp){
        for(int i=prices.size()-1; i>=0; i--){
            for(int buy=0; buy<2; buy++){
                for(int limit=1; limit<=k; limit++){
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
        return dp[0][1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(2, vector<int>(k+1, 0)));
        return solveSO(prices, k, dp);
    }
};