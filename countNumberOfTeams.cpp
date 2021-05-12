//
// Created by Ankit Batra on 5/12/21.
//

/* There are n soldiers standing in a line. Each soldier is assigned a unique rating value.
 * You have to form a team of 3 soldiers amongst them under the following rules:
 * Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
 * A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k])
 * where (0 <= i < j < k < n).
 * Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams). */

#include <vector>

using std::vector;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        int n = rating.size();

        for (int i = 1; i < n - 1; ++i) {
            int leftLesser = 0, rightGreater = 0;
            int leftGreater = 0, rightLesser = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (rating[j] > rating[i]) leftGreater++;
                else leftLesser++;
            }
            for (int j = i + 1; j < n; ++j) {
                if (rating[j] > rating[i]) rightGreater++;
                else rightLesser++;
            }
            ans += (leftLesser * rightGreater) + (leftGreater * rightLesser);
        }

        return ans;
    }
};

