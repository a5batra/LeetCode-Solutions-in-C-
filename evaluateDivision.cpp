//
// Created by Ankit Batra on 1/11/21.
//

/* You are given an array of variable pairs equations and an array of real numbers values,
 * where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i].
 * Each Ai or Bi is a string that represents a single variable.
 * You are also given some queries, where queries[j] = [Cj, Dj]
 * represents the jth query where you must find the answer for Cj / Dj = ?.
 * Return the answers to all queries. If a single answer cannot be determined, return -1.0.
 *
 * Note: The input is always valid.
 * You may assume that evaluating the queries will not result in division by zero and that there is no contradiction. */

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::pair;
using std::string;
using std::unordered_set;
using std::unordered_map;
using std::vector;

class Solution {
public:
    static unordered_map<string, vector<pair<string, double >>> buildGraph(vector<vector<string>>& equations, vector<double>& values) {
        int n = equations.size();
        unordered_map<string, vector<pair<string, double >>> g;

        for (int i = 0; i < n; ++i) {
            string src = equations[i][0], dest = equations[i][1];
            double wt = values[i];
            if (g.find(src) !=  g.end()) g[src].push_back({dest, wt});
            else g[src] = {{dest, wt}};
            if (g.find(dest) != g.end()) g[dest].push_back({src, 1 / wt});
            else g[dest] = {{src, 1 / wt}};
        }

        return g;
    }
    static vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        vector<double> result(queries.size());

        unordered_map<string, vector<pair<string, double >>> adjList = buildGraph(equations, values);

        for (int i = 0; i < queries.size(); ++i) {
            unordered_set<string> visited;
            result[i] = dfs(queries[i][0], queries[i][1], adjList, visited);
        }

        return result;
    }

    static double dfs(string src, string dest, unordered_map<string, vector<pair<string, double >>>& g, unordered_set<string>& visited)  {
        if (g.find(src) ==  g.end() || g.find(dest) == g.end()) return -1.0;
        if (src == dest) return  1.0;

        visited.insert(src);

        for (pair<string, double> p : g[src]) {
            if (visited.find(p.first) == visited.end()) {
                double ans = dfs(p.first, dest, g, visited);
                if (ans != -1.0) return ans * p.second;
            }
        }
        return -1.0;
    }
};

int main() {
    vector<vector<string>> equations = {{"a","b"}, {"b","c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};

    vector<double> result = Solution::calcEquation(equations, values, queries);

    for (double val : result) std::cout << val << " ";

    return 0;
}
