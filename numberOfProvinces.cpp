//
// Created by Ankit Batra on 1/27/21.
//

/* There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b,
 * and city b is connected directly with city c, then city a is connected indirectly with city c.
 * A province is a group of directly or indirectly connected cities and no other cities outside of the group.
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1
 * if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
 * Return the total number of provinces. */

#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
public:
    static int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        if (n == 0) return 0;
        unordered_map<int, vector<int>> adjList;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j != i && isConnected[i][j] == 1) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        for (auto l : adjList) {
            cout << l.first <<": ";
            for (int c : l.second) cout << c << " ";
            cout << endl;
        }

        int numProvinces = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, adjList, visited);
                numProvinces++;
            }
        }

        return numProvinces;
    }

    static void dfs(int node, unordered_map<int, vector<int>>& g, vector<bool>& visited) {
        visited[node] = true;

        for (int neighbor : g[node]) {
            if (!visited[neighbor]) dfs(neighbor, g, visited);
        }
    }
};

int main() {
    return 0;
}