//
// Created by Ankit Batra on 6/11/20.
//

/* Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color
 * are adjacent, with the colors in the order red, white and blue.
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 * Note: You are not suppose to use the library's sort function for this problem. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static void swap(int& num1, int& num2) {
        int temp = num2;
        num2 = num1;
        num1 = temp;
    }
    static void printVector(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            std::cout << nums[i] << " ";

    }
    static void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0;
        int p2 = n - 1;
        int curr = 0;
        int temp = 0;

        while (curr <= p2) {
            if (nums[curr] == 0) {
                swap(nums[curr], nums[p0]);
                curr++;
                p0++;
            }
            else if (nums[curr] == 1) curr++;
            else  {
                swap(nums[curr], nums[p2]);
                p2--;
            }
        }
    }
};

int main() {
    int number;
    string line;
    vector<int> nums;

    std::cout << "Enter the elements of array. " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        nums.push_back(number);

    Solution::sortColors(nums);

    std::cout << "After sorting the array: " << std::endl;
    Solution::printVector(nums);

    return 0;
}

