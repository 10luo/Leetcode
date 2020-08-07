class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> res;
        multiset<int> temp(A.begin(),A.end());
        
        for (int i=0;i<B.size();i++){
            auto pt = (*(--temp.end()) > B[i])? temp.upper_bound(B[i]): temp.begin();
            res.push_back(*pt);
            temp.erase(pt);
            
        }
        return res;
    }
};
