//
// Created by Ankit Batra on 5/21/21.
//

/* You are given an integer n which indicates that we have n courses, labeled from 1 to n.
 * You are also given an array relations where relations[i] = [a, b], representing a prerequisite relationship
 * between course a and course b: course a has to be studied before course b.
 * In one semester, you can study any number of courses as long as you have studied all the prerequisites for the
 * course you are studying.
 * Return the minimum number of semesters needed to study all courses.
 * If there is no way to study all the courses, return -1. */

// 0 : not visited
// -1 : processing
// > 1 : visited
class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> adjList(n);
        for (vector<int>& r : relations) {
            int u = r[0] - 1, v = r[1] - 1;
            adjList[u].push_back(v);
        }
        vector<int> visited(n);
        int maxLen = 0;
        for (int i = 0; i < n; ++i) {
            int len = dfs(adjList, i, visited);
            if (len == -1) return -1;
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
    int dfs(vector<vector<int>>& g, int node, vector<int>& visited) {
        if (visited[node] != 0) return visited[node];

        visited[node] = -1;

        int maxLen = 1;

        for (int& n : g[node]) {
            int len = dfs(g, n, visited);
            if (len == -1) return -1;
            maxLen = max(1 + len, maxLen);
        }
        visited[node] = maxLen;

        return maxLen;
    }
};

