class Solution {
public:
    void revAns(stack<string> &st, string &ans){
        if(st.empty()) return;
            //recursion ka use karenge to s1 to s1 reverse kar pa rhe h ni to character to                 charater ho jata reverse function lagakar
            string top = st.top();
            st.pop();  
            revAns(st, ans); 
            ans += top;
    }
    
    string simplifyPath(string path) {
        stack<string> st;
        int i = 0;
        while(i<path.size()){
            int start = i;
            int end = i+1;
            //jab tak '/' ni aa jata folder ka nam ayega joki hume chahiye(/home) kyoki '/' ane se new folder pe chale jate h ya kuch or hota h
            while(end<path.size() && path[end] != '/'){
                ++end;
            }
            //ab us substring ko nikal liya jisme / with folder name h
            string s1 = path.substr(start, end-start);
            
            //i ko new / ke se continue karawaya
            i = end;
            if(s1 == "/" || s1 == "/."){
                // '/' or '/.'ignore karana h kyoki inse same directory ya folder me rehte h
                continue;
            }
           // agar /.. ni h to push kardo is folder ko, hum kahi piche ni ja rhe wo folder to pakka rahega to use stack me daldo
            if(s1 != "/.."){
                st.push(s1);
            }
             
           // '/..' matlab piche wale folder me jana matlab ab jese /b se /a me jana to /b ko pop kar diya else condition me 
            else if(!st.empty()){
                  st.pop();
            }
         }
        
        string ans = st.empty() ? "/" : "";
        revAns(st,ans);
        return ans;
    }
};