//
// Created by Ankit Batra on 9/8/20.
//

/* Given n non-negative integers representing an elevation map where the width of each bar is 1,
 * compute how much water it is able to trap after raining. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = 0;
        rightMax[n - 1] = 0;

        int maxValue = height[0];
        int waterVolume = 0;

        for (int i = 1; i < n; ++i) {
            if (height[i - 1] > maxValue)
                maxValue = height[i - 1];
            leftMax[i] = maxValue;
        }

        maxValue = height[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            if (height[i + 1] > maxValue)
                maxValue = height[i + 1];
            rightMax[i] = maxValue;
        }

        for (int i = 0; i < n; ++i) {
            if (std::min(leftMax[i], rightMax[i]) - height[i] < 0) continue;

            waterVolume += std::min(leftMax[i], rightMax[i]) - height[i];
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