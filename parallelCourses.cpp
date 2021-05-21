//
// Created by Ankit Batra on 5/20/21.
//

/* You are given an integer n which indicates that we have n courses, labeled from 1 to n.
 * You are also given an array relations where relations[i] = [a, b], representing a prerequisite relationship
 * between course a and course b: course a has to be studied before course b.
 * In one semester, you can study any number of courses as long as you have studied all the prerequisites for the
 * course you are studying.
 * Return the minimum number of semesters needed to study all courses.
 * If there is no way to study all the courses, return -1. */

#include <queue>
#include <vector>

using std::queue;
using std::vector;

class Solution {
public:
    vector<vector<int>> buildGraph(int n, vector<vector<int>>& relations) {
        vector<vector<int>> g(n);

        for (vector<int>& r : relations) {
            int u = r[0] - 1, v = r[1] - 1;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        return g;
    }
    vector<int> buildIndegree(int n, vector<vector<int>>& relations) {
        vector<int> indegree(n);
        for (vector<int>& r : relations) {
            int u = r[0] - 1, v = r[1] - 1;
            indegree[v]++;
        }
        return indegree;
    }
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> adjList = buildGraph(n, relations);
        vector<int> indegree = buildIndegree(n, relations);

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (!indegree[i]) q.push(i);
        }

        int numSems = 0;
        int total = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int course = q.front();
                q.pop();
                for (int c : adjList[course]) {
                    indegree[c]--;
                    if (!indegree[c]) q.push(c);
                }
                total++;
            }
            numSems++;
        }
        return total == n ? numSems : -1;
    }
};

