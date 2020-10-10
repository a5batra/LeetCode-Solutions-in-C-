//
// Created by Ankit Batra on 10/9/20.
//

/* Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "". */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int maxLen = INT_MAX;
        string longestPrefix = "";

        if (n == 0) return longestPrefix;

        int prefixLen = 0;

        for (int i = 0; i < n; ++i) {
            if (strs[i].length() < maxLen) {
                maxLen = strs[i].length();
            }
        }

        int low = 0;
        int high = maxLen;
        int midLen = 0;

        while (low <= high) {
            midLen = low + (high - low) / 2;
            if (isCommonPrefix(strs, midLen)) {
                prefixLen = midLen;
                low = midLen + 1;
            }
            else high = midLen - 1;
        }

        longestPrefix = strs[0].substr(0, prefixLen);

        return longestPrefix;
    }
    static bool isCommonPrefix(vector<string>& strs, int len) {
        int n = strs.size();

        string toCheck = strs[0].substr(0, len);

        for (int i = 1; i < n; ++i) {
            if (strs[i].substr(0, len) != toCheck) return false;
        }
        return true;
    }
};

int main() {
    string str;
    string line;
    string longestPrefix = "";
    vector<string> strs;

    std::cout << "Enter the strings separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> str)
        strs.push_back(str);

    longestPrefix = Solution::longestCommonPrefix(strs);

    std::cout << "Longest Common Prefix: " << longestPrefix;


    return 0;
}
