//
// Created by Ankit Batra on 4/9/21.
//

/* You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of
 * them is that adjacent houses have security systems connected and it will automatically contact the
 * police if two adjacent houses were broken into on the same night.
 * Given an integer array nums representing the amount of money of each house,
 * return the maximum amount of money you can rob tonight without alerting the police. */


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int curr = nums[0], prev = 0;

        for (int i = 2; i < n + 1; ++i) {
            int temp = curr;
            curr = max(curr, prev + nums[i - 1]);
            prev = temp;
        }

        return curr;
    }
};

int main() {
    return 0;
}