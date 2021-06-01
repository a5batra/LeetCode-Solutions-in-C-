//
// Created by Ankit Batra on 5/31/21.
//

/* Given a matrix of integers grid with m rows and n columns, find the maximum score of a path starting at [0,0]
 * and ending at [m-1,n-1].
 * The score of a path is the minimum value in that path.  For example, the value of the path 8 →  4 →  5 →  9 is 4.
 * A path moves some number of times from one visited cell to any neighbouring unvisited cell in one of the 4
 * cardinal directions (north, east, west, south). */

class Solution {
    vector<vector<int>> dirs;
public:
    Solution() {
        dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    }
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();

        priority_queue<tuple<int, int, int>> pq;
        pq.emplace(grid[0][0], 0, 0);
        grid[0][0] = -1;
        int maxScore = INT_MAX;
        while (!pq.empty()) {
            auto [val, r, c] = pq.top();
            pq.pop();
            maxScore = min(maxScore, val);
            if (r == m - 1 && c == n - 1) return maxScore;
            for (vector<int>& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] == -1)
                    continue;
                pq.emplace(min(maxScore, grid[nr][nc]), nr, nc);
                grid[nr][nc] = -1;
            }
        }

        return -1;

    }
};

