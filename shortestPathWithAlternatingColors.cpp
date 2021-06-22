//
// Created by Ankit Batra on 6/22/21.
//

/* Consider a directed graph, with nodes labelled 0, 1, ..., n-1.  In this graph, each edge is either red or
 * blue, and there could be self-edges or parallel edges.
 * Each [i, j] in red_edges denotes a red directed edge from node i to node j.
 * Similarly, each [i, j] in blue_edges denotes a blue directed edge from node i to node j.
 * Return an array answer of length n, where each answer[X] is the length of the shortest path from node 0 to
 * node X such that the edge colors alternate along the path (or -1 if such a path doesn't exist). */

class Solution {
public:
    vector<vector<int>> buildGraph(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<int>> g (n, vector<int>(n, -n));

        for (vector<int>& r : red_edges) {
            int from = r[0], to = r[1];
            g[from][to] = 1;
        }
        for (vector<int>& b : blue_edges) {
            int from = b[0], to = b[1];
            if (g[from][to] == 1) g[from][to] = 0;
            else g[from][to] = -1;
        }

        return g;
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<int>> adjList = buildGraph(n, red_edges, blue_edges);
        vector<int> ans(n, INT_MAX);
        ans[0] = 0;

        queue<pair<int, int>> q; // node, color
        q.push({0, 1});
        q.push({0, -1});

        int dist = 0;

        unordered_set<string> visited;

        while (!q.empty()) {
            int sz = q.size();
            dist++;
            while (sz--) {
                pair<int, int> p = q.front();
                q.pop();
                int node = p.first, color = p.second;
                int oppColor = -color;
                for (int j = 1; j < n; ++j) {
                    if (adjList[node][j] == oppColor || adjList[node][j] == 0) {
                        string key = to_string(j) + "*" + to_string(oppColor);
                        if (visited.count(key)) continue;
                        visited.insert(key);
                        q.push({j, oppColor});
                        ans[j] = min(ans[j], dist);
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (ans[i] == INT_MAX) ans[i] = -1;
        }

        return ans;
    }
};

