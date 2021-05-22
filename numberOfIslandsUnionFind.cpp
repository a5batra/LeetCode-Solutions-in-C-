//
// Created by ankitb on 5/21/21.
//

/* Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
 * You may assume all four edges of the grid are all surrounded by water. */

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int numIslands = 0;
        if (m == 0) return numIslands;
        int n = grid[0].size();

        vector<int> parent(m * n, -1);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    parent[i*n+j] = i*n+j;
                    if (j > 0 && grid[i][j - 1] == '1') unionOp(parent, i*n+j, i*n+(j-1));
                    if (i > 0 && grid[i - 1][j] == '1') unionOp(parent, i*n+j, (i-1)*n+j);
                }
            }
        }

        unordered_set<int> st;
        for (int k = 0; k < parent.size(); ++k) {
            if (parent[k] != -1) st.insert(find(parent, k));
        }
        return st.size();
    }
    int find(vector<int>& parent, int u) {
        if (parent[u] == u) return u;
        return find(parent, parent[u]);
    }
    void unionOp(vector<int>& parent, int u, int v) {
        int parentU = find(parent, u);
        int parentV = find(parent, v);
        parent[parentU] = parentV;
    }
};