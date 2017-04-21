class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> record(prices.size());
        int result = 0;
        if ( prices.size() < 2 ) return 0;
        if ( prices.size() == 2 ) return max(prices[1]-prices[0], 0);
        for ( int i=record.size()-1, price_record=prices.back(), max_profit=0; i>=0; --i ) {
            if ( prices[i] > price_record ) price_record = prices[i];
            if ( price_record - prices[i] > max_profit  ) max_profit = price_record - prices[i];
            record[i] = max_profit;
        }
        for ( int i=0, price_record=prices.front(), max_profit=0; i!=prices.size(); ++i ) {
            if ( prices[i] < price_record ) price_record = prices[i];
            if ( prices[i] - price_record > max_profit ) max_profit = prices[i] - price_record ;
            if ( max_profit + record[i] > result ) result = max_profit + record[i];
        }
        return result;
    }
};
