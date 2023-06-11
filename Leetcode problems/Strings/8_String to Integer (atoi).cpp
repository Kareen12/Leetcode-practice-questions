class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        //Handling spaces
        while(s[i]==' '){
                i++;
        }
        
        
        //Checking sign
        int sign = 1;
        if(i<s.size() && (s[i]=='-' || s[i]=='+')){
            sign = s[i]== '+' ? 1 : -1;
            i++;
        }
        
        int num = 0;
        while(i<s.size() && isdigit(s[i])){
            //making sure that number does not exceed the max value of int and is less than                the min value of int
            if(num > INT_MAX/10 || ( num==INT_MAX/10 && s[i]>'7') ){
                return sign==-1 ? INT_MIN :  INT_MAX;
            }
            num = num*10 + (s[i]-'0');
            i++;
        }
        
        return num*sign;
    }
};