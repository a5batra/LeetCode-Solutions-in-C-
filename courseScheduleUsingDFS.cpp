//
// Created by Ankit Batra on 4/7/21.
//

/* There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
 * You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course
 * bi first if you want to take course ai.
 * For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
 * Return true if you can finish all courses. Otherwise, return false. */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> buildGraph(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(n);
        for (vector<int>& p : prerequisites) {
            int courseX = p[1];
            int courseDependsOnX = p[0];
            g[courseX].push_back(courseDependsOnX);
        }
        return g;
    }
    bool isCyclic(int curr, vector<vector<int>>& graph, vector<int>& visited) {
        if (visited[curr] == 2) return true;

        visited[curr] = 2;
        for (int n : graph[curr]) {
            if (visited[n] != 1) {
                if (isCyclic(n, graph, visited)) return true;
            }
        }
        visited[curr] = 1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);

        vector<int> visited(numCourses, 0);

        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0) {
                if (isCyclic(i, graph, visited)) return false;
            }
        }
        return true;
    }
};

