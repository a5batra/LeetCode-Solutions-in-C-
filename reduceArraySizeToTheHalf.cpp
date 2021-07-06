//
// Created by Ankit Batra on 7/6/21.
//

/* Given an array arr.  You can choose a set of integers and remove all the occurrences of these integers in the
 * array.
 * Return the minimum size of the set so that at least half of the integers of the array are removed. */

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> dict;
        int n = arr.size();

        for (int& num : arr) dict[num]++;

        priority_queue<int> pq;
        for (auto& d : dict) pq.push(d.second);

        int ans = 0;
        int count = 0;
        while (!pq.empty()) {
            if (count >= n / 2) break;
            ans += 1;
            count += pq.top();
            pq.pop();
        }

        return ans;
    }
};

