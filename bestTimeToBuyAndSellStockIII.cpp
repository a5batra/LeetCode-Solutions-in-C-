//
// Created by Ankit Batra on 12/18/20.
//

/* Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 * Note: You may not engage in multiple transactions at the same time
 * (i.e., you must sell the stock before you buy again). */

#include <iostream>
#include <sstream>
#include <vector>

using std::max;
using std::min;
using std::string;
using std::vector;

class Solution {
public:
    static int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<int> leftBuy(n);
        vector<int> rightBuy(n);
        int leftMin = prices[0], rightMax = prices[n - 1];
        int maxProf = 0;

        for (int i = 1; i < n; ++i) {
            leftBuy[i] = max(leftBuy[i - 1], prices[i - 1] - leftMin);
            leftMin = min(leftMin, prices[i]);
        }

        for (int i = n - 2; i >= 0; --i) {
            rightBuy[i] = max(rightBuy[i + 1], rightMax - prices[i]);
            rightMax = max(rightMax, prices[i]);
        }

        for (int i = 0; i < n; ++i) {
            maxProf = max(maxProf, leftBuy[i] + rightBuy[i]);
        }

        return maxProf;
    }
};

int main() {
    int number;
    string line;
    vector<int> prices;

    std::cout << "Enter the prices: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number) prices.push_back(number);

    std::cout << "Maximum profit: " << Solution::maxProfit(prices);

    return 0;
}

