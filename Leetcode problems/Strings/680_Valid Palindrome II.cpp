class Solution {
public:
     bool checkPal(string s, int x, int y){
        while (x<y){
            if(s[x] != s[y]){
                return false;
            }
            else{
                x++;
                y--;
            }
       }
       return true;
}
    
    bool validPalindrome(string s) {
        int i = 0;
        int j= s.length()-1;
        
        while(i<j){
            if(s[i] != s[j]){
                return checkPal(s,i,j-1) || checkPal(s,i+1,j);
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};