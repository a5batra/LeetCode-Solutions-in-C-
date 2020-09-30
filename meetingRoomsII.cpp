//
// Created by Ankit Batra on 9/29/20.
//

/* Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
 * find the minimum number of conference rooms required. */

#include <iostream>
#include <queue>
#include <vector>

using std::priority_queue;
using std::sort;
using std::vector;

class myComparator {
public:
    int operator()(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] > v2[1];
    }
};

class Solution {
public:
    static bool customSort(vector<int>& v1, vector<int>& v2) {
        return v1[0] < v2[0];
    }
    static int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return n;
        int minRooms = 1;
        sort(intervals.begin(), intervals.end(), customSort);

        priority_queue<vector<int>, vector<vector<int>>, myComparator> pq;
        pq.push(intervals[0]);

        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] >= pq.top()[1]) {
                pq.pop();
                pq.push(intervals[i]);
            }
            else {
                pq.push(intervals[i]);
                minRooms++;
            }
        }
        return minRooms;
    }
};

int main() {
    vector<vector<int>> intervals = {{1,5},{8,9},{8,9}};

    std::cout << "Minimum number of conference rooms: " << Solution::minMeetingRooms(intervals);

    return 0;
}

