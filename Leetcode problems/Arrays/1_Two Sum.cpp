class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();
            i++){
            if(mp.find(target-nums[i] )!= mp.end()){
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]] = i;
        }
    return ans;
  }
};

// ANOTHER WAY
class Solution {
public:
    static bool mycomp(pair<int,int> &a, pair<int,int> &b){
        return a.first < b.first;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<pair<int,int> > v;

        for(int i=0; i<nums.size(); i++){
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end(), mycomp);

        int s = 0;
        int e = v.size()-1;

        while(s < e){
            if(v[s].first + v[e].first < target){
                s++;
            }
            else if(v[s].first + v[e].first > target){
                e--;
            }
            else{
                ans.push_back(v[s].second);
                ans.push_back(v[e].second);
                break;
            }
        }
        return ans;
    }
};