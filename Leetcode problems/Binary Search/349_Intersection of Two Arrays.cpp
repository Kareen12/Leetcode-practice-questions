class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        vector<int> ans;
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size())
            {
            if(nums1[i] == nums2[j]){
                s.insert(nums1[i]);
                }
            if(i==nums1.size()-1){
                j++;
                i=0;
            }
            else {
                i++;
            }
    }
    for(auto i : s){
        ans.push_back(i);
    }
    return ans;
  }
};