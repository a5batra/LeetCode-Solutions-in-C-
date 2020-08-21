//
// Created by ankitb on 8/20/20.
//

#include <iostream>
#include <string>
#include <unordered_set>

using std::string;
using std::max;
using std::unordered_set;

class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int maxLen = 0;
        unordered_set<char> charSet;
        int i = 0;
        int j = 0;

        while (i < len && j < len) {
            if (charSet.find(s[j]) == charSet.end()) {
                charSet.insert(s[j]);
                j++;
                maxLen = max(maxLen, j - i);
            }
            else {
                charSet.erase(s[i]);
                i++;
            }
        }
        return maxLen;
    }
};

int main() {
    string s;

    std::cout << "Enter the string s: " << std::endl;
    std::cin >> s;

    std::cout << "Length of longest substring without repeating characters: " << Solution::lengthOfLongestSubstring(s);
}

