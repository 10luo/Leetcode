class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        if (tokens.size()==0) return 0;
        sort(tokens.begin(),tokens.end());        
        auto i = tokens.begin(),j = tokens.end()-1;
        int res = 0,temp = 0;
        while (i<=j){
            while (i<=j && P>=*i){
                P-=*i;
                temp++;
                i++;
            }
            res = max(res,temp);
            if (i > j || temp==0) break;
            temp--;
            P += *j;
            j--;        
        }
        
        return res;
    }
};
