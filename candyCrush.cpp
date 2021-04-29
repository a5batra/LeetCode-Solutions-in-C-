//
// Created by Ankit Batra on 4/27/21.
//

/* This question is about implementing a basic elimination algorithm for Candy Crush.
 * Given a 2D integer array board representing the grid of candy, different positive integers board[i][j]
 * represent different types of candies. A value of board[i][j] = 0 represents that the cell at position (i, j)
 * is empty. The given board represents the state of the game following the player's move.
 * Now, you need to restore the board to a stable state by crushing candies according to the following rules:
 *
 * If three or more candies of the same type are adjacent vertically or horizontally,
 * "crush" them all at the same time - these positions become empty.
 * After crushing all candies simultaneously, if an empty space on the board has candies on top of itself,
 * then these candies will drop until they hit a candy or bottom at the same time.
 * (No new candies will drop outside the top boundary.)
 * After the above steps, there may exist more candies that can be crushed.
 * If so, you need to repeat the above steps.
 * If there does not exist more candies that can be crushed (ie. the board is stable),
 * then return the current board.
 * You need to perform the above rules until the board becomes stable, then return the current board. */

#include <vector>

using std::vector;

class Solution {
public:
    void rewriteCol(vector<vector<int>>& board, int col) {
        int m = board.size();

        int r = m - 1;
        for (int i = m - 1; i >= 0; --i) {
            if (board[i][col] >= 0) {
                board[r--][col] = board[i][col];
            }
        }
        for (int i = r; i >= 0; --i) {
            board[i][col] = 0;
        }

    }

    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int count = 0;
        bool isStable = false;

        while (!isStable) {
            // crush
            isStable = true;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    dfs(board, i, j, board[i][j], count, 'r');
                    if (count >= 3)
                        isStable = false;
                    count = 0;
                    dfs(board, i, j, board[i][j], count, 'd');
                    if (count >= 3)
                        isStable = false;
                    count = 0;
                }
            }
            // gravity
            for (int j = 0; j < n; ++j) {
                rewriteCol(board, j);
            }
        }

        return board;
    }

    void dfs(vector<vector<int>>& board, int r, int c, int prevVal, int& count, char dir) {
        int m = board.size();
        int n = board[0].size();
        if (r >= m || c >= n || (abs(board[r][c]) != abs(prevVal)) || board[r][c] == 0) return;

        count += 1;

        if (dir == 'r')
            dfs(board, r, c + 1, board[r][c], count, 'r');
        else dfs(board, r + 1, c, board[r][c], count, 'd');

        if (count >= 3 && board[r][c] > 0) {
            board[r][c] = -board[r][c];
        }

    }
};

