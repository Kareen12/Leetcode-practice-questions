//METHOD 1 
class Solution {
public:
    string removeDuplicates(string s)     {
        string ans="";
        int i=0;
        while(i<s.length()){
            if(ans.length()>0 && ans[ans.length()-1]==s[i]){
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
            i++;
        }
        return ans;
    }
};

//METHOD 2
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pos = s.find(part);
        while(pos != string::npos){
            s.erase(pos, part.length());
            pos = s.find(part);
        }
        return s;
    }
};