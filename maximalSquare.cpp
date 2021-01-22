//
// Created by Ankit Batra on 1/20/21.
//

// Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

#include <iostream>
#include <vector>

using std::min;
using std::vector;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();

        vector<vector<int>> dp(r + 1, vector<int>(c + 1));
        int maxSz = 0;
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                    if (dp[i][j] > maxSz) maxSz = dp[i][j];
                }
            }
        }
        return maxSz * maxSz;
    }
};

int main() {
    return 0;
}

