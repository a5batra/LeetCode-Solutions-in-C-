//
// Created by Ankit Batra on 11/10/20.
//

/* Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
 * Note: The solution set must not contain duplicate subsets. */

#include <iostream>
#include <set>
#include <sstream>
#include <vector>

using std::set;
using std::string;
using std::vector;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n == 0) return result;

        int numSubsets = 1 << n;
        set<vector<int>> allSubsets;

        for (int subsetMask = 0; subsetMask < numSubsets; ++subsetMask) {
            vector<int> subset;
            for (int i = 0; i < n; ++i) {
                if ((subsetMask & (1 << i)) != 0) {
                    subset.push_back(nums[i]);
                }
            }
            sort(subset.begin(), subset.end());
            allSubsets.insert(subset);
        }

        for (auto it = allSubsets.begin(); it != allSubsets.end(); ++it) {
            result.push_back(*it);
        }

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
    result = obj.subsetsWithDup(nums);

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

