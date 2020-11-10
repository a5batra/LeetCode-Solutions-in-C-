//
// Created by Ankit Batra on 11/10/20.
//

/* Given a set of distinct integers, nums, return all possible subsets (the power set).
 * Note: The solution set must not contain duplicate subsets. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        int n = nums.size();
        if (n == 0) return allSubsets;

        int numSubsets = 1 << n;

        for (int subsetMask = 0; subsetMask < numSubsets; ++subsetMask) {
            vector<int> subset;
            for (int i = 0; i < n; ++i) {
                if ((subsetMask & (1 << i)) != 0) {
                    subset.push_back(nums[i]);
                }
            }
            allSubsets.push_back(subset);
        }
        return allSubsets;
    }
};

int main() {
    int number;
    string line;
    vector<int> nums;
    vector<vector<int>> result;

    std::cout << "Enter the elements of array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        nums.push_back(number);

    std::cout << "All possible subset of nums: " << std::endl;

    Solution obj;
    result = obj.subsets(nums);

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}