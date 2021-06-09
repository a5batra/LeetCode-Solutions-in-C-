//
// Created by Ankit Batra on 6/8/21.
//

/* There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1).
 * The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until
 * hitting a wall. When the ball stops, it could choose the next direction.
 * Given the m x n maze, the ball's start position and the destination, where start = [startrow, startcol] and
 * destination = [destinationrow, destinationcol], return the shortest distance for the ball to stop at the
 * destination. If the ball cannot stop at destination, return -1.
 * The distance is the number of empty spaces traveled by the ball from the start position (excluded) to the
 * destination (included). */

struct Node {
    int row;
    int col;
    int dist;
    Node(int r, int c, int d) : row(r), col(c), dist(d) {};
};
class myCompare {
public:
    bool operator()(Node& n1, Node& n2) {
        return n1.dist > n2.dist;
    }
};
class Solution {
    vector<vector<int>> dirs;
public:
    Solution() {
        dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    }
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        priority_queue<Node, vector<Node>, myCompare> pq;
        pq.push(Node(start[0], start[1], 0));
        vector<vector<bool>> visited(m, vector<bool>(n));

        while (!pq.empty()) {
            Node curr = pq.top();
            pq.pop();
            int r = curr.row, c = curr.col;
            if (visited[r][c]) continue;
            visited[r][c] = true;
            int dist = curr.dist;
            if (r == destination[0] && c == destination[1]) return dist;
            for (vector<int>& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                int d = dist;
                while (nr >= 0 && nr < m && nc >= 0 && nc < n && maze[nr][nc] != 1) {
                    nr += dir[0];
                    nc += dir[1];
                    d++;
                }
                nr -= dir[0];
                nc -= dir[1];
                pq.push(Node(nr, nc, d));
            }
        }
        return -1;
    }
};

