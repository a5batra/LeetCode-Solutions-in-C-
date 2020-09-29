//
// Created by Ankit Batra on 9/28/20.
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
        vector<int> result;
        int maxIdx = -1;
        string partition = "";

        for (int i = 0; i < S.length(); ++i)
            lastIdx[S[i]] = i;

        int idx = 0;
        while (idx < S.length()) {
            maxIdx = std::max(maxIdx, lastIdx[S[idx]]);
            if (idx == maxIdx) {
                partition += S[idx];
                result.push_back(partition.length());
                partition = "";
                idx++;
                continue;
            }
            partition += S[idx];
            idx++;
        }
        return result;
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


