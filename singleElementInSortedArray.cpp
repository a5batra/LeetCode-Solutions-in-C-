//
// Created by Ankit Batra on 5/25/20.
//

/* You are given a sorted array consisting of only integers where every element appears exactly twice,
 * except for one element which appears exactly once. Find this single element that appears only once.
 * Follow up: Your solution should run in O(log n) time and O(1) space. */

#include <iostream>
#include <vector>
#include <sstream>

using std::vector;
using std::string;

class Solution {
public:
    static int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mid = 0;
        bool halvesAreEven = 0;

        while (low < high) {
            mid = low + (high - low) / 2;
            halvesAreEven = (high - mid) % 2 == 0;
            if (nums[mid] == nums[mid+1]) {
                if (halvesAreEven) low = mid + 2;
                else high = mid - 1;
            }
            else if (nums[mid-1] == nums[mid]) {
                if (halvesAreEven) high = mid - 2;
                else low = mid + 1;
            }
            else
                return nums[mid];
        }
        return nums[low];
    }
};

int main() {
    string line;
    int number;
    int singleElement;
    vector<int> nums;

    std::cout << "Enter the sorted array of integers separated by space. " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while(stream >> number)
        nums.push_back(number);

    std::cout << "The single element that appears only once is: " << Solution::singleNonDuplicate(nums);

    return 0;
}
