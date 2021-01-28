//
// Created by ankitb on 1/27/21.
//

/* A string S of lowercase English letters is given.
 * We want to partition this string into as many parts as possible so that each letter appears in at most one part,
 * and return a list of integers representing the size of these parts. */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
    static vector<int> partitionLabels(string S) {
        unordered_map<char, int> lastIdx;
        vector<int> partition;
        for (int i = 0; i < S.length(); ++i)
            lastIdx[S[i]] = i;

        int j = 0;
        int i = 0;
        int maxIdx = 0;
        while (j < S.length()) {
            maxIdx = max(maxIdx, lastIdx[S[j]]);
            if (j == maxIdx) {
                partition.push_back(j - i + 1);
                i = j + 1;
            }
            j++;
        }

        return partition;

    }
};

int main() {
    string S;
    vector<int> result;

    std::cout << "Enter the string: " << std::endl;
    std::cin >> S;

    std::cout << "Size of partitions: " << std::endl;
    result = Solution::partitionLabels(S);

    for (int i = 0; i < result.size(); ++i)
        std::cout << result[i] << " ";


    return 0;
}