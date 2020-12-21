//
// Created by Ankit Batra on 12/20/20.
//

/* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time.
 * The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * How many possible unique paths are there? */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    static int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    int m, n;

    std::cout << "Enter the value of m: " << std::endl;
    std::cin >> m;

    std::cout << "Enter the value of n: " << std::endl;
    std::cin >> n;

    std::cout << "Unique Paths: " << Solution::uniquePaths(m, n);

    return 0;
}