//
// Created by Ankit Batra on 12/27/20.
//

/* There are a total of n courses you have to take labelled from 0 to n - 1.
 * Some courses may have prerequisites, for example, if prerequisites[i] = [ai, bi]
 * this means you must take the course bi before the course ai.
 * Given the total number of courses numCourses and a list of the prerequisite pairs,
 * return the ordering of courses you should take to finish all courses.
 * If there are many valid answers, return any of them.
 * If it is impossible to finish all courses, return an empty array. */

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using std::queue;
using std::unordered_map;
using std::vector;

class Solution {
public:
    static unordered_map<int, vector<int>> buildMap(vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> map;

        for (vector<int> courses : prerequisites) {
            int courseX = courses[1];
            int courseDependsOnX = courses[0];
            if (map.find(courseX) != map.end()) map[courseX].push_back(courseDependsOnX);
            else map[courseX] = {courseDependsOnX};
        }

        return map;
    }
    static vector<int> buildIndegree(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);

        for (vector<int> courses : prerequisites)  {
            int course = courses[0];
            indegree[course]++;
        }

        return indegree;
    }
    static vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;

        unordered_map<int, vector<int>> adjacencyList = buildMap(prerequisites);

        vector<int> indegree = buildIndegree(numCourses, prerequisites);

        queue<int> q;
        int count = 0;

        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            result.push_back(course);
            count++;
            for (int neighbor : adjacencyList[course]) {
                if (--indegree[neighbor] == 0) q.push(neighbor);
            }
        }

        if (count != numCourses) return {};

        return result;
    }
};

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> result;

    result =  Solution::findOrder(numCourses, prerequisites);

    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }

    return 0;
}