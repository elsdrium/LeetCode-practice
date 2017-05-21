class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell_price = prices.empty() ? 0 : prices.back(), profit = 0;
        for ( int i=prices.size()-2; i>=0; --i ) {
            if ( sell_price > prices[i] )
                profit += (sell_price - prices[i]);
            sell_price = prices[i];
        }
        return profit;
    }
};
