//
// Created by Ankit Batra on 4/29/21.
//

/* Given a robot cleaner in a room modeled as a grid.
 * Each cell in the grid can be empty or blocked.
 * The robot cleaner with 4 given APIs can move forward, turn left or turn right. Each turn it made is 90 degrees.
 * When it tries to move into a blocked cell, its bumper sensor detects the obstacle and it stays on the current cell.
 * Design an algorithm to clean the entire room using only the 4 given APIs shown below. */

/*
interface Robot {
        // returns true if next cell is open and robot moves into the cell.
        // returns false if next cell is obstacle and robot stays on the current cell.
        boolean move();

        // Robot will stay on the same cell after calling turnLeft/turnRight.
        // Each turn will be 90 degrees.
        void turnLeft();
        void turnRight();

        // Clean the current cell.
        void clean();
}
 */

/* Notes:
 * The input is only given to initialize the room and the robot's position internally.
 * You must solve this problem "blindfolded". In other words, you must control the robot using only the
 * mentioned 4 APIs, without knowing the room layout and the initial robot's position.
 * The robot's initial position will always be in an accessible cell.
 * The initial direction of the robot will be facing up.
 * All accessible cells are connected, which means the all cells marked as 1 will be accessible by the robot.
 * Assume all four edges of the grid are all surrounded by wall. */

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_set;
using std::vector;

class Solution {
    unordered_set<string> st;
    int x, y;
    vector<vector<int>> directions;
public:
    Solution() {
        directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    }
    void helper(Robot& robot, int x, int y, int dir) {
        st.insert(std::to_string(x) + "*" + std::to_string(y));
        robot.clean();
        for (int k = dir; k < dir + 4; ++k) {
            int nx = directions[k % 4][0] + x;
            int ny = directions[k % 4][1] + y;
            string key = std::to_string(nx) + "*" + std::to_string(ny);
            if (st.count(key) == 0 && robot.move()) {
                helper(robot, nx, ny, k);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            robot.turnRight();
        }
    }
    void cleanRoom(Robot& robot) {
        helper(robot, 0, 0, 0);
    }
};

