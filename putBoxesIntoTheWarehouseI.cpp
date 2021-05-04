//
// Created by Ankit Batra on 5/3/21.
//

/* You are given two arrays of positive integers, boxes and warehouse, representing the heights of some boxes of
 * unit width and the heights of n rooms in a warehouse respectively.
 * The warehouse's rooms are labelled from 0 to n - 1 from left to right where warehouse[i] (0-indexed)
 * is the height of the ith room.
 * Boxes are put into the warehouse by the following rules:
 * Boxes cannot be stacked.
 * You can rearrange the insertion order of the boxes.
 * Boxes can only be pushed into the warehouse from left to right only.
 * If the height of some room in the warehouse is less than the height of a box,
 * then that box and all other boxes behind it will be stopped before that room.
 * Return the maximum number of boxes you can put into the warehouse. */

#include <vector>

using std::min;
using std::vector;

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int ans = 0;
        sort(boxes.begin(), boxes.end());

        int n = warehouse.size();

        int currMin = warehouse[0];

        for (int i = 1; i < n; ++i) {
            currMin = min(currMin, warehouse[i]);
            warehouse[i] = currMin;
        }

        int wIdx = n - 1;
        int bIdx = 0;
        while (wIdx >= 0 && bIdx < boxes.size()) {
            if (boxes[bIdx] > warehouse[wIdx]) {
                wIdx--;
            }
            else {
                bIdx++;
                wIdx--;
                ans += 1;
            }
        }
        return ans;
    }
};

