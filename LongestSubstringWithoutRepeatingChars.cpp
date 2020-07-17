class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> init;
        for (char i = 'a'; i <='z'; i++){
            init[i] = 0;
        }
        
        int left = 0;
        int result = 0;
        for (int right = 0; right < s.size(); right++){
            init[s[right]]++;
            while (init[s[right]] > 1){
                init[s[left]] -= 1;
                left++;
            }   
            
            result = result>(right-left+1)? result:(right-left+1);          
        }
        return result;
        
    }
};
