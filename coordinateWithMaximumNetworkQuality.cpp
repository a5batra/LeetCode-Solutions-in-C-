//
// Created by Ankit Batra on 10/17/20.
//

/* You are given an array of network towers towers and an integer radius, where towers[i] = [xi, yi, qi] denotes
 * the ith network tower with location (xi, yi) and quality factor qi. All the coordinates are integral coordinates
 * on the X-Y plane, and the distance between two coordinates is the Euclidean distance.
 * The integer radius denotes the maximum distance in which the tower is reachable.
 * The tower is reachable if the distance is less than or equal to radius. Outside that distance,
 * the signal becomes garbled, and the tower is not reachable.
 * The signal quality of the ith tower at a coordinate (x, y) is calculated with the formula ⌊qi / (1 + d)⌋,
 * where d is the distance between the tower and the coordinate. The network quality at a coordinate is the
 * sum of the signal qualities from all the reachable towers.
 * Return the integral coordinate where the network quality is maximum. If there are multiple coordinates with the
 * same network quality, return the lexicographically minimum coordinate.
 *
 * Note:
 * A coordinate (x1, y1) is lexicographically smaller than (x2, y2) if either x1 < x2 or x1 == x2 and y1 < y2.
 * ⌊val⌋ is the greatest integer less than or equal to val (the floor function). */

#include <iostream>
#include <cmath>
#include <vector>

using std::vector;

class Solution {
public:
    static double distance(int x, int y, int x1, int y1) {
        double dist = 0.0;
        dist = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
        return dist;
    }
    static bool isReachable(int x, int y, int x1, int y1, int radius) {
        return (x - x1) * (x - x1) + (y - y1) * (y - y1) <= radius * radius;
    }
    static vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int maxQual = INT_MIN;
        vector<int> result = {0, 0};

        for (auto t : towers) {
            int x = t[0], y = t[1], q = t[2];
            int currQual = 0;
            for (auto s : towers) {
                int x1 = s[0], y1 = s[1], q1 = s[2];
                if (!isReachable(x, y, x1, y1, radius))
                    continue;
                currQual += floor(q1 / (1 + distance(x, y, x1, y1)));
            }
            if (currQual > maxQual) {
                maxQual = currQual;
                result = {x, y};
            }
            else if (currQual == maxQual)
                result = std::min(result, {x, y});
        }
        return result;
    }
};

int main() {
    vector<vector<int>> towers = {{1,2,5},{2,1,7},{3,1,9}};
    int radius = 2;
    vector<int> result = Solution::bestCoordinate(towers, radius);

    for (int i = 0; i < result.size(); ++i)
        std::cout << result[i] << " ";

    return 0;
}

