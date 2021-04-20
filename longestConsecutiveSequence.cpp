//
// Created by Ankit Batra on 4/19/21.
//

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> numSet;
        for (int num : nums) numSet.insert(num);

        int currAns = 0;
        int ans = 0;

        int idx = 0;
        while (idx < n) {
            if (numSet.count(nums[idx] - 1) > 0) {
                idx++;
                continue;
            }
            int num = nums[idx];
            while (numSet.count(num) > 0) {
                currAns++;
                num += 1;
            }
            ans = max(currAns, ans);
            currAns = 0;
            idx++;
        }

        return ans;
    }
};

int main() {
    return 0;
}

