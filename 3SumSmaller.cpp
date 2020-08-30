//
// Created by Ankit Batra on 8/30/20.
//

/* Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n
 * that satisfy the condition nums[i] + nums[j] + nums[k] < target. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static int twoSumSmaller(vector<int>& nums, int startIdx, int target) {
        int n = nums.size();
        int low = startIdx;
        int high = n - 1;
        int sum = 0;

        while (low < high) {
            if (nums[low] + nums[high] < target) {
                sum += high - low;
                low++;
            }
            else high--;
        }
        return sum;
    }
    static int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        int numTriplets = 0;
        if (n == 0) return numTriplets;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            numTriplets += twoSumSmaller(nums, i + 1, target - nums[i]);
        }
        return numTriplets;
    }
};

int main() {
    int number;
    string line;
    vector<int> nums;
    int target;

    std::cout << "Enter the elements of array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        nums.push_back(number);

    std::cout << "Enter the target value: " << std::endl;
    std::cin >> target;

    std::cout << "Number of triplets whose sum is less than target: " << Solution::threeSumSmaller(nums, target);

    return 0;
}

