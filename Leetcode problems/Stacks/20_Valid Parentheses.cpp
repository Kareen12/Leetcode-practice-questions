class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 1) return false;
        
        stack<char> st;
        
        for(int i = 0; i<s.length(); i++){
            //opening bracket
            if(s[i] == '(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else{
                //closing bracket
                if(!st.empty()){
                    char topch = st.top();
                    if(s[i]==')' &&  topch=='('){
                        st.pop();
                    }
                    else if(s[i]=='}' &&  topch=='{'){
                        st.pop();
                    }
                    else if(s[i]==']' &&  topch=='['){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        
        }
        else{
            return false;
        }
    }
};