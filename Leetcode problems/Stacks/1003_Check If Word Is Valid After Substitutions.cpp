class Solution {
public:
    //TIME COMPLEXITY: O(n) * O(n/3) => o(n^2)
    bool isValid(string s) {
        int found = s.find("abc");
        
        if(s.size() == 0){
            return true;
        }
        if(found != string::npos){
            //abc found
            
            string left = s.substr(0, found);
            string right = s.substr(found+3, s.size());
            
            //recursive call
            return isValid(left+right);
        }
        
        return false;
    }
};

//BETTER APPROACH
class Solution {
public:
    bool isValid(string s) {
        if(s[0] != 'a') return false;
        stack<char> st;
        
        for(auto ch: s){
            if(!st.empty() && ch == 'b' && st.top() == 'a'){
                st.push(ch);
            }
            else if(ch == 'a'){
                st.push(ch);
            }
            else{
                if(!st.empty() && st.top() == 'b'){
                    st.pop();
                    if(!st.empty() && st.top() == 'a')
                        st.pop();
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        else{
            return true;
        }
        
    }
};