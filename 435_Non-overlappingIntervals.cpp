class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(),intervals.end());
        
        int end = intervals[0][1];
        int res = -1;
        
        for (vector<int> p : intervals){
            if (end > p[0]) {
                res++;
                end = (p[1]<end)?p[1]:end;
            }
            else end = (p[1] > end)? p[1]:end;
        }
        
        return res;
            
    }
};
