
class Solution {
public:
#define ll long long 
    long long minimumDifference(vector<int>& nums) {
        ll n = nums.size()/3;
        priority_queue<ll> maxHeap;
        priority_queue<ll, vector<ll>, greater<ll>> minHeap;
        vector<ll> prefix(nums.size(), -1);
        vector<ll> suffix(nums.size(), -1);

        ll sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            maxHeap.push(nums[i]);

            if(maxHeap.size() > n){
                auto top = maxHeap.top();
                maxHeap.pop();
                sum -= top;
            }
            if(maxHeap.size()==n){
                prefix[i] = sum;
            }
        }

        sum = 0;
        for(int i=nums.size()-1; i>=0; --i){
            sum += nums[i];
            minHeap.push(nums[i]);

            if(minHeap.size() > n){
                auto top = minHeap.top();
                minHeap.pop();
                sum -= top;
            }
            if(minHeap.size()==n){
                suffix[i] = sum;
            }
        }

        ll ans = LONG_LONG_MAX;
        for(int i=n-1; i<2*n; ++i){
            ans = min(ans, prefix[i] - suffix[i+1]);
        }
        return ans;
    }
};