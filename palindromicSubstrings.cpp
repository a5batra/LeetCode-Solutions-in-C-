//
// Created by Ankit Batra on 12/1/20.
//

/* Given a string, your task is to count how many palindromic substrings in this string.
 * The substrings with different start indexes or end indexes are counted as different substrings
 * even they consist of same characters. */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static int countSubstrings(string s) {
        int n = s.length();
        if (n == 0) return 0;

        int num = 0;

        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
            num++;
        }

        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                num++;
            }
        }

        for (int k = 3; k <= n; ++k) {
            for (int i = 0; i < n - k + 1; ++i) {
                int j = i + k - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                    dp[i][j] = 1;
                    num++;
                }
            }
        }

        return num;
    }
};

int main() {
    string s;

    std::cout << "Enter the string s: " << std::endl;
    std::cin >> s;

    std::cout << "Number of palindromic substrings: " << Solution::countSubstrings(s);

    return 0;
}