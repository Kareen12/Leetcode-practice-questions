class mycomp{
    public:
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        int distA = a.first*a.first + a.second*a.second;
        int distB = b.first*b.first + b.second*b.second;
        return distA > distB;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomp > pq;
        for(auto i: points){
            pq.push({i[0], i[1]});
        }
        while(!pq.empty() && k--){
            auto top = pq.top();
            pq.pop();
            vector<int> temp;
            temp.push_back(top.first);
            temp.push_back(top.second);
            ans.push_back(temp);
        }
        return ans;
    }
};