//
// Created by ankitb on 4/5/21.
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
        if (p1[0] == p2[0]) return p1[1] < p2[1];
        return p1[0] < p2[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), customSort);

        int count = 0;
        vector<vector<int>> ans(n, vector<int>(2, -1));

        for (int i = 0; i < n; ++i) {
            count = people[i][1];
            for (int j = 0; j < n; ++j) {
                if (ans[j][0] == -1 && count == 0) {
                    ans[j][0] = people[i][0];
                    ans[j][1] = people[i][1];
                    break;
                }
                else if (ans[j][0] == -1 || ans[j][0] >= people[i][0]) {
                    count -= 1;
                }
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}