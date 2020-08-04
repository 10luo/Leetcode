class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) return false;
        int temp = num&-num;// The first 1 in binary number num
        
        if (num != temp){return false;}// Check if it's power of 2
        else if ((num & 0x55555555) ==0) {return false;}// Check if it's power of 4
        else return true;
        
        
    }
};
