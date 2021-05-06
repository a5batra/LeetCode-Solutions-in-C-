//
// Created by Ankit Batra on 5/5/21.
//

/* (This problem is an interactive problem.)
 * Each ship is located at an integer point on the sea represented by a cartesian plane, and
 * each integer point may contain at most 1 ship.
 * You have a function Sea.hasShips(topRight, bottomLeft) which takes two points as arguments and
 * returns true If there is at least one ship in the rectangle represented by the two points,
 * including on the boundary.
 * Given two points: the top right and bottom left corners of a rectangle,
 * return the number of ships present in that rectangle.
 * It is guaranteed that there are at most 10 ships in that rectangle.
 * Submissions making more than 400 calls to hasShips will be judged Wrong Answer.
 * Also, any solutions that attempt to circumvent the judge will result in disqualification. */

/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

#include <vector>

using std::vector;

class Solution {
public:
    int helper(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        if (topRight[0] < bottomLeft[0] || topRight[1] < bottomLeft[1]) return 0;
        if (!sea.hasShips(topRight, bottomLeft)) return 0;
        if (topRight[0] == bottomLeft[0] && topRight[1] == bottomLeft[1]) return 1;

        int numShips = 0;
        vector<int> diag = {(bottomLeft[0] + topRight[0]) / 2, (bottomLeft[1] + topRight[1]) / 2};

        numShips = helper(sea, diag, bottomLeft) + helper(sea, topRight, {diag[0] + 1, diag[1] + 1}) + helper(sea, {topRight[0], diag[1]}, {diag[0] + 1, bottomLeft[1]}) + helper(sea, {diag[0], topRight[1]}, {bottomLeft[0], diag[1] + 1});


        return numShips;

    }
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        return helper(sea, topRight, bottomLeft);
    }
};

