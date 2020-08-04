//
// Created by Ankit Batra on 8/3/20.
//

/* Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock),
 * design an algorithm to find the maximum profit. Note that you cannot sell a stock before you buy one. */

#include <iostream>
#include <vector>
#include <sstream>

using std::string;
using std::vector;

class Solution {
public:
    static int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buyingPrice = prices[0];
        int sellingPrice = 0;
        int maxProfit = 0;

        for (int i = 1; i < n; ++i) {
            sellingPrice = prices[i];
            if (sellingPrice - buyingPrice > 0) {
                maxProfit = std::max(maxProfit, sellingPrice - buyingPrice);
            }
            else
                buyingPrice = sellingPrice;
        }
        return maxProfit;
    }
};

int main() {
    int number;
    string line;
    vector<int> arr;

    std::cout << "Enter the elements of array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        arr.push_back(number);

    std::cout << "Maximum profit: " << Solution::maxProfit(arr);
    return 0;
}