//
// Created by Ankit Batra on 9/6/20.
//

// Given a collection of intervals, merge all overlapping intervals.

#include <iostream>
#include <stack>
#include <vector>

using std::sort;
using std::stack;
using std::vector;

class Solution {
public:
    static bool customSort(vector<int>& interval1, vector<int>& interval2) {
        return interval1[0] < interval2[0];
    }
    static vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        int n = intervals.size();
        if (n == 0) return mergedIntervals;

        stack<vector<int>> mergedStack;
        sort(intervals.begin(), intervals.end(), customSort);

        mergedStack.push(intervals[0]);

        for (int i = 1; i < n; ++i) {
            vector<int> intervalToCheck = mergedStack.top();
            if (intervalToCheck[1] >= intervals[i][0]) {
                mergedStack.pop();
                mergedStack.push({intervalToCheck[0], intervals[i][1] >= intervalToCheck[1] ? intervals[i][1] : intervalToCheck[1]});
            }
            else {
                mergedStack.push(intervals[i]);
            }
        }

        while (!mergedStack.empty()) {
            mergedIntervals.push_back({mergedStack.top()});
            mergedStack.pop();
        }
        return mergedIntervals;
    }
};

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> mergedIntervals;

    mergedIntervals = Solution::merge(intervals);

    for (int i = 0; i < mergedIntervals.size(); ++i) {
        for (int j = 0; j < 2; ++j)
            std::cout << mergedIntervals[i][j] << " ";
        std::cout << std::endl;
    }

    return 0;
}

