class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> profit(prices.size());
        profit[0] = {(0-prices[0]),0};
        //first elem the max profit w/stock, second elem wo/stock
        for (int i = 1; i<prices.size(); i++){
            int w = profit[i-1][0];
            int wo = profit[i-1][1];
            
            // having stock at day i
            profit[i].push_back(max(profit[i-1][0],profit[i-1][1] - prices[i]));
            // not have stock at day i
            profit[i].push_back(max(profit[i-1][1], profit[i-1][0] + prices[i] - fee));
                        
        }
        
        return max(profit.back()[0] + prices.back() - fee , profit.back()[1]);
        
        
    }
};
