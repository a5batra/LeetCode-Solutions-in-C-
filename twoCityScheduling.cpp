//
// Created by Ankit Batra on 6/3/20.
//

/* There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0],
 * and the cost of flying the i-th person to city B is costs[i][1].
 * Return the minimum cost to fly every person to a city such that exactly N people arrive in each city. */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    static bool customSortOnDiff(vector<int> cost1, vector<int> cost2) {
        return (cost1[0] - cost1[1] > cost2[0] - cost2[1]);
    }
    static int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int totalCost = 0;
        std::sort(costs.begin(), costs.end(), customSortOnDiff);

        for (int i = 0; i < n; ++i) {
            if (i < n / 2)
                totalCost += costs[i][1];
            else
                totalCost += costs[i][0];
        }

        return totalCost;
    }
};

int main() {
    vector<vector<int>> costs = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};

    std::cout << "Minimum cost to fly: " << Solution::twoCitySchedCost(costs) << std::endl;

    return 0;
}



