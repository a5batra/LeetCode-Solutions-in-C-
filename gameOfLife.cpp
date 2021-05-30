//
// Created by Ankit Batra on 5/30/21.
//

/* According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised
 * by the British mathematician John Horton Conway in 1970."
 * The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1)
 * or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal)
 * using the following four rules (taken from the above Wikipedia article):
 * Any live cell with fewer than two live neighbors dies as if caused by under-population.
 * Any live cell with two or three live neighbors lives on to the next generation.
 * Any live cell with more than three live neighbors dies, as if by over-population.
 * Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
 * The next state is created by applying the above rules simultaneously to every cell in the current state,
 * where births and deaths occur simultaneously.
 * Given the current state of the m x n grid board, return the next state. */

// die -> live : -1
// live -> die : 2
class Solution {
    vector<vector<int>> dirs;
public:
    Solution() {
        dirs = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    }
    int getLiveNeighbors(vector<vector<int>>& board, int r, int c) {
        int numLive = 0;
        for (int k = 0; k < 8; ++k) {
            int nr = r + dirs[k][0];
            int nc = c + dirs[k][1];
            if (nr < 0 || nr >= board.size() || nc < 0 || nc >= board[0].size())
                continue;
            if (board[nr][nc] == 1 || board[nr][nc] == 2) numLive++;
        }
        return numLive;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == 1) {
                    int count = getLiveNeighbors(board, r, c);
                    if (count < 2) board[r][c] = 2;
                    else if (count == 2 || count == 3) board[r][c] = 1;
                    else board[r][c] = 2;
                }
                else {
                    int count = getLiveNeighbors(board, r, c);
                    if (count == 3) board[r][c] = -1;
                }
            }
        }

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == -1) board[r][c] = 1;
                else if (board[r][c] == 2) board[r][c] = 0;
            }
        }

    }
};

