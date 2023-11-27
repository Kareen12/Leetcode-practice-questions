class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());

        while(k--){
            int top = pq.top();
            pq.pop();
            int x = top - floor(top/2);
            pq.push(x);
        }
        int sum = 0;
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            sum += top;
        }
        return sum;
    
    }
};