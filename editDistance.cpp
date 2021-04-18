//
// Created by Ankit Batra on 4/18/21.
//

/* Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
 * You have the following three operations permitted on a word:
 * Insert a character
 * Delete a character
 * Replace a character */

#include <string>
#include <vector>

using std::min;
using std::string;
using std::vector;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        vector<vector<int>> dp(n2 + 1, vector<int>(n1 + 1));

        int ans = 0;

        for (int j = 1; j < n1 + 1; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i < n2 + 1; ++i) {
            dp[i][0] = i;
        }

        for (int i = 1; i < n2 + 1; ++i) {
            for (int j = 1; j < n1 + 1; ++j) {
                if (word2[i - 1] == word1[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(1 + dp[i - 1][j - 1], min(1 + dp[i][j - 1], 1 + dp[i - 1][j]));
                }
            }
        }

        ans = dp[n2][n1];

        return ans;
    }
};

int main() {
    return 0;
}