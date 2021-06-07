//
// Created by Ankit Batra on 6/6/21.
//

/* You are given an array of integers stones where stones[i] is the weight of the ith stone.
 * We are playing a game with the stones. On each turn, we choose any two stones and smash them together.
 * Suppose the stones have weights x and y with x <= y. The result of this smash is:
 * If x == y, both stones are destroyed, and
 * If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
 * At the end of the game, there is at most one stone left.
 * Return the smallest possible weight of the left stone. If there are no stones left, return 0. */

class Solution {
    unordered_map<string, int> memo;
public:
    int helper(vector<int>& stones, int idx, int currSum) {
        string key = to_string(idx) + "*" + to_string(currSum);
        if (idx >= stones.size())
            return abs(currSum);

        if (memo.count(key)) return memo[key];

        int currAns = 0;

        currAns = helper(stones, idx + 1, currSum + stones[idx]);
        currAns = min(currAns, helper(stones, idx + 1, currSum - stones[idx]));

        return memo[key] = currAns;

    }
    int lastStoneWeightII(vector<int>& stones) {
        return helper(stones, 0, 0);
    }
};

