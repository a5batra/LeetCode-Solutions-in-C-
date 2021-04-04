//
// Created by Ankit Batra on 4/4/21.
//

/* Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Your goal is to reach the last index in the minimum number of jumps.
 * You can assume that you can always reach the last index. */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1000);
        dp[n - 1] = 0;
        return solve(nums, 0, dp);
    }

    int solve(vector<int>& nums, int idx, vector<int>& dp) {
        if (idx >= nums.size() - 1) return 0;

        if (dp[idx] != 1000) return dp[ix];

        int jumps = 1000;
        for (int i = idx + 1; i <= idx + nums[idx]; ++i) {
            jumps = std::min(jumps, 1 + solve(nums, i, dp));
        }

        return dp[idx] = jumps;
    }
};

int main() {
    return 0;
}