//
// Created by Ankit Batra on 8/13/20.
//

/* Given an array nums of n integers where n > 1,
 * return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 * Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array
 * (including the whole array) fits in a 32 bit integer.
 * Note:
 * Please solve it without division and in O(n). */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static void printVector(vector<int>& vec) {
        int n = vec.size();

        for (int i = 0; i < n; ++i)
            std::cout << vec[i] << " ";
        std::cout << std::endl;
    }
    static vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        if (n == 0) return result;

        vector<int> leftProduct(n);
        vector<int> rightProduct(n);
        leftProduct[0] = 1;
        rightProduct[n - 1] = 1;

        for (int i = 1; i < n; ++i)
            leftProduct[i] = leftProduct[i - 1] * nums[i - 1];

        for (int j = n - 2; j >= 0; --j)
            rightProduct[j] = rightProduct[j + 1] * nums[j + 1];

        for (int i = 0; i < n; ++i)
            result[i] = leftProduct[i] * rightProduct[i];

        return result;
    }
};

int main() {
    int number;
    string line;
    vector<int> arr;
    vector<int> result;

    std::cout << "Enter the elements of array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        arr.push_back(number);

    std::cout << "Resulting array is: " << std::endl;
    result = Solution::productExceptSelf(arr);
    Solution::printVector(result);

    return 0;
}