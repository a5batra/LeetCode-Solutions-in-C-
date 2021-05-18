//
// Created by Ankit Batra on 5/17/21.
//

/* There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b,
 * and city b is connected directly with city c, then city a is connected indirectly with city c.
 * A province is a group of directly or indirectly connected cities and no other cities outside of the group.
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1
 * if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
 * Return the total number of provinces. */

#include <vector>

using std::vector;

class Solution {
public:
    int find(vector<int>& parent, int u) {
        if (parent[u] == -1) return u;
        return parent[u] = find(parent, parent[u]);
    }

    void unionOp(vector<int>& parent, int u, int v) {
        int parentU = find(parent, u);
        int parentV = find(parent, v);
        parent[parentU] = parentV;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n);
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (isConnected[i][j] == 1) {
                    adjList[i].push_back(j);
                }
            }
        }

        vector<int> parent(n, -1);

        for (int u = 0; u < n; ++u) {
            for (int v : adjList[u]) {
                int parentU = find(parent, u);
                int parentV = find(parent, v);
                if (parentU == parentV) continue;

                unionOp(parent, u, v);
            }
        }

        for (int p : parent) {
            if (p == -1) ans++;
        }
        return ans;
    }
};

