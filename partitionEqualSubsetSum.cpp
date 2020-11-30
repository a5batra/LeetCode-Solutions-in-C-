//
// Created by Ankit Batra on 11/29/20.
//

/* Given a non-empty array nums containing only positive integers,
 * find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return false;

        int total = 0;
        for (int num : nums)
            total += num;

        if (total & 1) return false;

        vector<vector<int>> state(n + 1, vector<int>(total / 2 + 1, -1));

        return canPartitionHelper(nums, 0, 0, total, state);
    }

    static bool canPartitionHelper(vector<int>& nums, int idx, int sum, int total, vector<vector<int>>& state) {
        if (sum * 2 == total) return true;

        if (sum > total / 2 || idx >= nums.size()) return false;

        if (state[idx][sum] != -1) return state[idx][sum];

        bool found = canPartitionHelper(nums, idx + 1, sum, total, state) ||
                canPartitionHelper(nums, idx + 1, sum + nums[idx], total, state);

        return state[idx][sum] = found;
    }
};

int main() {
    int number;
    string line;
    vector<int> nums;

    std::cout << "Enter the elements of nums separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        nums.push_back(number);

    std::cout << "Result: " << Solution::canPartition(nums);

    return 0;
}

