class Solution {
public:
    bool rotateString(string s, string goal) {
        string strAdd=s+s;
        if(s.length()!=goal.length()){
            return false;
        }
        if(strAdd.find(goal)==-1){
            return false;
        }
        else{
            return true;
        }
    }
};