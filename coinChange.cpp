//
// Created by Ankit Batra on 9/1/20.
//

/* You are given coins of different denominations and a total amount of money amount.
 * Write a function to compute the fewest number of coins that you need to make up that amount.
 * If that amount of money cannot be made up by any combination of the coins, return -1. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int m = amount + 1;
        vector<int> dp(m, INT_MAX - 1);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (j >= coins[i])
                    dp[j] = std::min(dp[j], 1 + dp[j - coins[i]]);
            }
        }

        return dp[m - 1] > amount ? - 1 : dp[m - 1];
    }
};

int main() {
    int number;
    string line;
    vector<int> coins;
    int amount;

    std::cout << "Enter the denominations of coins separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        coins.push_back(number);

    std::cout << "Enter the amount: " << std::endl;
    std::cin >> amount;

    std::cout << "Minimum number of coins required to make up this amount: " << Solution::coinChange(coins, amount);

    return 0;
}

