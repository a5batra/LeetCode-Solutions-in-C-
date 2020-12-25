//
// Created by Ankit Batra on 12/24/20.
//

/* Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land)
 * connected 4-directionally (horizontal or vertical.)
 * You may assume all four edges of the grid are surrounded by water.
 * Count the number of distinct islands. An island is considered to be the same as another
 * if and only if one island can be translated (and not rotated or reflected) to equal the other. */

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_set;
using std::vector;

class Solution {
    unordered_set<string> recursivePath;
    string path = "";
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int distinctIslands = 0;
        int rows = grid.size();
        if (rows == 0) return distinctIslands;
        int cols = grid[0].size();

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    dfs(grid, row, col, "");
                    recursivePath.insert(path);
                    path = "";
                }
            }
        }

        distinctIslands = recursivePath.size();

        return distinctIslands;
    }
    void dfs(vector<vector<int>>& grid, int row, int col, string dir) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return;

        if (grid[row][col] != 1) return;

        path += dir;
        grid[row][col] = -1;

        dfs(grid, row, col + 1, "r");
        dfs(grid, row + 1, col,  "d");
        dfs(grid, row, col - 1,  "l");
        dfs(grid, row - 1, col, "u");

        path += "x";
    }
};

int main() {
    vector<vector<int>> grid = {{0,0,1,0,1,0,1,1,1,0,0,0,0,1,0,0,1,0,0,1,1,1,0,1,1,1,0,0,0,1,1,0,1,1,0,1,0,1,0,1,0,0,0,0,0,1,1,1,1,0},
                           {0,0,1,0,0,1,1,1,0,0,1,0,1,0,0,1,1,0,0,1,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,1,1,0,1,0,0,0},
                           {0,1,0,1,0,1,1,1,0,0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,0,0,1,0,1,0,1,0,0,0,1,1,1,1,1,0,0,1,0,0,1,0},
                           {1,0,1,0,0,1,0,1,0,0,1,0,0,1,1,1,0,1,0,0,0,0,1,0,1,0,0,1,0,1,1,1,0,1,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1}};
    Solution obj;

    std::cout << "Number of distinct islands: " << obj.numDistinctIslands(grid);

    return 0;
}