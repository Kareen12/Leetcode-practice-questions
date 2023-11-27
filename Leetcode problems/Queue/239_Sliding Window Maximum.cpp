class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        
        for(int i=0; i<k; i++){
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
         ans.push_back(nums[dq.front()]);
        
        for(int i=k; i<nums.size(); i++){
            if(!dq.empty() && i-dq.front() >= k){
                 dq.pop_front();
            }
            
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            
            ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};
// USING HEAP
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<k; i++){
            pq.push({nums[i], i});
        }
        ans.push_back(pq.top().first);

        // 1,3,-1,-3,5,3,6,7
        //           ^ this element is now added to the window
        for(int i=k; i<nums.size(); i++){
            pq.push({nums[i], i});
            // piche ke elements jo ab window me consider ni karenge unko ese hatayenge
            while(pq.top().second <= i-k){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};

