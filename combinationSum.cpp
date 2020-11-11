//
// Created by Ankit Batra on 11/11/20.
//

/* Given an array of distinct integers candidates and a target integer target,
 * return a list of all unique combinations of candidates where the chosen numbers sum to target.
 * You may return the combinations in any order.
 * The same number may be chosen from candidates an unlimited number of times.
 * Two combinations are unique if the frequency of at least one of the chosen numbers is different.
 * It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations
 * for the given input. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
    vector<vector<int>> result;
    vector<int> subset;
public:
    void backtrack(vector<int>& candidates, int target, int idx, vector<int>& subset) {
        if (target <= 0) {
            if (target == 0) result.push_back(subset);
            return;
        }
        if (idx > candidates.size() - 1) return;
        int val = candidates[idx];
        subset.push_back(val);
        backtrack(candidates, target - val, idx, subset);
        subset.pop_back();
        backtrack(candidates, target, idx + 1, subset);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        if (n == 0) return result;

        backtrack(candidates, target, 0, subset);

        return result;
    }
};

int main() {
    int number;
    string line;
    vector<int> candidates;
    int target;
    vector<vector<int>> result;

    std::cout << "Enter the elements of array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number) {
        candidates.push_back(number);
    }

    std::cout << "Enter the target value: " << std::endl;
    std::cin >> target;

    Solution obj;
    result = obj.combinationSum(candidates, target);

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

