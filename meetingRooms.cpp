//
// Created by Ankit Batra on 9/29/20.
//

/* Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
 * determine if a person could attend all meetings. */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    static bool customSort(vector<int>& v1, vector<int>& v2) {
        return v1[0] < v2[0];
    }
    static bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), customSort);

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i - 1][1]) return false;
        }

        return true;
    }
};

int main() {
    vector<vector<int>> intervals = {{7,10}, {2,4}};

    std::cout << "Result: " << Solution::canAttendMeetings(intervals);

    return 0;
}

