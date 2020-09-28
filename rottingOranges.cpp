//
// Created by Ankit Batra on 9/27/20.
//

/* In a given grid, each cell can have one of three values:
 * the value 0 representing an empty cell;
 * the value 1 representing a fresh orange;
 * the value 2 representing a rotten orange.
 * Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.
 * Return the minimum number of minutes that must elapse until no cell has a fresh orange.
 * If this is impossible, return -1 instead. */

#include <iostream>
#include <queue>
#include <vector>

using std::make_pair;
using std::pair;
using std::queue;
using std::vector;

class Solution {
    int minutes = 0;
public:
    void bfs(vector<vector<int>>& grid, vector<pair<int, int>>& rottenCells) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < rottenCells.size(); ++i) {
            int row = rottenCells[i].first, col = rottenCells[i].second;
            q.push(make_pair(row, col));
        }

        int flag = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                pair<int, int> rc = q.front();
                q.pop();
                int r = rc.first, c = rc.second;
                if (grid[r][c] == 2) grid[r][c] = -2;

                if (c < cols - 1 && grid[r][c + 1] == 1) {
                    grid[r][c + 1] = 2;
                    flag = 1;
                    q.push(make_pair(r, c + 1));
                }
                if (r < rows - 1 && grid[r + 1][c] == 1) {
                    grid[r + 1][c] = 2;
                    flag = 1;
                    q.push(make_pair(r + 1, c));
                }
                if (c > 0 && grid[r][c - 1] == 1) {
                    grid[r][c - 1] = 2;
                    flag = 1;
                    q.push(make_pair(r, c- 1));
                }
                if (r > 0 && grid[r - 1][c] == 1) {
                    grid[r - 1][c] = 2;
                    flag = 1;
                    q.push(make_pair(r - 1, c));
                }
            }
            if (flag == 1) {
                minutes += 1;
                flag = 0;
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return minutes;
        int m = grid[0].size();

        vector<pair<int, int>> rottenCells;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2)
                    rottenCells.push_back(make_pair(i, j));
            }
        }

        bfs(grid, rottenCells);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) minutes = -1;
            }
        }
        return minutes;
    }
};

int main() {
    vector<vector<int>> grid = {{1,2,1,1,2,1,1}};

    Solution obj;

    std::cout << "Minimum number of minutes: " << obj.orangesRotting(grid);

    return 0;
}

