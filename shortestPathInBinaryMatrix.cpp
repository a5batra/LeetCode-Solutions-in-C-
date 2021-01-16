//
// Created by Ankit Batra on 1/15/21.
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

#include <iostream>
#include <queue>
#include <vector>

using std::pair;
using std::queue;
using std::vector;

class Solution {
public:
    static int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r = grid.size();
        if (r == 0) return -1;
        int c = grid[0].size();
        if (grid[0][0] == 1 || grid[r - 1][c - 1] == 1) return -1;

        queue<pair<int, int>> q;
        q.push({0,0});
        grid[0][0] = -1;

        vector<vector<int>> dirs = {{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};

        int currLevel = 0;
        while (!q.empty()) {
            int sz = q.size();
            currLevel++;
            while (sz--) {
                pair<int, int> p = q.front();
                q.pop();
                int currRow = p.first, currCol = p.second;
                if (currRow == r - 1 && currCol == c - 1) return currLevel;
                for (vector<int> dir : dirs) {
                    int x = dir[0], y = dir[1];
                    int nextRow = currRow + x, nextCol = currCol + y;
                    if (nextRow < 0 || nextRow >= r || nextCol < 0 || nextCol >= c || grid[nextRow][nextCol] != 0)
                        continue;
                    q.push({nextRow, nextCol});
                    grid[nextRow][nextCol] = -1;
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};

    std::cout << "Shortest Path: " << Solution::shortestPathBinaryMatrix(grid);

    return 0;
}
