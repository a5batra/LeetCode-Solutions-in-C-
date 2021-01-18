//
// Created by Ankit Batra on 1/17/21.
//

/* We are given an array asteroids of integers representing asteroids in a row.
 * For each asteroid, the absolute value represents its size, and the sign represents its direction
 * (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
 * Find out the state of the asteroids after all collisions.
 * If two asteroids meet, the smaller one will explode.
 * If both are the same size, both will explode. Two asteroids moving in the same direction will never meet. */

#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

using std::stack;
using std::string;
using std::vector;

class Solution {
public:
    static vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for (int a : asteroids) {
            if (s.empty() || a > 0) s.push(a);
            else {
                while (true) {
                    int top = s.top();
                    if (top < 0) {
                        s.push(a);
                        break;
                    }
                    else if (top == -a) {
                        s.pop();
                        break;
                    }
                    else if (top > abs(a)) {
                        break;
                    }
                    else {
                        s.pop();
                        if (s.empty()) {
                            s.push(a);
                            break;
                        }
                    }
                }
            }
        }

        vector<int> result;
        while (!s.empty()) {
            int t = s.top();
            s.pop();
            result.push_back(t);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    int number;
    string line;
    vector<int> asteroids;

    std::cout << "Enter the array having asteroids size: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number) asteroids.push_back(number);

    vector<int> result = Solution::asteroidCollision(asteroids);

    for (int sz : result)
        std::cout << sz << " ";

    return 0;
}

