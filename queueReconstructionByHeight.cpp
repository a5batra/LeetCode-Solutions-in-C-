//
// Created by Ankit Batra on 11/17/20.
//

/* Suppose you have a random list of people standing in a queue.
 * A pair of integers [hi, ki] describe each person, where hi is the height of the ith person and
 * ki is the number of people in front of the ith person who has a height greater than or equal to hi.
 * Write an algorithm to reconstruct the queue. */

#include <algorithm>
#include <iostream>
#include <vector>

using std::sort;
using std::vector;

class Solution {
public:
    static bool customSort(vector<int>& p1, vector<int>& p2) {
        return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
    }
    static vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<vector<int>> q;
        if (n == 0) return q;

        sort(people.begin(), people.end(), customSort);

        for (vector<int> person : people) {
            q.insert(q.begin() + person[1], person);
        }
        return q;
    }
};

int main() {
    vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};

    vector<vector<int>> result = Solution::reconstructQueue(people);

    for (vector<int> person : result) {
        std::cout << person[0] << " " << person[1] << std::endl;
    }

    return 0;
}

