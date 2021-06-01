//
// Created by Ankit Batra on 5/31/21.
//

/* In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].
 * A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction,
 * then one square in an orthogonal direction.
 * Return the minimum number of steps needed to move the knight to the square [x, y].
 * It is guaranteed the answer exists. */

class Solution {
    vector<vector<int>> dirs;
public:
    Solution() {
        dirs = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
    }
    int minKnightMoves(int x, int y) {
        pair<int, int> start = {0, 0};
        pair<int, int> end = {x, y};

        queue<pair<int, int>> q;
        q.push(start);
        int minSteps = 0;

        vector<vector<bool>> visited(800, vector<bool>(800));
        int offset = 400;
        visited[0 + offset][0 + offset] = true;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                pair<int, int> p = q.front();
                q.pop();
                int r = p.first, c = p.second;
                if (p == end) return minSteps;
                for (vector<int>& dir : dirs) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    if (visited[nr + offset][nc + offset]) continue;
                    visited[nr + offset][nc + offset] = true;
                    q.push({nr, nc});
                }
            }
            minSteps++;
        }

        return -1;
    }
};

