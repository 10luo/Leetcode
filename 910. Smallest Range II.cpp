class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        int res = A[A.size()-1] - A[0];
        int n = A.size();
        
        for (int i = 1; i < n; i++){
            int temp = max(A[i - 1] + K, A[n - 1] - K) - min(A[0] + K, A[i] - K);
            res = min(res,temp);
        }
        return res;
    }
};
