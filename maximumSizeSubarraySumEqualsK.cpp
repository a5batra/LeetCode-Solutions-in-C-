//
// Created by Ankit Batra on 12/15/20.
//

/* Given an array nums and a target value k, find the maximum length of a subarray that sums to k.
 * If there isn't one, return 0 instead.
 * Note:
 * The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range. */

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using std::max;
using std::unordered_map;
using std::string;
using std::vector;

class Solution {
public:
    static int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;

        int maxLen = 0;

        unordered_map<int, int> prefixSum;

        int currSum = 0;

        for (int i = 0; i < n; ++i) {
            currSum += nums[i];
            if (currSum - k == 0) {
                maxLen = max(maxLen, i + 1);
            }
            if (prefixSum.find(currSum - k) != prefixSum.end()) {
                maxLen = max(maxLen, i - prefixSum[currSum - k]);
            }
            if (prefixSum.find(currSum) == prefixSum.end())
                prefixSum[currSum] = i;
        }

        return maxLen;
    }
};

int main() {
    int number, k;
    string line;
    vector<int> nums;

    std::cout << "Enter the elements of array: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        nums.push_back(number);

    std::cout << "Enter the value of k: " << std::endl;
    std::cin >> k;

    std::cout << "Maximum size subarray length: " << Solution::maxSubArrayLen(nums, k);

    return 0;
}

