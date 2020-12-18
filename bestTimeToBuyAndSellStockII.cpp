//
// Created by Ankit Batra on 12/17/20.
//

/* Say you have an array prices for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit.
 * You may complete as many transactions as you like
 * (i.e., buy one and sell one share of the stock multiple times).
 * Note: You may not engage in multiple transactions at the same time
 * (i.e., you must sell the stock before you buy again). */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        int maxProf = 0;
        for (int i = 1; i < n; ++i) {
            if (prices[i] > prices[i - 1]) maxProf += prices[i] - prices[i - 1];
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
    while (stream >> number)
        prices.push_back(number);

    std::cout << "Maximum profit: " << Solution::maxProfit(prices);

    return 0;
}
