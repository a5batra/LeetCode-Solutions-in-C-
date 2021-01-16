//
// Created by Ankit Batra on 1/15/21.
//

/* Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes),
 * write a function to find the number of connected components in an undirected graph. */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
    unordered_map<int, vector<int>> adjList;
    unordered_set<int> visited;
public:
    void buildGraph(vector<vector<int>>& edges) {
        for (vector<int> edge : edges) {
            int u = edge[0], v = edge[1];
            if (adjList.find(u) != adjList.end()) adjList[u].push_back(v);
            else adjList[u] = {v};
            if (adjList.find(v) != adjList.end()) adjList[v].push_back(u);
            else adjList[v] = {u};
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        buildGraph(edges);
        int connCompts = 0;

        for (int i = 0; i < n; ++i) {
            if (visited.find(i) == visited.end()) {
                dfs(i);
                connCompts++;
            }
        }
        return connCompts;
    }
    void dfs(int vertex) {
        visited.insert(vertex);

        for (int neighbor : adjList[vertex]) {
            if (visited.find(neighbor) == visited.end()) dfs(neighbor);
        }
    }
};

int main() {
    return 0;
}