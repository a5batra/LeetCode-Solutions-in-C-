//
// Created by Ankit Batra on 10/22/20.
//

/* Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes
 * the sum of all numbers along its path.
 * Note: You can only move either down or right at any point in time. */

#include <iostream>
#include <vector>

using std::min;
using std::vector;

class Solution {
public:
    static int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return -1;
        int m = grid[0].size();

        vector<vector<int>> dpTable(n, vector<int>(m));

        dpTable[0][0] = grid[0][0];

        for (int j = 1; j < m; ++j)
            dpTable[0][j] += dpTable[0][j - 1] + grid[0][j];

        for (int i = 1; i < n; ++i)
            dpTable[i][0] += dpTable[i - 1][0] + grid[i][0];

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dpTable[i][j] = grid[i][j] + min(dpTable[i - 1][j], dpTable[i][j - 1]);
            }
        }
        return dpTable[n - 1][m - 1];
    }
};

int main() {
    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};
    std::cout << "Result: " << Solution::minPathSum(grid);

    return 0;
}

