//
// Created by Ankit Batra on 7/16/21.
//

/* Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c],
 * nums[d]] such that:
 * 0 <= a, b, c, d < n
 * a, b, c, and d are distinct.
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 * You may return the answer in any order. */

class Solution {
    vector<vector<int>> ans;
public:
    void findQuadruplets(vector<int>& nums, int i, int val) {
        int n = nums.size();
        for (int j = i + 1; j < n - 2; ++j) {
            if (j != i + 1 && nums[j] == nums[j - 1]) continue;
            int low = j + 1, high = n - 1;
            while (low < high) {
                if (nums[j] + nums[low] + nums[high] < val) low++;
                else if (nums[j] + nums[low] + nums[high] > val) high--;
                else {
                    ans.push_back({nums[i], nums[j], nums[low], nums[high]});
                    low++;
                    high--;
                    while (low < high && nums[low] == nums[low - 1]) {
                        low++;
                    }
                }
            }
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) return ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            int val = target - nums[i];
            findQuadruplets(nums, i, val);
        }

        return ans;
    }
};

