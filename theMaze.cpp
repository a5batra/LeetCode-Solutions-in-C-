//
// Created by Ankit Batra on 5/14/21.
//

/* There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1).
 * The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until
 * hitting a wall. When the ball stops, it could choose the next direction.
 * Given the m x n maze, the ball's start position and the destination, where start =
 * [startrow, startcol] and destination = [destinationrow, destinationcol],
 * return true if the ball can stop at the destination, otherwise return false.
 * You may assume that the borders of the maze are all walls (see examples). */

#include <set>
#include <vector>

using std::set;
using std::vector;

class Solution {
    set<vector<int>> st;
    vector<vector<int>> directions;
public:
    Solution() {
        directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        return dfs(maze, start, destination);
    }

    bool dfs(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        if (st.count(start)) return false;
        st.insert(start);
        if (start == dest) return true;
        for (vector<int>& dir : directions) {
            int nr = start[0], nc = start[1];
            while (nr >= 0 && nr < maze.size() && nc >= 0 && nc < maze[0].size() && maze[nr][nc] != 1) {
                nr += dir[0];
                nc += dir[1];
            }
            nr -= dir[0];
            nc -= dir[1];
            vector<int> newPos = {nr, nc};
            if (dfs(maze, newPos, dest)) {
                return true;
            }
        }
        return false;
    }
};

