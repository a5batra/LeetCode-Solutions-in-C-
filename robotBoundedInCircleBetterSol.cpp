//
// Created by ankitb on 1/25/21.
//

/* On an infinite plane, a robot initially stands at (0, 0) and faces north.  The robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degress to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle. */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static bool isRobotBounded(string instructions) {

        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> pos = {0, 0};
        int d = 0;
        for (char i : instructions) {
            if (i == 'G') {
                pos[0] += dir[d % 4][0];
                pos[1] += dir[d % 4][1];
            }
            else if (i == 'L')
                d = (d + 3) % 4;
            else
                d = (d + 1) % 4;
        }

        return (pos[0] == 0 && pos[1] == 0) || d % 4 != 0;

    }
};

int main() {
    string instructions;

    std::cout << "Enter the instructions: " << std::endl;
    std::cin >> instructions;

    std::cout << "Result: " << Solution::isRobotBounded(instructions);
    return 0;
}
