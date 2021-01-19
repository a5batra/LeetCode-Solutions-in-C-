//
// Created by Ankit Batra on 1/18/21.
//

/* We have a list of bus routes. Each routes[i] is a bus route that the i-th bus repeats forever.
 * For example if routes[0] = [1, 5, 7], this means that the first bus (0-th indexed) travels in the sequence
 * 1->5->7->1->5->7->1->... forever.
 * We start at bus stop S (initially not on a bus), and we want to go to bus stop T.
 * Travelling by buses only, what is the least number of buses we must take to reach our destination?
 * Return -1 if it is not possible. */

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::pair;
using std::queue;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
    unordered_map<int, vector<int>> adjList;
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        for (int i = 0; i < routes.size(); ++i) {
            for (int stop : routes[i]) adjList[stop].push_back(i);
        }

        unordered_set<int> visitedStops;
        unordered_set<int> visitedRoutes;
        queue<pair<int, int>> q;
        q.push({S, 0});

        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int stop = p.first, busNum = p.second;
            if (stop == T) return busNum;

            for (int route : adjList[stop]) {
                if (visitedRoutes.find(route) == visitedRoutes.end()) {
                    visitedRoutes.insert(route);
                    for (int stop : routes[route]) {
                        if (visitedStops.find(stop) == visitedStops.end()) {
                            visitedStops.insert(stop);
                            q.push({stop, busNum + 1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> routes = {{1,2,7},{3,6,7}};
    int S = 1, T = 6;

    Solution obj;
    std::cout << "Result: " << obj.numBusesToDestination(routes, S, T);

    return 0;
}
