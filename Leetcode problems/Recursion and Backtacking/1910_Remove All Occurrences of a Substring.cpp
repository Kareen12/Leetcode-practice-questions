class Solution {
public:
    void remOccwRe(string& s, string& part){
        int found = s.find(part);
        if(found != string::npos){
            string left_part = s.substr(0,found);
            string right_part = s.substr(found+part.length(), s.length());

            s = left_part + right_part;

            remOccwRe(s,part);
        }
        else{
            return;
        }
    }
    string removeOccurrences(string s, string part) {
       remOccwRe(s,part);
       return s;  
    }
};