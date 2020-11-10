//
// Created by Ankit Batra on 11/9/20.
//

/* Given a set of distinct integers, nums, return all possible subsets (the power set).
 * Note: The solution set must not contain duplicate subsets. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
    vector<int> subset;
    vector<vector<int>> result;
public:
    void generateSubsets(vector<int>& nums, int idx, vector<int> subset) {
        result.push_back(subset);
        if (idx > nums.size() - 1) return;

        for (; idx < nums.size(); ++idx) {
            subset.push_back(nums[idx]);
            generateSubsets(nums, idx + 1, subset);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return result;

        generateSubsets(nums, 0, subset);

        return result;
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
