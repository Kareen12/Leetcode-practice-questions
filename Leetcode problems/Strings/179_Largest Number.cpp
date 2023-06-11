class Solution {
public:
    static bool mycomp(string a, string b){
        string t1 = a+b;
        string t2 = b+a;
        //The statement below holds true when a is greater than b and false for otherwise
        return t1>t2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> numsString;
        
        for(int i=0;i<nums.size();i++){
            numsString.push_back(to_string(nums[i]));
        }
        
        sort(numsString.begin(),numsString.end(), mycomp);
        
        if(numsString[0] == "0") return "0";
        
        string ans = "";
        for(int i=0;i<numsString.size();i++){
            ans+=numsString[i];
        }
        return ans;
    }
};