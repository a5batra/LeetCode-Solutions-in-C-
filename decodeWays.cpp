//
// Created by Ankit Batra on 9/14/20.
//

/* A message containing letters from A-Z is being encoded to numbers using the following mapping:
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given a non-empty string containing only digits, determine the total number of ways to decode it. */

#include <iostream>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
    unordered_map<int, int> idxToWays;
public:
    int numDecodingsHelper(int idx, string s) {
        if (s[idx] == '0') return 0;
        if (idx == s.length() - 1 || idx == s.length()) return 1;
        if (idxToWays.find(idx) != idxToWays.end()) return idxToWays[idx];

        int ways = numDecodingsHelper(idx + 1, s);
        if (std::stoi(s.substr(idx, 2)) <= 26) {
            ways += numDecodingsHelper(idx + 2, s);
        }

        idxToWays[idx] = ways;

        return ways;
    }

    int numDecodings(string s) {
        if (s.length() == 0) return 0;

        return numDecodingsHelper(0, s);
    }
};

int main() {
    string s;

    std::cout << "Enter the string s: " << std::endl;
    std::cin >> s;

    Solution obj;

    std::cout << "Number of ways to decode the string: " << obj.numDecodings(s) << std::endl;

    return 0;
}