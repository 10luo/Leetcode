bool comp(pair<int,int>a,pair<int,int>b){
    return a.second > b.second;
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        vector<int> res(k);        
        for (int i:nums)count[i]++;
        
        
        vector<pair<int,int>> elems(count.begin(),count.end());
        sort(elems.begin(),elems.end(),comp);
        for (int i = 0; i<k; i++){
            res[i] = elems[i].first;
        }
        return res;       
        
    }
};
