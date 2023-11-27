// SAME AS LONGEST INCREASING SUBSEQUENCE
class Solution {
     void sortVector(vector<vector<int>>& vec) {
        sort(vec.begin(), vec.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sortVector(envelopes);
        int n = envelopes.size();
        vector<int> ans;
        ans.push_back(envelopes[0][1]);

        for(int i=1; i<n; i++){
            if(envelopes[i][1] > ans.back()){
                ans.push_back(envelopes[i][1]);
            }
            else{
                //just bada element dhundenge
                int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
                ans[index] = envelopes[i][1];
            }
        }
        return ans.size();
    }
};