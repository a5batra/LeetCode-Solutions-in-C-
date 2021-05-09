//
// Created by Ankit Batra on 5/9/21.
//

/* Given an array of strings wordsDict and two different strings that already exist in the array word1 and word2,
 * return the shortest distance between these two words in the list. */

#include <string>
#include <vector>

using std::min;
using std::string;
using std::vector;

class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int ans = INT_MAX;
        int n = wordsDict.size();
        int idx1 = -1, idx2 = -1;
        for (int i = 0; i < n; ++i) {
            string w = wordsDict[i];
            if (w == word1)
                idx1 = i;
            if (w == word2)
                idx2 = i;
            if (idx1 != -1 && idx2 != -1) ans = min(ans, abs(idx2 - idx1));
        }

        return ans;
    }
};

