//
// Created by Ankit Batra on 11/30/20.
//

/* You are given a list of non-negative integers, a1, a2, ..., an, and a target, S.
 * Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
 * Find out how many ways to assign symbols to make sum of integers equal to target S. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<vector<int>> state(n + 1, vector<int>(2001, INT_MIN));

        return dfs(nums, 0, 0, S, state);
    }

    static int dfs(vector<int>& nums, int idx, int sum, int S, vector<vector<int>>& state) {
        if (idx == nums.size()) {
            if (sum == S) return 1;
            else return 0;
        }
        if (idx > nums.size()) return 0;

        if (state[idx][sum + 1000] != INT_MIN) return state[idx][sum + 1000];

        int add = dfs(nums, idx + 1, sum + nums[idx], S, state);
        int diff = dfs(nums, idx + 1, sum - nums[idx], S, state);

        return state[idx][sum + 1000] = add + diff;
    }
};

int main() {
    int number;
    string line;
    vector<int> nums;

    std::cout << "Enter the elements of array nums separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        nums.push_back(number);

    int S;
    std::cout << "Enter the value of target, S: " << std::endl;
    std::cin >> S;

    std::cout << "Number of ways to form S: " << Solution::findTargetSumWays(nums, S);

    return 0;
}

