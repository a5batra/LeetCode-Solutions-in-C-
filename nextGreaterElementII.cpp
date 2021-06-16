//
// Created by Ankit Batra on 6/16/21.
//

/* Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]),
 * return the next greater number for every element in nums.
 * The next greater number of a number x is the first greater number to its traversing-order next in the array,
 * which means you could search circularly to find its next greater number.
 * If it doesn't exist, return -1 for this number. */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return vector<int>();

        vector<int> ans(n, -1);

        stack<int> st;

        for (int i = 0; i < 2 * n; ++i) {
            while (!st.empty() && nums[i % n] > nums[st.top()]) {
                ans[st.top()] = nums[i % n];
                st.pop();
            }
            st.push(i % n);
        }

        return ans;

    }
};

