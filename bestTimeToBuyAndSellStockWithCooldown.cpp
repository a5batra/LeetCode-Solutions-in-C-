//
// Created by Ankit Batra on 1/6/21.
//

/* Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit.
 * You may complete as many transactions as you like
 * (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day) */

#include <iostream>
#include <sstream>
#include <vector>

using std::max;
using std::string;
using std::vector;

class Solution {
public:
    static int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        int maxProf = 0;
        vector<int> state(n, -1);

        maxProf = helper(prices, 0, state);

        return maxProf;
    }

    static int helper(vector<int>& prices, int idx, vector<int>& state) {
        if (idx >= prices.size()) return 0;

        if (state[idx] != -1) return state[idx];

        int maxVal = 0;
        for (int i = idx + 1; i < prices.size(); ++i) {
            if (prices[i] > prices[idx]) {
                maxVal = max(maxVal, prices[i] - prices[idx] + helper(prices, i + 2, state));
            }
        }
        maxVal = max(maxVal, helper(prices, idx + 1, state));

        return state[idx] = maxVal;
    }
};

int main() {
    int number;
    string line;
    vector<int> prices;

    std::cout << "Enter the array of prices: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        prices.push_back(number);

    std::cout << "Result: " << Solution::maxProfit(prices);

    return 0;
}