//
// Created by Ankit Batra on 8/6/20.
//

/* You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    static int climbStairs(int n) {
        if (n == 0 || n == 1) return 1;
        vector<int> dp(n + 1);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i < n + 1; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

int main() {
    int n;

    std::cout << "Enter the value of n: " << std::endl;
    std::cin >> n;

    std::cout << "Distinct ways to climb to the top: " << Solution::climbStairs(n) << std::endl;

    return 0;
}