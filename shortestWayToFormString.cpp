//
// Created by Ankit Batra on 12/17/20.
//

/* From any string, we can form a subsequence of that string by deleting some number of characters
 * (possibly no deletions).
 * Given two strings source and target,
 * return the minimum number of subsequences of source such that their concatenation equals target.
 * If the task is impossible, return -1. */

#include <iostream>
#include <string>
#include <unordered_set>

using std::string;
using std::unordered_set;

class Solution {
public:
    static int shortestWay(string source, string target) {
        int srcLen = source.length(), tarLen = target.length();

        unordered_set<char> srcSet;
        for (char c : source) srcSet.insert(c);
        for (char c: target) {
            if (srcSet.find(c) == srcSet.end()) return -1;
        }
        int minNum = 1;

        int i = 0, j = 0;
        while (j < tarLen) {
            if (source[i] == target[j]) {
                i++;
                j++;
            }
            else {
                if (i != srcLen - 1 && i < srcLen) i++;
                else {
                    i = 0;
                    minNum++;
                }
            }
        }
        return minNum;
    }
};

int main() {
    string source, target;

    std::cout << "Enter source string: " << std::endl;
    std::cin >> source;

    std::cout << "Enter target string: " << std::endl;
    std::cin >> target;

    std::cout << "Minimum number of subsequences: " << Solution::shortestWay(source, target);

    return 0;
}