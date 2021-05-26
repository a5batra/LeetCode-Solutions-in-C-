//
// Created by ankitb on 5/26/21.
//

/* Given an m x n picture consisting of black 'B' and white 'W' pixels, return the number of black lonely pixels.
 * A black lonely pixel is a character 'B' that located at a specific position where the same row and same column
 * don't have any other black pixels. */

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size();
        int n = picture[0].size();
        vector<int> rows(m);
        vector<int> cols(n);
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B' && rows[i] == 1 && cols[j] == 1) ans += 1;
            }
        }

        return ans;
    }
};