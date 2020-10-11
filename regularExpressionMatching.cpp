//
// Created by Ankit Batra on 10/10/20.
//

/* Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'
 * where:
 * '.' Matches any single character.​​​​
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial). */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static bool isMatch(string s, string p) {
        int strLen = s.length();
        int pattLen = p.length();

        vector<vector<bool>> dpTable(strLen + 1, vector<bool>(pattLen + 1));

        if (p[0] == '*') return false;

        dpTable[0][0] = true;
        for (int j = 1; j <= pattLen; ++j) {
            if (p[j - 1] == '*' && (j - 2 < 0 || dpTable[0][j - 2]) == true)
                dpTable[0][j] = true;
        }

        for (int i = 1; i <= strLen; ++i) {
            for (int j = 1; j <= pattLen; ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dpTable[i][j] = dpTable[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                        dpTable[i][j] = dpTable[i][j - 2] || dpTable[i - 1][j];
                    }
                    else {
                        dpTable[i][j] = dpTable[i][j - 2];
                    }
                }
            }
        }
        return dpTable[strLen][pattLen];
    }
};

int main() {
    string s;
    string p;

    std::cout << "Enter the string s: " << std::endl;
    std::cin >> s;
    std::cout << "Enter the pattern p: " << std::endl;
    std::cin >> p;

    std::cout << "Result: " << Solution::isMatch(s, p);
    return 0;
}
