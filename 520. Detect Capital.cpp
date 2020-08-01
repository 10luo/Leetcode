class Solution {
public:
    bool detectCapitalUse(string word) {
        if (all_of(word.begin(),word.end(),[](char ch) { return std::isupper(ch); }) || all_of(++word.begin(),word.end(),[](char ch) { return islower(ch); })){
            return true;
        }
        return false;      
        
        
    }
};
