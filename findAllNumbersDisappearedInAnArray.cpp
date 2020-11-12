//
// Created by Ankit Batra on 11/12/20.
//

/* Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * Could you do it without extra space and in O(n) runtime?
 * You may assume the returned list does not count as extra space. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        if (n == 0) return result;

        for (int i = 0; i < n; ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) nums[idx] = -nums[idx];
        }


        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) result.push_back(i + 1);
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

    result = Solution::findDisappearedNumbers(nums);

    std::cout << "All numbers disappeared in the array: " << std::endl;
    for (int i = 0; i < result.size(); ++i)
        std::cout << result[i] << " ";
    std::cout << std::endl;

    return 0;
}