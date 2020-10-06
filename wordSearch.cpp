//
// Created by Ankit Batra on 10/1/20.
//

/* Given a 2D board and a word, find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those
 * horizontally or vertically neighboring. The same letter cell may not be used more than once. */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static bool dfs(int row, int col, int idx, vector<vector<char>>& board, string word) {
        if (idx == word.length()) return true;

        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[idx])
            return false;

        char temp = board[row][col];
        board[row][col] = '\0';

        if (dfs(row, col + 1, idx + 1, board, word) || dfs(row + 1, col, idx + 1, board, word) ||
        dfs(row, col - 1, idx + 1, board, word) || dfs(row - 1, col, idx + 1, board, word))
            return true;

        board[row][col] = temp;

        return false;

    }
    static bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (board[row][col] == word[0] && dfs(row, col, 0, board, word))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board = {{'A','B','C','E'},
                                  {'S','F','C','S'},
                                  {'A','D','E','E'}};
    string word;

    std::cout << "Enter the word to search: " << std::endl;
    std::cin >> word;

    std::cout << "Result: " << Solution::exist(board, word);

    return 0;
}
