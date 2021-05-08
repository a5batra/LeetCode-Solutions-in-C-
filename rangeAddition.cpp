//
// Created by Ankit Batra on 5/8/21.
//

/* You are given an integer length and an array updates where updates[i] = [startIdxi, endIdxi, inci].
 * You have an array arr of length length with all zeros, and you have some operation to apply on arr.
 * In the ith operation, you should increment all the elements arr[startIdxi], arr[startIdxi + 1], ..., arr[endIdxi]
 * by inci.
 * Return arr after applying all the updates. */

#include <vector>

using std::vector;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length + 1);

        for (vector<int>& u : updates) {
            int startIdx = u[0], endIdx = u[1], inc = u[2];
            ans[startIdx] += inc;
            ans[endIdx + 1] -= inc;
        }

        for (int i = 1; i < length + 1; ++i) {
            ans[i] += ans[i - 1];
        }

        ans.pop_back();

        return ans;
    }
};

