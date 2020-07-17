class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int curr = prices[0];
        
        for (int p : prices){
            int diff = p-curr;
            curr = p;
            res += diff>0?diff:0;
        }
        return res;
        
    }
};
