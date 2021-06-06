//
// Created by Ankit Batra on 6/6/21.
//

/* Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by
 * rotating mat in 90-degree increments, or false otherwise. */

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int count = 4;
        int n = mat.size();

        while (count--) {
            vector<vector<int>> ans(n, vector<int>(n));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    ans[i][j] = mat[j][n - 1 - i];
                }
            }
            mat = ans;
            if (ans == target) return true;
        }

        return false;
    }
};

