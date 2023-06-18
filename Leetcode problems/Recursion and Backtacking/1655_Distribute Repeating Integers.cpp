class Solution {
public:
    bool solve( vector<int>& quantity, vector<int> &v, int k ) {
        //Base case
        if(k >= quantity.size()){
            return true;;
        }
        for(int i=0;i<v.size();i++){
            if(v[i] >= quantity[k]){
                v[i] -= quantity[k];
                if(solve(quantity, v, k+1)){
                    return true;
                }
                v[i] += quantity[k];
            }
        }
        return false;
    }
    
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        
        vector<int> v;
        for(auto j: mp){
           v.push_back(j.second);
        }
        sort(quantity.rbegin(), quantity.rend());
        return solve(quantity, v, 0);
    }
};