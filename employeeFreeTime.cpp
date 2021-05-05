//
// Created by Ankit Batra on 5/2/21.
//

/* We are given a list schedule of employees, which represents the working time for each employee.
 * Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.
 * Return the list of finite intervals representing common, positive-length free time for all employees,
 * also in sorted order.
 * (Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or
 * arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined).
 * Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length. */

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    static bool customSort(Interval& i1, Interval& i2) {
        if (i1.start == i2.start) return i1.end < i2.end;
        return i1.start < i2.start;
    }
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> intervals;
        for (vector<Interval>& v : schedule) {
            for (Interval& i : v) {
                intervals.push_back(i);
            }
        }
        sort(intervals.begin(),intervals.end(), customSort);

        stack<Interval> s;

        vector<Interval> ans;

        int n = intervals.size();
        s.push(intervals[0]);

        for (int i = 1; i < n; ++i) {
            Interval top = s.top();
            if (intervals[i].start <= top.end) {
                s.pop();
                int newEnd = top.end > intervals[i].end ? top.end : intervals[i].end;
                s.push(Interval(top.start, newEnd));
            }
            else s.push(intervals[i]);
        }

        vector<Interval> mergeInt(s.size());
        int idx = s.size() - 1;

        while (!s.empty()) {
            Interval t = s.top();
            s.pop();
            mergeInt[idx] = t;
            idx--;
        }

        for (int i = 0; i < mergeInt.size() - 1; ++i) {
            ans.push_back(Interval(mergeInt[i].end, mergeInt[i + 1].start));
        }
        return ans;
    }
};

