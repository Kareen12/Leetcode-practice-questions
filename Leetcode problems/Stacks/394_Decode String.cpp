class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(auto ch: s){
            //jab tak closing bracket ni aa jaat string ke characters push karte jao(else
            //me jo lika h)
            if(ch == ']'){
                string tobeReapeated = "";
                while(!st.empty() && st.top() != "["){
                    string top = st.top();
                    st.pop();
                    tobeReapeated += top;
                }
                //jese hi opening bracket aya hum bahar nikal gye or humare toBeRepeated me                 sari strings aa gyi that need to be reapated that particular number of times                 below it
                st.pop(); //yaha [ ko pop kia h kyoki isko vese bhi ignore karna h
                //yaha se wo number la rhe h jiyni bar toBerepeated to repeat karna h
                string numericString = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    string top = st.top();
                    numericString += top;
                    st.pop();
                } //esa isliye kiya h kyoki sirf single igit ni hgi double triple bhi ho                        sakti h to stack me jab tak digits h tab tak unhe pop karo fir unhe                          reverse karke int me convert kiya
               reverse(numericString.begin(), numericString.end());

                int n = stoi(numericString);
                
                // ab n ke bad toBeRepeated to repeat karke ek nye string variable me store                 karke stack me push kar diya
                string currString = "";
                while(n--){
                    currString += tobeReapeated;
                }
                st.push(currString);
            }
            else{
                //pushing string in stack 
                string temp(1, ch); //char se string me convert kiya h
                //then push kiya h
                st.push(temp);
            } 
           
        }
        
        //ab jitni bhi currString stack me padhi h unko nikal kar add kar rhe h then reverse
        string ans= "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};