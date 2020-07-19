class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(),points.end());
        //int start = points[0][0];
        int end = points[0][1];
        int res = 1;
        
        for (vector<int> p : points){
            if (end < p[0]) {
                res++;
                end = p[1];
            }
            else end = (p[1] < end)? p[1]:end;
        }
        
        return res;
            
    }
};
