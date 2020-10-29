//
// Created by Ankit Batra on 10/28/20.
//

/* There are N students in a class. Some of them are friends, while some are not.
 * Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C,
 * then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct
 * or indirect friends.
 * Given a N*N matrix M representing the friend relationship between students in the class.
 * If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not.
 * And you have to output the total number of friend circles among all the students. */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    static void dfs(vector<vector<int>>& M, vector<bool>& visited, int i) {
        visited[i] = true;
        for (int j = 0; j < M.size(); ++j) {
            if (M[i][j] == 1 && !visited[j]) {
                dfs(M, visited, j);
            }
        }
    }
    static int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if (n == 0) return -1;

        int friendCircles = 0;
        vector<bool> visited(n);

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(M, visited, i);
                friendCircles++;
            }
        }
        return friendCircles;
    }
};

int main() {
    vector<vector<int>> M = {{1,1,0},
                             {1,1,0},
                             {0,0,1}};

    std::cout << "Number of friend circles: " << Solution::findCircleNum(M);

    return 0;
}

