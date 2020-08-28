//
// Created by Ankit Batra on 8/25/20.
//

/* Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero. Note:
 * The solution set must not contain duplicate triplets. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static void printVectorOfVectors(vector<vector<int>>& result) {
        int n = result.size();
        int m = result[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout << result[i][j] <<  " ";
            }
            std::cout << std::endl;
        }
    }
    static vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        if (n == 0) return result;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int currNum = nums[i];
                int start = i + 1;
                int end = n - 1;
                while (start < end) {
                    if (currNum + nums[start] + nums[end] == 0) {
                        result.push_back({currNum, nums[start], nums[end]});
                        int currStart = start;
                        while (nums[start] == nums[currStart] && start < end)
                            start++;
                    }
                    else if(currNum + nums[start] + nums[end] > 0) {
                        end--;
                    } else start++;

                }
            }
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

    result = Solution::threeSum(nums);

    std::cout << "Resulting triplets: " << std::endl;
    Solution::printVectorOfVectors(result);

    return 0;
}
