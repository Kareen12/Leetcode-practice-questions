class Solution {
public:
    void findingAns(string& num1, string& num2, int n1, int n2, string& ans, int carry=0){
        // Base case
        if(n1 < 0 && n2 < 0){
            if(carry){
                ans.push_back(carry + '0');
            }
            return;
        }
        //converting the last characters of both num1 and num2 to integer to add them
        int nums1 = (n1>=0 ? num1[n1] : '0') - '0';
        int nums2 = (n2>=0 ? num2[n2] : '0') - '0';
        
        int sum = nums1 + nums2 + carry;
        int digit = sum % 10;
        carry = sum/10;
        ans.push_back(digit + '0');
        findingAns(num1, num2, n1-1, n2-1, ans, carry);
    }
    string addStrings(string num1, string num2) {
        string ans ="";
        findingAns(num1, num2, num1.size()-1, num2.size()-1, ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};