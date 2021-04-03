//
// Created by Ankit Batra on 4/2/21.
//

/* Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n. */

#include <iostream>
#include <unordered_map>
#include <vector>

using std::min;
using std::unordered_map;
using std::vector;

class Solution {
    unordered_map<int, int> dict;
public:
    int backtrack(int n, int idx, vector<int>& nums) {
        if (n <= 0) {
            return n == 0 ? 0 : 10000;
        }
        if (dict.count(n) != 0) return dict[n];

        int sz = 10000;
        for (int j = idx; j < nums.size(); ++j) {
            sz = min(sz, 1 + backtrack(n - nums[j], j, nums));
        }
        return dict[n] = sz;
    }
    int numSquares(int n) {
        vector<int> nums;

        for (int i = 1; i * i <= n; ++i) {
            nums.push_back(i * i);
        }

        return backtrack(n, 0, nums);
    }
};