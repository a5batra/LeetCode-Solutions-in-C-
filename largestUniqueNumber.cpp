//
// Created by Ankit Batra on 5/1/21.
//

/* Given an array of integers A, return the largest integer that only occurs once.
 * If no integer occurs once, return -1. */

#include <vector>

using std::vector;

class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        vector<int> cnt(2000);
        for (int a : A)
            cnt[a]++;

        int ans = -1;

        for (int i = cnt.size() - 1; i >= 0; --i) {
            if (cnt[i] == 1) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

