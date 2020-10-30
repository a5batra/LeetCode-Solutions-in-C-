//
// Created by Ankit Batra on 10/29/20.
//

/* On an infinite plane, a robot initially stands at (0, 0) and faces north.  The robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degress to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle. */

#include <iostream>
#include <string>

using std::pair;
using std::string;

class Solution {
public:
    static bool isRobotBounded(string instructions) {
        int len = instructions.length();
        if (len == 0) return true;

        pair<int, int> dir = {0, 1};
        pair<int, int> coord = {0, 0};

        for (int i = 0; i < len; ++i) {
            if (instructions[i] == 'G') {
                coord.first = coord.first + dir.first;
                coord.second = coord.second + dir.second;
            }
            else if (instructions[i] == 'L') {
                int temp = dir.first;
                dir.first = -dir.second;
                dir.second = temp;
            }
            else {
                int temp = dir.first;
                dir.first = dir.second;
                dir.second = -temp;
            }
        }

        if (coord.first == 0 && coord.second == 0) return true;
        if (dir.first == 0 && dir.second == 1) return false;

        return true;

    }
};

int main() {
    string instructions;

    std::cout << "Enter the instructions: " << std::endl;
    std::cin >> instructions;

    std::cout << "Result: " << Solution::isRobotBounded(instructions);
    return 0;
}

