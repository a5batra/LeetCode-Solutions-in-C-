//
// Created by Ankit Batra on 1/16/21.
//

/* You have some number of sticks with positive integer lengths. These lengths are given as an array sticks,
 * where sticks[i] is the length of the ith stick.
 * You can connect any two sticks of lengths x and y into one stick by paying a cost of x + y.
 * You must connect all the sticks until there is only one stick remaining.
 * Return the minimum cost of connecting all the given sticks into one stick in this way. */

#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

using std::priority_queue;
using std::string;
using std::vector;

class Solution {
public:
    static int connectSticks(vector<int>& sticks) {
        int n = sticks.size();
        if (n == 0 || n == 1) return 0;

        int minCost = 0;

        priority_queue<int, vector<int>, std::greater<int>> pq;
        for (int s : sticks) pq.push(s);

        while (pq.size() > 1) {
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            minCost += s1 + s2;
            pq.push(s1 + s2);
        }
        return minCost;
    }
};

int main() {
    int number;
    string line;
    vector<int> sticks;

    std::cout << "Enter the array containing stick lengths: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number) sticks.push_back(number);

    std::cout << "Minimum Cost: " << Solution::connectSticks(sticks);

    return 0;
}
