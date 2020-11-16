//
// Created by Ankit Batra on 11/12/20.
//

/* Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n. */

#include <iostream>
#include <vector>

using std::min;
using std::vector;

class Solution {
public:
    static int numSquares(int n) {
        if (n == 0) return 0;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }

        return dp[n];
    }
};

int main() {
    int ans = 0;
    int n;

    std::cout << "Enter the positive integer n: " << std::endl;
    std::cin >> n;

    std::cout << "Least number of perfect square numbers to form n: " << Solution::numSquares(n);

    return 0;
}

