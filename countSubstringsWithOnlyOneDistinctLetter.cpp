//
// Created by Ankit Batra on 4/24/21.
//

// Given a string S, return the number of substrings that have only one distinct letter.

#include <string>

using std::string;

class Solution {
public:
    int countLetters(string S) {
        int len = S.length();
        if (len == 0 || len == 1) return len;

        int n = 1;
        int ans = 0;
        for (int i = 1; i < len; ++i) {
            if (S[i] != S[i - 1]) {
                ans += (n * (n + 1)) / 2;
                n = 1;
            }
            else n++;
        }

        ans += (n * (n + 1)) / 2;

        return ans;
    }
};

