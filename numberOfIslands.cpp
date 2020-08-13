//
// Created by Ankit Batra on 8/11/20.
//

/* Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
 * You may assume all four edges of the grid are all surrounded by water. */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    static int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        int num = 0;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == '1') {
                    dfs(grid, row, col);
                    num += 1;
                }
            }
        }

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 'V')
                    grid[row][col] = '1';
            }
        }

        return num;
    }

    static int dfs(vector<vector<char>>& grid, int row, int col) {
        int rows = grid.size();
        int cols = grid[0].size();

        grid[row][col] = 'V';

        if (col < cols - 1 && grid[row][col + 1] == '1')
            dfs(grid, row, col + 1);
        if (row < rows - 1 && grid[row + 1][col] == '1')
            dfs(grid, row + 1, col);
        if (col > 0 && grid[row][col - 1] == '1')
            dfs(grid, row, col - 1);
        if (row > 0 && grid[row - 1][col] == '1')
            dfs(grid, row - 1, col);
    }
};

int main() {
    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '1', '0', '0'},
                                 {'0', '0', '0', '1', '1'}};

    std::cout << "Number of islands: " << Solution::numIslands(grid) << std::endl;

    return 0;
}
