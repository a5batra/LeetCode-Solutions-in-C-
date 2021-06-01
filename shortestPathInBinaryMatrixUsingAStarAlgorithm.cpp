//
// Created by Ankit Batra on 5/31/21.
//

/* In an N by N square grid, each cell is either empty (0) or blocked (1).
 * A clear path from top-left to bottom-right has length k if and only if it is composed of cells
 * C_1, C_2, ..., C_k such that:
 * Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
 * C_1 is at location (0, 0) (ie. has value grid[0][0])
 * C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
 * If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
 * Return the length of the shortest such clear path from top-left to bottom-right.
 * If such a path does not exist, return -1. */

struct Candidate {
    int row;
    int col;
    int distanceSoFar;
    int totalEstimate;
    Candidate(int r, int c, int d, int t) : row(r), col(c), distanceSoFar(d), totalEstimate(t) {};
};
class myCompare {
public:
    bool operator()(Candidate& c1, Candidate& c2) {
        return c1.totalEstimate > c2.totalEstimate;
    }
};
class Solution {
    vector<vector<int>> dirs;
    int shortestPath;
public:
    Solution() {
        dirs = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
        shortestPath = 0;
    }
    int estimate(vector<vector<int>>& grid, int row, int col) {
        int remainingRows = grid.size() - row - 1;
        int remainingCols = grid[0].size() - col - 1;
        return max(remainingRows, remainingCols);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        vector<vector<bool>> visited(n, vector<bool>(n));
        priority_queue<Candidate, vector<Candidate>, myCompare> pq;
        pq.push(Candidate(0, 0, 1, estimate(grid, 0, 0)));

        while (!pq.empty()) {
            Candidate best = pq.top();
            pq.pop();
            if (best.row == n - 1 && best.col == n - 1) return best.distanceSoFar;
            if (visited[best.row][best.col]) continue;
            visited[best.row][best.col] = true;

            for (vector<int>& dir : dirs) {
                int nr = best.row + dir[0];
                int nc = best.col + dir[1];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n || grid[nr][nc] == 1) continue;
                int newDistance = best.distanceSoFar + 1;
                int totalEstimate = newDistance + estimate(grid, nr, nc);
                pq.push(Candidate(nr, nc, newDistance, totalEstimate));
            }
        }
        return -1;
    }
};

