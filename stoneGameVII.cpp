//
// Created by Ankit Batra on 6/11/21.
//

/* Alice and Bob take turns playing a game, with Alice starting first.
 * There are n stones arranged in a row. On each player's turn, they can remove either the leftmost stone or the
 * rightmost stone from the row and receive points equal to the sum of the remaining stones' values in the row.
 * The winner is the one with the higher score when there are no stones left to remove.
 * Bob found that he will always lose this game (poor Bob, he always loses), so he decided to minimize the
 * score's difference. Alice's goal is to maximize the difference in the score.
 * Given an array of integers stones where stones[i] represents the value of the ith stone from the left,
 * return the difference in Alice and Bob's score if they both play optimally. */

class Solution {
public:
    int helper(vector<int>& stones, int start, int end, int total, vector<vector<int>>& memo) {
        if (start == end) return 0;
        if (end - start == 1) return max(stones[start], stones[end]);

        if (memo[start][end] != -1) return memo[start][end];

        int ans = 0;

        ans = max(total - stones[start] - helper(stones, start + 1, end, total - stones[start], memo), total - stones[end] - helper(stones, start, end - 1, total - stones[end], memo));

        return memo[start][end] = ans;
    }
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        int total = 0;

        for (int& s : stones) total += s;

        vector<vector<int>> memo(n, vector<int>(n, -1));

        return helper(stones, 0, n - 1, total, memo);
    }
};

