//
// Created by Ankit Batra on 6/7/20.
//

/* You are given coins of different denominations and a total amount of money. Write a function to compute the number
 * of combinations that make up that amount. You may assume that you have infinite number of each kind of coin. */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dpTable(n + 1, vector<int>(amount + 1));

        for (int row = 0; row < n + 1; ++row)
            dpTable[row][0] = 1;

        for (int col = 1; col < amount  + 1; ++col)
            dpTable[0][col] = 0;

        for (int row = 1; row < n + 1; ++row) {
            for (int col = 1; col < amount + 1; ++col) {
                if (col >= coins[row - 1])
                    dpTable[row][col] = dpTable[row - 1][col] + dpTable[row][col - coins[row - 1]];
                else
                    dpTable[row][col] = dpTable[row - 1][col];
            }
        }
        return dpTable[n][amount];
    }
};

int main() {
    int amount;
    int number;
    string line;
    vector<int> coins;

    std::cout << "Enter the amount: " << std::endl;
    std::cin >> amount;

    std::cin.ignore(); // To handle the issue of using ">>" operator with getline()
    std::cout << "Enter the coins of different denominations separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        coins.push_back(number);

    std::cout << "Number of combinations that make up the amount: " << Solution::change(amount, coins);

    return 0;
}

