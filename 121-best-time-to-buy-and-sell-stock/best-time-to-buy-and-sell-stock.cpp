class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int maxProfit = 0;
    
        for (int price : prices) {
           maxProfit=max(maxProfit,price-buy);
           buy=min(buy,price);

        }

        return maxProfit;
    }
};