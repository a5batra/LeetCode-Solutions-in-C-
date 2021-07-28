//
// Created by Ankit Batra on 7/28/21.
//

/* For some fixed n, an array nums is beautiful if it is a permutation of the integers 1, 2, ..., n, such that:
 * For every i < j, there is no k with i < k < j such that nums[k] * 2 = nums[i] + nums[j].
 * Given n, return any beautiful array nums.  (It is guaranteed that one exists.) */

class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans;
        ans.push_back(1);

        while (ans.size() < n) {
            vector<int> temp;
            for (int i = 0; i < ans.size(); ++i) {
                if (2 * ans[i] - 1 <= n) {
                    temp.push_back(2 * ans[i] - 1);
                }
            }
            for (int i = 0; i < ans.size(); ++i) {
                if (2 * ans[i] <= n) {
                    temp.push_back(2 * ans[i]);
                }
            }
            ans = temp;
        }

        return ans;
    }
};

