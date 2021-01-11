//
// Created by Ankit Batra on 1/10/21.
//

/* You want to schedule a list of jobs in d days. Jobs are dependent
 * (i.e To work on the i-th job, you have to finish all the jobs j where 0 <= j < i).
 * You have to finish at least one task every day.
 * The difficulty of a job schedule is the sum of difficulties of each day of the d days.
 * The difficulty of a day is the maximum difficulty of a job done in that day.
 * Given an array of integers jobDifficulty and an integer d. The difficulty of the i-th job is jobDifficulty[i].
 * Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1. */

#include <iostream>
#include <sstream>
#include <vector>

using std::max;
using std::min;
using std::string;
using std::vector;

class Solution {
public:
    static int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1;

        vector<vector<int>> dp(d + 1, vector<int>(n, - 1));

        return dfs(jobDifficulty, d, 0, dp);
    }
    static int dfs(vector<int>& jobDifficulty, int d, int idx, vector<vector<int>>& dp) {
        if (d == 1) {
            int maxVal = 0;
            while (idx < jobDifficulty.size()) maxVal = max(maxVal, jobDifficulty[idx++]);
            return maxVal;
        }
        if (dp[d][idx] != -1) return dp[d][idx];
        int maxVal = 0;
        int result = INT_MAX;
        for (int i = idx; i < jobDifficulty.size() - d + 1; ++i) {
            maxVal = max(maxVal, jobDifficulty[i]);
            result = min(result, maxVal + dfs(jobDifficulty, d - 1, i + 1, dp));
        }

        return dp[d][idx] = result;
    }
};

int main() {
    int number, d;
    string line;
    vector<int> jobDifficulty;

    std::cout << "Enter the array of job difficulty: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number) {
        jobDifficulty.push_back(number);
    }

    std::cout << "Enter the value of d: " << std::endl;
    std::cin >> d;

    std::cout << "Result: " << Solution::minDifficulty(jobDifficulty, d);

    return 0;
}

