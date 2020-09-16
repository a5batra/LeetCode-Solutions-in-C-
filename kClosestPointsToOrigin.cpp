//
// Created by Ankit Batra on 9/15/20.
//

/* We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
 * (Here, the distance between two points on a plane is the Euclidean distance.)
 * You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.) */

#include <iostream>
#include <vector>

using std::sort;
using std::vector;

class Solution {
public:
    static bool customSort(vector<int>& point1, vector<int>& point2) {
        return point1[0] * point1[0] + point1[1] * point1[1] < point2[0] * point2[0] + point2[1] * point2[1];
    }
    static vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> kClosestPoints;
        int n = points.size();
        if (n == 0) return kClosestPoints;

        sort(points.begin(), points.end(), customSort);

        for (int i = 0; i < K; ++i)
            kClosestPoints.push_back(points[i]);
        return kClosestPoints;
    }
};

int main() {
    vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
    int K = 2;
    vector<vector<int>> kClosestPoints;

    kClosestPoints = Solution::kClosest(points, K);

    for (int i = 0; i < kClosestPoints.size(); ++i) {
        std::cout << kClosestPoints[i][0] << " " << kClosestPoints[i][1] << std::endl;
    }

    return 0;
}

