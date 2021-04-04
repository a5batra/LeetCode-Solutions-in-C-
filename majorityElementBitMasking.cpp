//
// Created by ankitb on 4/3/21.
//

/* Given an array of size n, find the majority element.
 * The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 * You may assume that the array is non-empty and the majority element always exist in the array. */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int len = sizeof(int) * 8;
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (nums[j] & (1 << i))
                    count += 1;
            }
            if (count > n / 2) {
                ans += (1 << i);
            }
        }
        return ans;
    }
};
