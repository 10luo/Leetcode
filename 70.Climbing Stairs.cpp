class Solution {
public:
    int climbStairs(int n) {
        if (n==0){
            return 0;
        }
        int res1 = 0,res2 = 1, res3 = 1;
        for (int i=0;i<n;i++){
            res3 = res1 + res2;
            res1 = res2;
            res2 = res3;
        }
        return res2;
    }
};
