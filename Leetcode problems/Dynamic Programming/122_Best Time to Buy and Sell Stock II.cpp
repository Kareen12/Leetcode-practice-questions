// TOP DOWN
class Solution {
public:
    int solve(vector<int>& prices, int i, int buy, vector<vector<int>> &dp){
        if(i >= prices.size()){
            return 0;
        }

        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int ans = 0;
        if(buy){
            int buy = -prices[i] + solve(prices, i+1, 0, dp);
            // if we choose tonot buy that day
            int notBuy = solve(prices, i+1, 1, dp);
            ans = max(buy, notBuy);
        }
        else{
            int sell = prices[i] + solve(prices, i+1, 1, dp);
            // if we choose tonot sell that day
            int notSell = solve(prices, i+1, 0, dp);
            ans = max(sell, notSell);
        }
        return dp[i][buy] = ans;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int> > dp(prices.size()+1,vector<int>(2, -1));
        return solve(prices, 0, 1, dp);
    }
};

//TABULATION OR BOTTOM UP
class Solution {
public:
    int solveBU(vector<int>& prices, vector<vector<int>> &dp){
        // dp[prices.size()][] = 0;
        for(int i=prices.size()-1; i>=0; i--){
            for(int buy=0; buy<2; buy++){
                int ans = 0;
                if(buy){
                    int buy = -prices[i] + dp[i+1][0];
                    // if we choose tonot buy that day
                    int notBuy = dp[i+1][1];
                    ans = max(buy, notBuy);
                }
                else{
                    int sell = prices[i] + dp[i+1][1];
                    // if we choose tonot sell that day
                    int notSell =  dp[i+1][0];
                    ans = max(sell, notSell);
                }
                dp[i][buy] = ans;
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int> > dp(prices.size()+1,vector<int>(2, 0));
        return solveBU(prices, dp);
    }
};

// SPACE OPTIMISATION
class Solution {
public:
    int solveUsingSO(vector<int>& prices, vector<vector<int>> &dp){
        for(int i=prices.size()-1; i>=0; i--){
            for(int buy=0; buy<2; buy++){
                int ans = 0;
                if(buy){
                    int buy = -prices[i] + dp[1][0];
                    // if we choose tonot buy that day
                    int notBuy = dp[1][1];
                    ans = max(buy, notBuy);
                }
                else{
                    int sell = prices[i] + dp[1][1];
                    // if we choose tonot sell that day
                    int notSell =  dp[1][0];
                    ans = max(sell, notSell);
                }
                dp[0][buy] = ans;
            }
            dp[1] = dp[0];
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int> > dp(2,vector<int>(2, 0));
        return solveUsingSO(prices, dp);
    }
};