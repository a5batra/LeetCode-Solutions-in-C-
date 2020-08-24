//
// Created by Ankit Batra on 8/22/20.
//

/* Given an unsorted array of integers, find the length of longest increasing subsequence.
 * Note:
 * There may be more than one LIS combination, it is only necessary for you to return the length.
 * Your algorithm should run in O(n2) complexity. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return n;

        vector<int> dp(n, 1);
        int lengthLIS = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[i] < dp[j] + 1)
                        dp[i] = dp[j] + 1;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (dp[i] > lengthLIS)
                lengthLIS = dp[i];
        }

        return lengthLIS;
    }
};


int main() {
    int number;
    string line;
    vector<int> nums;

    std::cout << "Enter the elements of array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        nums.push_back(number);

    std::cout << "Length of longest increasing subsequence: " << Solution::lengthOfLIS(nums);

    return 0;
}

