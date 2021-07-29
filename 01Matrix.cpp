//
// Created by Ankit Batra on 7/29/21.
//

/* Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
 * The distance between two adjacent cells is 1. */

class Solution {
    vector<vector<int>> directions;
public:
    Solution() {
        directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int r = p.first, c = p.second;
            for (vector<int>& dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || mat[nr][nc] == 0 || ans[nr][nc] != INT_MAX) continue;
                ans[nr][nc] = ans[r][c] + 1;
                q.push({nr, nc});
            }

        }

        return ans;

    }
};

