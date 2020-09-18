//
// Created by Ankit Batra on 9/16/20.
//

/* Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 * Note: You may not slant the container and n is at least 2. */

#include <iostream>
#include <sstream>
#include <vector>

using std::min;
using std::string;
using std::vector;

class Solution {
public:
    static int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n - 1;
        int maxArea = INT_MIN;
        int currArea = 0;

        while (i != j) {
            currArea = min(height[i], height[j]) * (j - i);
            if (currArea > maxArea) maxArea = currArea;
            if (height[i] <= height[j]) i++;
            else j--;
        }
        return maxArea;
    }
};

int main() {
    int number;
    string line;
    vector<int> arr;

    std::cout << "Enter the n non-negative integers separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        arr.push_back(number);

    std::cout << "Maximum volume of water that can be contained: " << Solution::maxArea(arr);

    return 0;
}