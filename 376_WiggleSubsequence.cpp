class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        int res = 0;
        int curr = nums[0];
        int inc = 2;
        
        for (int num:nums){
            if (num > curr) {
                if (inc == 2 || !inc){
                    res++;
                    inc = 1;
                }
            }
            else if (num < curr) {
                if (inc){
                    res++;
                    inc = 0;
                }
            }
            curr = num;            
        }
        
        
        return res+1;
    }
};
