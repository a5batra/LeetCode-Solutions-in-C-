//
// Created by ankitb on 2/17/21.
//

// Given a string s, find the length of the longest substring without repeating characters.

#include <iostream>
#include <string>
#include <vector>

using std::max;
using std::string;
using std::vector;

class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        vector<int> charMap(256, 0);
        int i = 0, j = 0;

        int maxLen = -1;

        while (j < s.length()) {
            if (charMap[s[j]] != 0) {
                maxLen = max(maxLen, j - i);
                charMap[s[i]]--;
                i++;
            }
            else {
                charMap[s[j]]++;
                j++;
            }
        }

        return max(maxLen, j - i);
    }
};

int main() {
    string s;

    std::cout << "Enter the string s: " << std::endl;
    std::cin >> s;

    std::cout << "Length of longest substring without repeating characters: " << Solution::lengthOfLongestSubstring(s);
}
