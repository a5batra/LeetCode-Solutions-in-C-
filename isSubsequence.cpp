//
// Created by Ankit Batra on 6/9/20.
//

/* Given a string s and a string t, check if s is subsequence of t.
 * A subsequence of a string is a new string which is formed from the original string by deleting some (can be none)
 * of the characters without disturbing the relative positions of the remaining characters.
 * (ie, "ace" is a subsequence of "abcde" while "aec" is not).
 * Follow up:
 * If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see
 * if T has its subsequence. In this scenario, how would you change your code? */

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    static bool isSubsequence(string s, string t) {
        int len1 = t.length();
        int len2 = s.length();
        int len = 0;
        int idx = 0;

        for (int i = 0; i < len2; ++i) {
            while (idx < len1) {
                if (t[idx++] == s[i]) {
                    len++;
                    break;
                }
            }
        }
        return len == len2 ? true : false;
    }
};

int main() {
    string s;
    string t;
    bool result;
    std::cout << "Enter string s. " << std::endl;
    std::cin >> s;

    std::cout << "Enter string t. " << std::endl;
    std::cin >> t;

    result = Solution::isSubsequence(s, t);

    if (result)
        std::cout << "string s is a subsequence of t. " << std::endl;
    else
        std::cout << "string s is not a subsequence of t. " << std::endl;

    return 0;
}

