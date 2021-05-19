//
// Created by Ankit Batra on 5/19/21.
//

/* You are starving and you want to eat food as quickly as possible.
 * You want to find the shortest path to arrive at any food cell.
 * You are given an m x n character matrix, grid, of these different types of cells:
 * '*' is your location. There is exactly one '*' cell.
 * '#' is a food cell. There may be multiple food cells.
 * 'O' is free space, and you can travel through these cells.
 * 'X' is an obstacle, and you cannot travel through these cells.
 * You can travel to any adjacent cell north, east, south, or west of your current location if there
 * is not an obstacle.
 *
 * Return the length of the shortest path for you to reach any food cell.
 * If there is no path for you to reach food, return -1. */

#include <vector>

using std::pair;
using std::vector;

class Solution {
public:
    pair<int, int> getStartLoc(vector<vector<char>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '*') return {i, j};
            }
        }
        return {-1, -1};
    }
    int getFood(vector<vector<char>>& grid) {
        pair<int, int> startLoc = getStartLoc(grid);
        int m = grid.size(), n = grid[0].size();

        queue<vector<int>> q;
        q.push({startLoc.first, startLoc.second, 0});
        int dist = 0;
        set<pair<int, int>> visited;

        while (!q.empty()) {
            vector<int> p = q.front();
            int r = p[0], c = p[1];
            int dist = p[2];
            q.pop();
            if (grid[r][c] == '#') return dist;
            if (c < n - 1 && grid[r][c + 1] != 'X' && !visited.count(make_pair(r, c + 1))) {
                visited.insert({r, c + 1});
                q.push({r, c + 1, dist + 1});
            }
            if (r < m - 1 && grid[r + 1][c] != 'X' && !visited.count(make_pair(r + 1, c))) {
                visited.insert({r + 1, c});
                q.push({r + 1, c, dist + 1});
            }
            if (c > 0 && grid[r][c - 1] != 'X' && !visited.count(make_pair(r, c - 1))) {
                visited.insert({r, c - 1});
                q.push({r, c - 1, dist + 1});
            }

            if (r > 0 && grid[r - 1][c] != 'X' && !visited.count(make_pair(r - 1, c))) {
                visited.insert({r - 1, c});
                q.push({r - 1, c, dist + 1});
            }
        }
        return -1;
    }
};

