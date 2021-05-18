//
// Created by Ankit Batra on 5/16/21.
//

/* Given an undirected tree, return its diameter: the number of edges in a longest path in that tree.
 * The tree is given as an array of edges where edges[i] = [u, v] is a bidirectional edge between nodes u and v.
 * Each node has labels in the set {0, 1, ..., edges.length}. */

#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
    unordered_map<int, vector<int>> adjList;
    pair<int, int> farthest;
public:
    Solution() {
        farthest = make_pair(-1, -1);
    }
    void buildGraph(vector<vector<int>>& edges) {
        for (vector<int>& e : edges) {
            int u = e[0], v = e[1];
            if (adjList.count(u)) adjList[u].push_back(v);
            else adjList[u] = {v};
            if (adjList.count(v)) adjList[v].push_back(u);
            else adjList[v] = {u};
        }
    }
    void dfs(int node, int parent, int dist) {
        if (dist > farthest.second) {
            farthest.first = node;
            farthest.second = dist;
        }
        for (int neighbor : adjList[node]) {
            if (neighbor == parent) continue;
            dfs(neighbor, node, dist + 1);
        }
    }
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size();
        int diameter = 0;
        buildGraph(edges);

        dfs(0, -1, 0);

        int n1 = farthest.first;
        farthest.first = -1, farthest.second = -1; // reset the pair

        dfs(n1, -1, 0);

        diameter = farthest.second;

        return diameter;
    }
};

