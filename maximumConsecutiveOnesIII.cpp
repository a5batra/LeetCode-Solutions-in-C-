//
// Created by Ankit Batra on 6/30/21.
//

/* Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if
 * you can flip at most k 0's. */

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;

        int numZeros = 0;
        int maxLen = 0;

        deque<int> dq;

        while (i < n) {
            if (nums[i] == 0) {
                dq.push_back(i);
            }
            if (dq.size() > k) {
                j = dq.front() + 1;
                dq.pop_front();
            }
            maxLen = max(maxLen, i - j + 1);
            i++;
        }

        return maxLen;
    }
};

