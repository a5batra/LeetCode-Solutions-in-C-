//
// Created by Ankit Batra on 10/21/20.
//

/* There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1,
 * which is expressed as a pair: [0,1]
 * Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses? */

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using std::queue;
using std::unordered_map;
using std::vector;

class Solution {
public:
    static unordered_map<int, vector<int>> buildMap(int& numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < numCourses; ++i) {
            map[i] = vector<int>();
        }

        for (auto arr : prerequisites) {
            int courseX = arr[1];
            int courseDependsOnX = arr[0];
            map[courseX].push_back(courseDependsOnX);
        }
        return map;
    }
    static vector<int> buildInDegree(int& numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses);
        for (auto arr : prerequisites) {
            int course = arr[0];
            inDegree[course]++;
        }
        return inDegree;
    }
    static bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> map = buildMap(numCourses, prerequisites);
        vector<int> inDegree = buildInDegree(numCourses, prerequisites);

        int count = 0;
        queue<int> q;
        for (int i = 0; i < inDegree.size(); ++i) {
            if (inDegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int currCourse = q.front();
            q.pop();
            count++;
            for (auto neighbor : map[currCourse]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) q.push(neighbor);
            }
        }
        return count == numCourses;
    }
};

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0},{0,1}};

    std::cout << "Result: " << Solution::canFinish(numCourses, prerequisites);
    return 0;
}

