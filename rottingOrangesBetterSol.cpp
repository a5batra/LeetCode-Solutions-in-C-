//
// Created by ankitb on 1/30/21.
//

/* In a given grid, each cell can have one of three values:
 * the value 0 representing an empty cell;
 * the value 1 representing a fresh orange;
 * the value 2 representing a rotten orange.
 * Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.
 * Return the minimum number of minutes that must elapse until no cell has a fresh orange.
 * If this is impossible, return -1 instead. */

#include <iostream>
#include <queue>
#include <vector>

using std::make_pair;
using std::pair;
using std::queue;
using std::vector;

class Solution {
    struct Node {
        int time;
        pair<int, int> id;

        Node(int t, pair<int, int> index) : time(t), id(index){
        }
    };
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();

        queue<Node> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) q.push(Node(0, {i, j}));
            }
        }

        int numMin = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                Node node = q.front();
                numMin = q.front().time;
                q.pop();
                int t = node.time;
                pair<int, int> p = node.id;
                int r = p.first, c = p.second;
                if (c < n - 1 && grid[r][c + 1] == 1) {
                    grid[r][c + 1] = 2;
                    q.push(Node(t + 1, {r, c + 1}));
                }
                if (r < m - 1 && grid[r + 1][c] == 1) {
                    grid[r + 1][c] = 2;
                    q.push(Node(t + 1, {r + 1, c}));
                }
                if (c > 0 && grid[r][c - 1] == 1) {
                    grid[r][c - 1] = 2;
                    q.push(Node(t + 1, {r, c - 1}));
                }
                if (r > 0 && grid[r - 1][c] == 1) {
                    grid[r - 1][c] = 2;
                    q.push(Node(t + 1, {r - 1, c}));
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return numMin;

    }
};

int main() {
    return 0;
}