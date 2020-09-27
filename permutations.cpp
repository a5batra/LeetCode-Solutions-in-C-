//
// Created by Ankit Batra on 9/26/20.
//

// Given a collection of distinct integers, return all possible permutations.

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
    vector<vector<int>> result;
    vector<int> visitedSet;
public:
    vector<int> constructVec(vector<int>& nums, int idx) {
        vector<int> vec;

        for (int i = 0; i < nums.size(); ++i) {
            if (i == idx) continue;
            vec.push_back(nums[i]);
        }
        return vec;
    }
    void permuteHelper(vector<int>& nums) {
        if (nums.size() == 0) result.push_back(visitedSet);

        for (int i = 0; i < nums.size(); ++i) {
            visitedSet.push_back(nums[i]);
            vector<int> vec = constructVec(nums, i);
            permute(vec);
            visitedSet.pop_back();
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        permuteHelper(nums);

        return result;
    }

};

int main() {
    int number;
    string line;
    vector<int> nums;\
    vector<vector<int>> result;

    std::cout << "Enter the elements of array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        nums.push_back(number);

    Solution obj;
    result = obj.permute(nums);

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[0].size(); ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
