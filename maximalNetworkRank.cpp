//
// Created by Ankit Batra on 10/12/20.
//

/* There is an infrastructure of n cities with some number of roads connecting these cities.
 * Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.
 * The network rank of two different cities is defined as the total number of directly connected roads to either city.
 * If a road is directly connected to both cities, it is only counted once.
 * The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.
 * Given the integer n and the array roads, return the maximal network rank of the entire infrastructure. */

#include <iostream>
#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution {
public:
    static int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maxRank = 0;
        vector<unordered_set<int>> adjList(n);

        for (int i = 0; i < roads.size(); ++i) {
            adjList[roads[i][0]].insert(roads[i][1]);
            adjList[roads[i][1]].insert(roads[i][0]);
        }

        // Just for debugging
//        for (int i = 0; i < n; ++i) {
//            std::cout << i << " : ";
//            for (auto it = adjList[i].begin(); it != adjList[i].end(); ++it)
//                std::cout << *it << " ";
//            std::cout << std::endl;
//        }

        int rank = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                rank = adjList[i].size() + adjList[j].size();
                if (adjList[i].find(j) != adjList[i].end()) rank--;
                if (rank > maxRank) maxRank = rank;
            }
        }
        return maxRank;
    }
};

int main() {
    int n = 8;
    vector<vector<int>> roads = {{0,1},{1,2},{2,3},{2,4},{5,6},{5,7}};

    std::cout << "Maximal network rank for this case: " << Solution::maximalNetworkRank(n, roads);
    return 0;
}
