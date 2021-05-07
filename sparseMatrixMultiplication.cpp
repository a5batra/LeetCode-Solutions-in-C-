//
// Created by Ankit Batra on 5/6/21.
//

/* Given two sparse matrices mat1 of size m x k and mat2 of size k x n, return the result of mat1 x mat2.
 * You may assume that multiplication is always possible. */

#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), k = mat1[0].size();
        int n = mat2[0].size();

        vector<vector<int>> ans(m, vector<int>(n));
        vector<vector<int>> idxVal(m, vector<int>());

        for (int i = 0; i < m; ++i) {
            vector<int> numsA;
            for (int j = 0; j < k; ++j) {
                if (mat1[i][j] != 0) {
                    numsA.push_back(j);
                    numsA.push_back(mat1[i][j]);
                }
            }
            idxVal[i] = numsA;
        }

        for (int i = 0; i < m; ++i) {
            vector<int> numsA = idxVal[i];
            if (numsA.size() == 0) continue;
            for (int p = 0; p < numsA.size() - 1; p += 2) {
                int colA = numsA[p];
                int valA = numsA[p + 1];
                for (int j = 0; j < n; ++j) {
                    int valB = mat2[colA][j];
                    ans[i][j] += valA * valB;
                }
            }
        }
        return ans;
    }
};

