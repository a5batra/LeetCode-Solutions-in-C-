//
// Created by Ankit Batra on 12/24/20.
//

// Given two strings s and t , write a function to determine if t is an anagram of s.

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static bool isAnagram(string s, string t) {
        vector<int> anagram(26);

        for (char c: s) {
            anagram[c - 'a'] += 1;
        }

        for (char c : t) {
            anagram[c - 'a'] -= 1;
        }

        for (int i = 0; i < 26; ++i) {
            if (anagram[i] != 0) return false;
        }

        return true;
    }
};

int main() {
    string s, t;

    std::cout << "Enter string s: " << std::endl;
    std::cin >> s;

    std::cout << "Enter string t: " << std::endl;
    std::cin >> t;

    std::cout << "Result: " << Solution::isAnagram(s, t);

    return 0;
}
