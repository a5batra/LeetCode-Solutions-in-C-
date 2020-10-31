//
// Created by Ankit Batra on 10/31/20.
//

/* Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
 * Return the running sum of nums. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        if (n == 0) return result;

        result[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            result[i] = result[i - 1] + nums[i];
        }
        return result;
    }
};

int main() {
    string line;
    int number;
    vector<int> nums;
    vector<int> result;

    std::cout << "Enter the elements of array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        nums.push_back(number);


    result = Solution::runningSum(nums);
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }

    return 0;
}

