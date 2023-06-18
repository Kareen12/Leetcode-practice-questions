class Solution {
public:

    void calc(vector<int>& price,int i,int& miniPrice, int& maxiProfit){

        if(i==price.size()) return;
        
        if(price[i]<miniPrice) miniPrice = price[i];
        int diff = price[i]-miniPrice;
        if(diff>maxiProfit) maxiProfit = diff;
       
        calc(price,i+1,miniPrice,maxiProfit);
    }
    int maxProfit(vector<int>& prices) {
        //714562
        int miniPrice = INT_MAX;
        int maxiProfit = INT_MIN;
        calc(prices,0,miniPrice,maxiProfit);
        return maxiProfit;
    }
};