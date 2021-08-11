//
// Created by Ankit Batra on 8/11/21.
//

/* Given an array of integers arr of even length, return true if and only if it is possible to reorder it such
 * that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2. */

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> dict;
        for (int& num : arr) dict[num]++;

        for (auto& d : dict) {
            if (dict[d.first] == 0) continue;
            int target = d.first < 0 ? d.first / 2 : 2 * d.first;

            if (d.first < 0 && d.first % 2 != 0) return false;

            if (dict[target] < dict[d.first])  return false;
            dict[target] -= dict[d.first];
        }

        return true;
    }
};

