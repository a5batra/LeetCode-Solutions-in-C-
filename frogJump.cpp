//
// Created by Ankit Batra on 6/16/21.
//

/* A frog is crossing a river. The river is divided into some number of units, and at each unit,
 * there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.
 * Given a list of stones' positions (in units) in sorted ascending order,
 * determine if the frog can cross the river by landing on the last stone.
 * Initially, the frog is on the first stone and assumes the first jump must be 1 unit.
 * If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units.
 * The frog can only jump in the forward direction. */

class Solution {
    unordered_set<int> st;
    unordered_map<string, bool> memo;
public:
    bool helper(vector<int>& stones, int currIdx, int prevJump, int targetIndex) {
        if (currIdx == targetIndex) return true;

        string key = to_string(currIdx) + "*" + to_string(prevJump);

        if (memo.count(key)) return memo[key];

        for (int nextJump = prevJump - 1; nextJump <= prevJump + 1; ++nextJump) {
            if (nextJump <= 0 || st.count(currIdx + nextJump) == 0)
                continue;
            if (helper(stones, currIdx + nextJump, nextJump, targetIndex)) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }
    bool canCross(vector<int>& stones) {
        if (stones.size() <= 1) return true;
        if (stones[1] > 1) return false;

        int n = stones.size();

        for (int i = 0; i < n; ++i) st.insert(stones[i]);

        return helper(stones, 1, 1, stones[n-1]);
    }
};

