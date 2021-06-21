//
// Created by Ankit Batra on 6/21/21.
//

/* Given the array houses and an integer k. where houses[i] is the location of the ith house along a street,
 * your task is to allocate k mailboxes in the street.
 * Return the minimum total distance between each house and its nearest mailbox.
 * The answer is guaranteed to fit in a 32-bit signed integer. */

class Solution {
    int minDist;
public:
    Solution() {
        minDist = INT_MAX;
    }
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());

        vector<vector<int>> memo(100, vector<int>(100, -1));
        return helper(houses, 0, k, memo);

    }

    int helper(vector<int>& houses, int idx, int k, vector<vector<int>>& memo) {
        if (k == 1) {
            int medianIdx = (idx + houses.size() - 1) / 2;
            int d = 0;
            while (idx < houses.size()) {
                d += abs(houses[medianIdx] - houses[idx]);
                idx++;
            }
            return d;
        }

        if (memo[idx][k] != -1) return memo[idx][k];

        int minD = 1e9;

        for (int i = idx; i < houses.size() - k + 1; ++i) {
            int dist = 0;
            int medIdx = (idx + i) / 2;
            for (int j = idx; j <= i; ++j) {
                dist += abs(houses[medIdx] - houses[j]);
            }
            minD = min(minD, dist + helper(houses, i + 1, k - 1, memo));
        }

        return memo[idx][k] = minD;
    }
};

