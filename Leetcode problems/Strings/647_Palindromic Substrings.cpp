class Solution {
public:
    int countingSubstrings(string s, int i, int j){
        int count1 = 0;
        while(i>=0 && j<s.length() && s[i]==s[j]){
            count1++;
            i--;
            j++;
        }
        return count1;
    }
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        for(int i=0;i<n;i++){
            
            // Counting odd substrings
            int oddCount = countingSubstrings(s,i,i);
            count = count + oddCount;
            
            // Counting even substrings
            int evenCount = countingSubstrings(s,i,i+1);
            count = count + evenCount;
        }
        return count;
    }
           
            
};
