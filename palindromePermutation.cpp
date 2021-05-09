//
// Created by Ankit Batra on 5/8/21.
//

// Given a string s, return true if a permutation of the string could form a palindrome.

#include <vector>

using std::vector;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        int len = s.length();
        vector<int> freq(26);

        for (char& c : s) freq[c - 'a']++;
        int oddFreq = 0;

        for (int f : freq) {
            if (f % 2 != 0) oddFreq++;
        }

        if (len % 2 == 0) {
            if (oddFreq == 0) return true;
            else return false;
        }
        else {
            if (oddFreq == 1) return true;
            else return false;
        }
    }
};

