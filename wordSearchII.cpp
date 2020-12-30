//
// Created by Ankit Batra on 12/30/20.
//

/* Given an m x n board of characters and a list of strings words, return all words on the board.
 * Each word must be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring.
 * The same letter cell may not be used more than once in a word. */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
    vector<string> result;
    struct TrieNode {
        char c;
        int endsHere;
        TrieNode* child[26];
        string word;
    };
    TrieNode* getNode(int idx) {
        TrieNode* node = new TrieNode;
        node->c = idx + 'a';
        node->endsHere = 0;
        for (int i = 0; i < 26; ++i) {
            node->child[i] = nullptr;
        }
        return node;
    }
    TrieNode* root = getNode('/' - 'a');
public:
    void insert(string word) {
        TrieNode* curr = root;
        int idx = 0;
        for (char c : word) {
            idx = c - 'a';
            if (curr->child[idx] == nullptr) curr->child[idx] = getNode(idx);
            curr = curr->child[idx];
        }
        curr->endsHere += 1;
        curr->word = word;
    }
    void solve(vector<vector<char>>& board, int i, int j, int r, int c, TrieNode* curr) {
        if (i < 0 || i >= r || j < 0 || j >= c || board[i][j] == '\0') return;

        int idx = board[i][j] - 'a';
        if (curr->child[idx] == nullptr) return;

        char val = board[i][j];
        board[i][j] = '\0';
        curr = curr->child[idx];
        if (curr->endsHere > 0) {
            result.push_back(curr->word);
            curr->endsHere -= 1;
        }

        solve(board, i, j + 1, r, c, curr);
        solve(board, i + 1, j, r, c, curr);
        solve(board, i, j - 1, r, c, curr);
        solve(board, i - 1, j, r, c, curr);

        board[i][j] = val;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int rows = board.size();
        if (rows == 0) return result;
        int cols = board[0].size();

        for (string word : words) insert(word);

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                solve(board, row, col, rows, cols, root);
            }
        }
        return result;
    }
};

int main() {
    return 0;
}

