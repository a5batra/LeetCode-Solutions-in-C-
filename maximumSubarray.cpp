//
// Created by Ankit Batra on 4/4/20.
//

/* Given an integer array nums, find the contiguous subarray (containing at least one number)
 * which has the largest sum and return its sum.
 * Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer
 * approach, which is more subtle.
*/

#include <iostream>
#include <sstream>
#include <vector>

class Solution {
public:
    static bool allNegative(std::vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (nums[i] >= 0)
                return false;
        }
        return true;
    }
    static int maxSubArray(std::vector<int>& nums) {
        int len = nums.size();
        int ans = INT_MIN;
        std::vector<int> runningSum(len);

        if(allNegative(nums)) {
            for(int i = 0; i < len; ++i) {
                if (nums[i] > ans) {
                    ans = nums[i];
                }
            }
            return ans;
        }

        runningSum[0] = nums[0];
        for (int i =1; i < len; ++i) {
            if (runningSum[i-1] + nums[i] <= 0)
                runningSum[i] = std::max(0, nums[i]);
            else
                runningSum[i] = std::max(runningSum[i-1] + nums[i], nums[i]);
        }

        for(int i = 0; i < len; ++i) {
            if (runningSum[i] > ans)
                ans = runningSum[i];
        }
        return ans;
    }
};

int main() {
    int number;
    std::string line;
    std::vector<int> nums;

    std::cout << "Enter the elements of the integer array separated by space. " << std::endl;
    std::getline(std::cin, line);
    std::istringstream stream(line);

    while (stream >> number)
        nums.push_back(number);

    std::cout << "The largest sum of the contiguous array is: " << Solution::maxSubArray(nums);

    return 0;
}

