//
// Created by Ankit Batra on 6/13/21.
//

/* Given a matrix and a target, return the number of non-empty submatrices that sum to target.
 * A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.
 * Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is
 * different: for example, if x1 != x1'. */


class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> rowPrefixSum(m, vector<int>(n));
        for (int i = 0; i < m; ++i) rowPrefixSum[i][0] = matrix[i][0];

        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                rowPrefixSum[i][j] = rowPrefixSum[i][j - 1] + matrix[i][j];
            }
        }

        int ans = 0;

        for (int c1 = 0; c1 < n; ++c1) {
            for (int c2 = c1; c2 < n; ++c2) {
                int prefixSum = 0;
                unordered_map<int, int> dict;
                dict[0] = 1;
                for (int row = 0; row < m; ++row) {
                    prefixSum += rowPrefixSum[row][c2] - (c1 > 0 ? rowPrefixSum[row][c1 - 1] : 0);
                    if (dict.count(prefixSum - target)) ans += dict[prefixSum - target];
                    dict[prefixSum]++;
                }
            }
        }

        return ans;
    }
};

