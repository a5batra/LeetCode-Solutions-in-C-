//
// Created by ankitb on 5/26/21.
//

/* Given an m x n picture consisting of black 'B' and white 'W' pixels, return the number of black lonely pixels.
 * A black lonely pixel is a character 'B' that located at a specific position where the same row and same column
 * don't have any other black pixels. */

#include <vector>

using std::pair;
using std::vector;

class Solution {
    int ans;
    vector<pair<int, int>> blackPixels;
    vector<vector<int>> directions;
public:
    Solution() {
        ans = 0;
        directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    }
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size();
        int n = picture[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    blackPixels.push_back({i, j});
                }
            }
        }

        for (auto b : blackPixels) {
            if (dfs(picture, b.first, b.second + 1, directions[0]) && dfs(picture, b.first + 1, b.second, directions[1]) && dfs(picture, b.first, b.second - 1, directions[2]) && dfs(picture, b.first - 1, b.second, directions[3])) {
                ans += 1;
            }
        }
        return ans;
    }

    bool dfs(vector<vector<char>>& picture, int row, int col, vector<int>& dir) {
        if (row >= picture.size() || col >= picture[0].size() || row < 0 || col < 0) return true;
        if (picture[row][col] == 'B') return false;

        return dfs(picture, row + dir[0], col + dir[1],  dir);
    }
};