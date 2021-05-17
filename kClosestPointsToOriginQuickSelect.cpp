//
// Created by Ankit Batra on 5/17/21.
//

/* We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
 * (Here, the distance between two points on a plane is the Euclidean distance.)
 * You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)
 * */

#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        int low = 0, high = n - 1;
        vector<vector<int>> kClosestPoints(k);

        while (low <= high) {
            int pivotIdx = rand()%(high-low + 1) + low;
            int finalIdxOfPivot = partition(points, low, high, pivotIdx);
            if (finalIdxOfPivot == k) break;
            else if (finalIdxOfPivot < k) low = finalIdxOfPivot + 1;
            else high = finalIdxOfPivot - 1;
        }

        for (int i = 0; i < k; ++i) {
            kClosestPoints[i] = points[i];
        }

        return kClosestPoints;
    }

    bool compare(vector<int>& p1, vector<int>& p2) {
        int dist1 = p1[0] * p1[0] + p1[1] * p1[1];
        int dist2 = p2[0] * p2[0] + p2[1] * p2[1];

        return dist1 > dist2;
    }

    void swap(vector<vector<int>>& points, int idx1, int idx2) {
        vector<int> temp = points[idx1];
        points[idx1] = points[idx2];
        points[idx2] = temp;
    }

    int partition(vector<vector<int>>& points, int l, int h, int pivotIdx) {
        vector<int> pivotVal = points[pivotIdx];
        int lesserItemsTailIdx = l;

        swap(points, pivotIdx, h);

        for (int i = l; i < h; ++i) {
            if (!compare(points[i], pivotVal)) {
                swap(points, lesserItemsTailIdx, i);
                lesserItemsTailIdx++;
            }
        }

        swap(points, lesserItemsTailIdx, h);

        return lesserItemsTailIdx;
    }
};

