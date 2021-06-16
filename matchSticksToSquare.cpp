//
// Created by Ankit Batra on 6/15/21.
//

/* You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick.
 * You want to use all the matchsticks to make one square. You should not break any stick,
 * but you can link them up, and each matchstick must be used exactly one time.
 * Return true if you can make this square and false otherwise. */

class Solution {
public:
    bool solve(vector<int>& matchsticks, int idx, vector<int>& sides) {
        if (idx == matchsticks.size())
            return sides[0] == 0 && sides[1] == 0 && sides[2] == 0 && sides[3] == 0;

        for (int i = 0; i < sides.size(); ++i) {
            if (matchsticks[idx] > sides[i]) continue;
            sides[i] -= matchsticks[idx];
            if (solve(matchsticks, idx + 1, sides)) return true;
            sides[i] += matchsticks[idx];
        }

        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int total = 0;

        for (int& m : matchsticks) total += m;

        if (total % 4 != 0) return false;

        int sideLen = total / 4;

        vector<int> sides(4, sideLen);

        sort(matchsticks.begin(), matchsticks.end(), greater<int>());

        return solve(matchsticks, 0, sides);

    }
};

