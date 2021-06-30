//
// Created by Ankit Batra on 6/29/21.
//

/* Given a binary array nums, return the maximum number of consecutive 1's in the array if
 * you can flip at most one 0. */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int prevZeroIdx = -1;

        int currAns = 0;
        int ans = 0;

        int i = 0, j = 0;

        while (i < n) {
            if (nums[i] == 0) {
                if (prevZeroIdx != -1) {
                    ans = max(ans, currAns);
                    currAns = i - prevZeroIdx;
                    prevZeroIdx = i;
                    i++;
                }
                else {
                    prevZeroIdx = i;
                    currAns++;
                    i++;
                }
            }
            else {
                currAns++;
                i++;
            }
        }

        ans = max(ans, currAns);

        return ans;
    }
};

