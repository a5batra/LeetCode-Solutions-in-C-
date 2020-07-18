//
// Created by Ankit Batra on 7/17/20.
//

/* Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
 * A region is captured by flipping all 'O's into 'X's in that surrounded region. */

#include <iostream>
#include <queue>
#include <vector>

using std::vector;
using std::pair;
using std::make_pair;
using std::queue;

class Solution {
public:
    // For debugging
    static void printBoard(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j)
                std::cout << board[i][j] << " ";
            std::cout << std::endl;
        }
    }
    static void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows == 0) return;
        int cols = board[0].size();
        vector<pair<int,int>> borderCells;

        for (int i = 0; i < rows; ++i) {
            borderCells.push_back(make_pair(i, 0));
            borderCells.push_back(make_pair(i, cols - 1));
        }

        for (int j = 1; j < cols; ++j) {
            borderCells.push_back(make_pair(0, j));
            borderCells.push_back(make_pair(rows - 1, j));
        }

        for (int k = 0; k < borderCells.size(); ++k)
            bfs(board, borderCells[k].first, borderCells[k].second);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'E')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }

    static void bfs(vector<vector<char>>& board, int row, int col) {
        int rows = board.size();
        int cols = board[0].size();

        queue<pair<int,int>> q;
        q.push(make_pair(row, col));

        while (!q.empty()) {
            pair<int,int> p = q.front();
            int r = p.first;
            int c = p.second;
            q.pop();
            if (board[r][c] != 'O') continue;

            board[r][c] = 'E';
            // Right
            if (c < cols - 1) q.push(make_pair(r, c + 1));
            // Down
            if (r < rows - 1) q.push(make_pair(r + 1, c));
            // Left
            if (c > 0) q.push(make_pair(r, c - 1));
            // Up
            if (r > 0) q.push(make_pair(r - 1, c));
        }
    }
};

int main() {
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};

    Solution::solve(board);
    Solution::printBoard(board);
    return 0;
}

