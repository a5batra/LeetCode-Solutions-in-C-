//
// Created by Ankit Batra on 8/24/20.
//

/* Given an array of integers and an integer k,
 * you need to find the total number of continuous subarrays whose sum equals to k. */

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
    static int subarraySum(vector<int>& nums, int k) {
        int numArrays = 0;
        int n = nums.size();

        if (n == 0) return numArrays;
        unordered_map<int, int> sumToCount;
        sumToCount[0] = 1;
        int cumSum = 0;

        for (int i = 0; i < n; ++i) {
            cumSum += nums[i];
            if (sumToCount.find(cumSum - k) != sumToCount.end())
                numArrays += sumToCount[cumSum - k];
            if (sumToCount.find(cumSum) == sumToCount.end())
                sumToCount[cumSum] = 1;
            else
                sumToCount[cumSum] += 1;
        }

        return numArrays;
    }
};

int main() {
    int number;
    string line;
    vector<int> nums;
    int k;

    std::cout << "Enter the elements of array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        nums.push_back(number);

    std::cout << "Enter the value of k: " << std::endl;
    std::cin >> k;

    std::cout << "Number of subarrays whose sum equal k: " << Solution::subarraySum(nums, k) << std::endl;
    return 0;
}