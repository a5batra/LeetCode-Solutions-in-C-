//
// Created by Ankit Batra on 5/22/21.
//

/* Assume the following rules are for the tic-tac-toe game on an n x n board between two players:
 * A move is guaranteed to be valid and is placed on an empty block.
 * Once a winning condition is reached, no more moves are allowed.
 * A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
 * Implement the TicTacToe class:
 * TicTacToe(int n) Initializes the object the size of the board n.
 * int move(int row, int col, int player) Indicates that player with id player plays at the cell (row, col) of the
 * board. The move is guaranteed to be a valid move.
 * Follow up:
 * Could you do better than O(n2) per move() operation? */

#include <vector>

using std::vector;

class TicTacToe {
    vector<int> rows;
    vector<int> cols;
    int sz;
    int diagonal;
    int antiDiagonal;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        sz = n;
        rows = vector<int>(n);
        cols = vector<int>(n);
        diagonal = 0;
        antiDiagonal = 0;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int val = player == 1 ? 1 : -1;
        rows[row] += val;
        cols[col] += val;
        if (row == col) diagonal += val;
        if (row + col == sz - 1) antiDiagonal += val;
        if (abs(rows[row]) == sz || abs(cols[col]) == sz || abs(diagonal) == sz || abs(antiDiagonal) == sz) return player;

        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

