//
// Created by Ankit Batra on 5/23/21.
//

/* On an N x N board, the numbers from 1 to N*N are written boustrophedonically starting from the bottom left of the
 * board, and alternating direction each row.  For example, for a 6 x 6 board, the numbers are written as follows:
 * You start on square 1 of the board (which is always in the last row and first column).
 * Each move, starting from square x, consists of the following:
 * You choose a destination square S with number x+1, x+2, x+3, x+4, x+5, or x+6, provided this number is <= N*N.
 * (This choice simulates the result of a standard 6-sided die roll: ie., there are always at most 6 destinations,
 * regardless of the size of the board.)
 * If S has a snake or ladder, you move to the destination of that snake or ladder.
 * Otherwise, you move to S.
 * A board square on row r and column c has a "snake or ladder" if board[r][c] != -1.
 * The destination of that snake or ladder is board[r][c].
 * Note that you only take a snake or ladder at most once per move:
 * if the destination to a snake or ladder is the start of another snake or ladder, you do not continue moving.
 * (For example, if the board is `[[4,-1],[-1,3]]`, and on the first move your destination square is `2`,
 * then you finish your first move at `3`, because you do not continue moving to `4`.)
 * Return the least number of moves required to reach square N*N.  If it is not possible, return -1. */

#include <queue>
#include <vector>

using std::queue;
using std::vector;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int> q;
        int moves = 0;
        q.push(1);

        vector<bool> visited(n * n + 1, false);
        visited[1] = true;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int curr = q.front();
                q.pop();
                if (curr == n * n) return moves;
                for (int i = 1; i <= 6; ++i) {
                    int num = curr + i;
                    if (num > n * n) break;
                    if (visited[num]) continue;
                    visited[num] = true;
                    int row = n - (num - 1) / n - 1;
                    int col = (n - row) % 2 == 0 ? n - (num - 1) % n - 1 : (num - 1)  % n;
                    if (board[row][col] == -1) q.push(num);
                    else q.push(board[row][col]);
                }
            }
            moves++;
        }
        return -1;
    }
};

