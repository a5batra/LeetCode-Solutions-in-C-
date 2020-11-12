//
// Created by Ankit Batra on 11/11/20.
//

/* Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
 * Only numbers 1 through 9 are used.
 * Each number is used at most once.
 * Return a list of all possible valid combinations.
 * The list must not contain the same combination twice, and the combinations may be returned in any order. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> result;
    vector<int> combination;
public:
    void backtrack(int idx, int target, int k) {
        if (target <= 0) {
            if (target == 0 && combination.size() == k) result.push_back(combination);
            return;
        }
        if (combination.size() > k) return;
        for (; idx < nums.size(); ++idx) {
            int val = nums[idx];
            combination.push_back(val);
            backtrack(idx + 1, target - val, k);
            combination.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(0, n, k);

        return result;
    }
};

int main() {
    int number;
    string line;
    int k, n;
    vector<vector<int>> result;

    std::cout << "Enter the value of k: " << std::endl;
    std::cin >> k;

    std::cout << "Enter the value of n: " << std::endl;
    std::cin >> n;

    Solution obj;
    result = obj.combinationSum3(k, n);

    std::cout << "Resulting combinations that make up the sum: " << std::endl;

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

