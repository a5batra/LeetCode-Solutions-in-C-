//
// Created by Ankit Batra on 10/13/20.
//

/* Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 * Find all the elements that appear twice in this array.
 * Could you do it without extra space and in O(n) runtime? */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) result.push_back(idx + 1);
            else nums[idx] = -nums[idx];
        }
        return result;
    }
};

int main() {
    int number;
    string line;
    vector<int> nums;
    vector<int> result;

    std::cout << "Enter the elements of array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        nums.push_back(number);

    result = Solution::findDuplicates(nums);

    std::cout << "Duplicate elements are: " << std::endl;

    for (int i = 0; i < result.size(); ++i)
        std::cout << result[i] << " ";


    return 0;
}

