//
// Created by Ankit Batra on 8/21/20.
//

/* Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land)
 * connected 4-directionally (horizontal or vertical.)
 * You may assume all four edges of the grid are surrounded by water.
 * Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.) */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
    int area = 0;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        int maxArea = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    dfs(grid, row, col);
                    if (area > maxArea) {
                        maxArea = area;
                    }
                }
                area = 0;
            }
        }

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 2)
                    grid[row][col] = 1;
            }
        }
        return maxArea;
    }

    void dfs(vector<vector<int>>& grid, int row, int col) {
        int rows = grid.size();
        int cols = grid[0].size();
        area += 1;

        grid[row][col] = 2;

        if (col < cols - 1 && grid[row][col + 1] == 1)
            dfs(grid, row, col + 1);
        if (row < rows - 1 && grid[row + 1][col] == 1)
            dfs(grid, row + 1, col);
        if (col > 0 && grid[row][col - 1] == 1)
            dfs(grid, row, col - 1);
        if (row > 0 && grid[row - 1][col] == 1)
            dfs(grid, row - 1, col);

    }
};


int main() {
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    Solution obj;

    std::cout << "Maximum area of island: " << obj.maxAreaOfIsland(grid);

    return 0;
}

