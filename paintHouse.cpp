//
// Created by Ankit Batra on 6/1/21.
//

/* There is a row of n houses, where each house can be painted one of three colors: red, blue, or green.
 * The cost of painting each house with a certain color is different.
 * You have to paint all the houses such that no two adjacent houses have the same color.
 * The cost of painting each house with a certain color is represented by an n x 3 cost matrix costs.
 * For example, costs[0][0] is the cost of painting house 0 with the color red; costs[1][2] is the cost of
 * painting house 1 with color green, and so on...
 * Return the minimum cost to paint all houses. */

class Solution {
public:
    int helper(vector<vector<int>>& costs, int idx, int currColor, vector<vector<int>>& state) {
        if (idx >= costs.size()) return 0;
        if (state[idx][currColor] != -1) return state[idx][currColor];

        int cost = costs[idx][currColor];
        int nextColor = (currColor + 1) % 3;
        int nextNextColor = (currColor + 2) % 3;
        cost += min(helper(costs, idx + 1, nextColor, state), helper(costs, idx + 1, nextNextColor, state));

        return state[idx][currColor] = cost;
    }
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> state(n, vector<int>(3, -1));
        int cost = min(helper(costs, 0, 0, state), min(helper(costs, 0, 1, state), helper(costs, 0, 2, state)));

        return cost;
    }
};

