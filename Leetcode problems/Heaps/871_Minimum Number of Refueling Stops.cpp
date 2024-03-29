class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<pair<int, int>>pq;
        int ans = 0;
        int dist = 0;
        int i = 0;
        int fuel = startFuel;

        while(true){
            while(i < stations.size()){
                if(stations[i][0] <= dist + fuel){
                    pq.push({stations[i][1], stations[i][0]});
                }
                else{
                    break;
                }
                i++;
            }

            dist += fuel;
            fuel = 0;

            if(dist >= target){
                break;
            }

            if(pq.empty()){
                ans = -1;
                break;
            }

            auto top = pq.top();
            fuel = (dist -top.second) + top.first;
            dist = top.second;
            pq.pop();
            ans++;
        }
        return ans;
    }
};