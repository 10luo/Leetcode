class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int res = 0, m = A.size(), n = A[0].size(), i = 0, j = 0;
        vector<int> sorted(m - 1);
        for (j = 0; j < n; ++j) {
            for (i = 0; i < m - 1; ++i) {
                if (!sorted[i] && A[i][j] > A[i + 1][j]) {
                    ++res;
                    break;
                }
            }
            //if (i < m - 1) continue;
            for (i = 0; i < m - 1; ++i) {
                sorted[i] |= A[i][j] < A[i + 1][j];
            }
        }
        return res;
    }
};
