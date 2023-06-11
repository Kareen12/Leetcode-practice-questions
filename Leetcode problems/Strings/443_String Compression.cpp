class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        int prev = chars[0];
        int count = 1;
        int i = 1;
        while(i<chars.size()){
            if(chars[i]==prev){
                count++;
            }
            else{
                chars[index] = prev;
                index++;
                int start = index;
                if(count>1){
                    while(count){
                        chars[index] = (count%10) + '0';
                        count/=10;
                        index++;
                    }
                    reverse(chars.begin()+start, chars.begin()+index);
                }
                count=1;
            }
            prev = chars[i];
            i++;
            
        }
        chars[index] = prev;
        index++;
        int start = index;
        if(count>1){
            while(count){
                chars[index] = (count%10) + '0';
                count/=10;
                index++;
            }
        }
        reverse(chars.begin()+start, chars.begin()+index);        
        return index;
        
    }
};