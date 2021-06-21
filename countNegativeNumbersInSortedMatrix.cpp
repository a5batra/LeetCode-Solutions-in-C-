//
// Created by Ankit Batra on 6/21/21.
//

/* Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise,
 * return the number of negative numbers in grid. */

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int r = m - 1, c = 0;
        int ans = 0;

        while (r >= 0 && c < n) {
            if (grid[r][c] < 0) {
                r--;
                ans += n - c;
            }
            else c++;
        }

        return ans;
    }
};

