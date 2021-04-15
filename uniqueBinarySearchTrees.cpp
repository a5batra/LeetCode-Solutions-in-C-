//
// Created by Ankit Batra on 4/14/21.
//

// Given an integer n, return the number of structurally unique BST's (binary search trees)
// which has exactly n nodes of unique values from 1 to n.

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int dfs(int n, vector<int>& dp) {
        if (n == 0 || n == 1) return 1;

        if (dp[n] != -1) return dp[n];

        int num = 0;
        for (int i = 1; i <= n; ++i) {
            num += dfs(i - 1, dp) * dfs(n - i, dp);
        }
        return dp[n] = num;
    }

    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        return dfs(n, dp);
    }
};

int main() {
    return 0;
}
