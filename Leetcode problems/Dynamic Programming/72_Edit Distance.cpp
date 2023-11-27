// MEMOISATION
class Solution {
    int solve(string &a, string &b, int i, int j, vector<vector<int> > &dp){
        if(i == a.length()){
            return b.length()-j;
        }
        if(j == b.length()){
            return a.length()-i;
        }

        int ans = 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(a[i] == b[j]){
            ans = solve(a, b, i+1, j+1, dp);
        }
        else{
            int insert = 1 + solve(a, b, i, j+1, dp);
            int deleted = 1 + solve(a, b, i+1, j, dp);
            int replace = 1 + solve(a, b, i+1, j+1, dp);
            ans = min(insert, min(deleted, replace));
        }
        return dp[i][j] = ans;
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int> > dp(word1.length(), vector<int> (word2.length(), -1));
        int i = 0;
        int j = 0;
        return solve(word1, word2, i, j, dp);
    }
};

// TABULATION
class Solution {
    int solveUsingTab(string &a, string &b){
        vector<vector<int> > dp(a.length()+1, vector<int> (b.length()+1, 0));

        for(int j=0; j<=b.length(); j++){
            dp[a.length()][j] = b.length()-j;
        }
        for(int i=0; i<=a.length(); i++){
            dp[i][b.length()] = a.length()-i;
        }

        for(int i=a.length()-1; i>=0; i--){
            for(int j=b.length()-1; j>=0; j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = dp[i+1][j+1];
                }
                else{
                    int insert = 1 + dp[i][j+1];
                    int deleted = 1 + dp[i+1][j];
                    int replace = 1 + dp[i+1][j+1];
                    ans = min(insert, min(deleted, replace));
                }
                dp[i][j] = ans; 
            }
        }
        return dp[0][0];
    }
public:
    int minDistance(string word1, string word2) {
        return solveUsingTab(word1, word2);
    }
};

// SPACE OPTIMISATION
class Solution {
    int solveUsingSO(string &a, string &b){
        vector<int> curr(b.length()+1, 0);
        vector<int> next(b.length()+1, 0);

        for(int j=0; j<=b.length(); j++){
            next[j] = b.length()-j;
        }
        // for(int i=0; i<=a.length(); i++){
        //     dp[i][b.length()] = a.length()-i;
        // }


        for(int i=a.length()-1; i>=0; i--){
            curr[b.length()] = a.length()-i;
            for(int j=b.length()-1; j>=0; j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = next[j+1];
                }
                else{
                    int insert = 1 + curr[j+1];
                    int deleted = 1 + next[j];
                    int replace = 1 + next[j+1];
                    ans = min(insert, min(deleted, replace));
                }
                curr[j] = ans; 
            }
            next = curr;
        }
        return next[0];
    }
public:
    int minDistance(string word1, string word2) {
        return solveUsingSO(word1, word2);
    }
};