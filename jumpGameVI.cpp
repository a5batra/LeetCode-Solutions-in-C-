//
// Created by Ankit Batra on 6/9/21.
//

/* You are given a 0-indexed integer array nums and an integer k.
 * You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside
 * the boundaries of the array. That is, you can jump from index i to any index in the range
 * [i + 1, min(n - 1, i + k)] inclusive.
 * You want to reach the last index of the array (index n - 1).
 * Your score is the sum of all nums[j] for each index j you visited in the array.
 * Return the maximum score you can get. */

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        vector<int> dp(n);
        dp[0] = nums[0];
        pq.push({dp[0], 0});

        for (int i = 1; i < n; ++i) {
            while (!pq.empty() && pq.top().second + k < i) {
                pq.pop();
            }
            dp[i] = nums[i] + pq.top().first;
            pq.push({dp[i], i});
        }

        return dp[n - 1];
    }
};

