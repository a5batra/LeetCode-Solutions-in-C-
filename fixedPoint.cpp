//
// Created by Ankit Batra on 5/4/21.
//

/* Given an array of distinct integers arr, where arr is sorted in ascending order, return the smallest index i
 * that satisfies arr[i] == i. If there is no such index, return -1. */

#include <vector>

using std::vector;

class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        int mid = 0;

        int ans = -1;

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (arr[mid] == mid) {
                ans = mid;
                high = mid - 1;
            }
            else if (arr[mid] > mid) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};

