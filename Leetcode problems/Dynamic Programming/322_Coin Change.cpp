// RECURSION + MEMOISATION
class Solution {
    int solve(vector<int>& coins, int amount,  vector<int> &dp){
        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }
        if(dp[amount] != -1){
            return dp[amount];
        }
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int ans = solve(coins, amount - coins[i], dp);
            if(ans != INT_MAX){
                mini = min(mini, ans+1);
            }
        }
        dp[amount] = mini;
        return mini;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
       vector<int> dp(amount+1, -1);
       int ans = solve(coins, amount, dp); 
       if(ans == INT_MAX) return -1;
       else
          return ans;
    }
};

// TABULATION METHOD
class Solution {
    int solveUsingTabulation(vector<int>& coins, int amount){
        vector<int> dp(amount+1, INT_MAX);

        dp[0] = 0;

        for(int i=1; i<=amount; i++){
            int mini =  INT_MAX;
            for(int j=0; j<coins.size(); j++){
                if(i-coins[j] >= 0){
                    int ans = dp[i - coins[j]];
                    if(ans != INT_MAX){
                        mini = min(mini, ans+1);
                    }
                }
                dp[i] = mini;
            }
        }
        return dp[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
       int ans = solveUsingTabulation(coins, amount); 
       if(ans == INT_MAX) return -1;
       else
          return ans;
    }
};