class Solution {
public:
    string intToRoman(int num) {
        string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX","V", "IV", "I"};
        int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        
        string ans;
        int i = 0;
        while(i<13){
            while(num>=values[i]){
                ans += symbols[i];
                num -= values[i];
            }
            i++;;
        }
        return ans;
    }
};