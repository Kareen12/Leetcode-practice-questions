class Solution {
public:
    int findingAns(vector<int>& days, vector<int>& costs, int i, vector<int> &dp, int n){
        // Base case
        if(i >= n) return 0;

        if(dp[i] != -1){
            return dp[i];
        }
        
        // 1 day ticket
        int cost1 = costs[0] + findingAns(days, costs, i+1, dp, n);
        
        // 7 day cost
        /* why -1? 1 2 3 4 5 6 7 8 ... 20 
        1 + 7 - 1 = 7(7 din tak hi to valid rahega pass) */
        int day1 = days[i] + 7 - 1; // day1 is the day at which pass will expire when buying 7 day pass
        int j = i;
        while(j<days.size() && days[j]<=day1){
            j++;
        }
        int cost7 = costs[1] + findingAns(days, costs, j, dp, n);
        
        // 30 day cost
        int day2 = days[i] + 30 - 1; // day2 is the day at which pass will expire when buying 30 day pass
        j = i;
        while(j<days.size() && days[j]<=day2){
            j++;
        }
        int cost30 = costs[2] + findingAns(days, costs, j, dp, n);
        
        return dp[i] = min(cost1, min(cost7,cost30));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        return findingAns(days, costs, 0, dp, n);
    }
};

// TABULATION OR BOTTOM UP APPROACH
class Solution {
public:
    int solveUsingTab(vector<int>& days, vector<int>& costs, int n){
        vector<int> dp(n+1, INT_MAX);

        dp[n] = 0;
        for(int x=n-1; x>=0; x--){
            // 1 day ticket
            int cost1 = costs[0] + dp[x+1];
            
            // 7 day cost
            /* why -1? 1 2 3 4 5 6 7 8 ... 20 
            1 + 7 - 1 = 7(7 din tak hi to valid rahega pass) */
            int day1 = days[x] + 7 - 1;
            int j = x;
            while(j<n && days[j]<=day1){
                j++;
            }
            int cost7 = costs[1] + dp[j];
            
            // 30 day cost
            int day2 = days[x] + 30 - 1;
            j = x;
            while(j<n && days[j]<=day2){
                j++;
            }
            int cost30 = costs[2] + dp[j];
            
            dp[x] = min(cost1, min(cost7,cost30));
        }
        return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        return solveUsingTab(days, costs, n);
    }
};