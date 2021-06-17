//
// Created by Ankit Batra on 6/16/21.
//

/* Given an array of integers arr and an integer k. Find the least number of unique integers after removing
 * exactly k elements. */

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> dict;
        for (int& a : arr) dict[a]++;

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& d : dict) pq.push(d.second);

        int ans = 0;

        while (k >= pq.top()) {
            k -= pq.top();
            pq.pop();
        }

        ans = pq.size();

        return ans;

    }
};

