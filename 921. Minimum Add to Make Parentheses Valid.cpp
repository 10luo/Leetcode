class Solution {
public:
    int minAddToMakeValid(string S) {
        vector<char> temp;
        int res = 0;       
        for (auto s:S){
            if (s == '(') temp.push_back('(');
            else {
                if (temp.size() == 0) res+=1;
                else temp.pop_back();
            }
        }
        res += temp.size();
        return res;
    }
};
