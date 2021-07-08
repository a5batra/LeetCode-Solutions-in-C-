//
// Created by Ankit Batra on 7/8/21.
//

// Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // return helper(nums1, 0, nums2, 0, 0);
        int m = nums1.size();
        int n = nums2.size();
        int ans = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};

