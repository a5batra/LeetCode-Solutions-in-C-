//
// Created by Ankit Batra on 6/15/21.
//

/* You are given an array colors, in which there are three colors: 1, 2 and 3.
 * You are also given some queries. Each query consists of two integers i and c,
 * return the shortest distance between the given index i and the target color c.
 * If there is no solution return -1. */

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> dict;
        vector<int> ans;

        int n = colors.size();

        for (int i = 0; i < n; ++i) {
            dict[colors[i]].push_back(i);
        }

        for (vector<int>& q : queries) {
            int idx = q[0], color = q[1];
            if (dict.count(color) == 0) {
                ans.push_back(-1);
                continue;
            }
            vector<int>& arr = dict[color];
            if (idx <= arr[0]) ans.push_back(arr[0] - idx);
            else if (idx >= arr[arr.size() - 1]) ans.push_back(idx - arr[arr.size() - 1]);
            else {
                int targetIdx = lower_bound(arr.begin(), arr.end(), idx) - arr.begin();
                int leftDist = idx - (arr[targetIdx - 1]);
                int rightDist = arr[targetIdx] - idx;
                ans.push_back(min(leftDist, rightDist));
            }
        }

        return ans;
    }
};

