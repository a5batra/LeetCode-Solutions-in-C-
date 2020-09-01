//
// Created by Ankit Batra on 9/1/20.
//

/* Given a string s, find the longest palindromic substring in s.
 * You may assume that the maximum length of s is 1000. */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";
        int startIdx = 0;
        int maxLen = 0;
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n - 1; ++i) {
            dp[i][i] = 1;
            if (s[i] == s[i + 1]) {
                startIdx = i;
                maxLen = 2;
                dp[i][i + 1] = 1;
            }
            else dp[i][i + 1] = 0;
        }
        dp[n - 1][n - 1] = 1;

        for (int k = 3; k <= n; ++k) {
            for (int i = 0; i < n - k + 1; ++i) {
                int j = i + k - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                    startIdx = i;
                    maxLen = j - i + 1;
                    dp[i][j] = 1;
                } else dp[i][j] = 0;
            }
        }
        return s.substr(startIdx, maxLen);
    }
};

int main() {
    string s;

    std::cout << "Enter the string s: " << std::endl;
    std::cin >> s;

    std::cout << "Longest Palindromic Substring: " << Solution::longestPalindrome(s);

    return 0;
}

