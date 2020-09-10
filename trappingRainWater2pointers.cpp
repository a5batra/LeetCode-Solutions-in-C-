//
// Created by ankitb on 9/9/20.
//

/* Given n non-negative integers representing an elevation map where the width of each bar is 1,
 * compute how much water it is able to trap after raining. */

#include <iostream>
#include <sstream>
#include <vector>

using std::max;
using std::string;
using std::vector;

class Solution {
public:
    static int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int i = 0, j = n - 1;
        int leftMax = height[i];
        int rightMax = height[j];
        int waterVolume = 0;

        while (i < j) {
            leftMax = max(leftMax, height[i]);
            rightMax = max(rightMax, height[j]);
            if (leftMax <= rightMax) {
                waterVolume += leftMax - height[i];
                i++;
            }
            else {
                waterVolume += rightMax - height[j];
                j--;
            }
        }
        return waterVolume;
    }
};

int main() {
    string line;
    int number;
    vector<int> height;

    std::cout << "Enter the n non-negative integers representing an elevation map: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        height.push_back(number);

    std::cout << "Amount of water that it can trap after raining: " << Solution::trap(height);

    return 0;
}