//
// Created by Ankit Batra on 8/12/20.
//

/* Given two arrays, write a function to compute their intersection.
 * Note:
 * Each element in the result should appear as many times as it shows in both arrays.
 * The result can be in any order. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static void printVector(vector<int> vec) {
        for (int i = 0; i < vec.size(); ++i)
            std::cout << vec[i] << " ";
        std::cout << std::endl;
    }
    static vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if (n == 0 || m == 0) return {};

        vector<int> result;
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        if (nums1[0] > nums2[m - 1] || nums1[n - 1] < nums2[0]) return result;

        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            if (nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] > nums2[j]) j++;
            else i++;
        }

        return result;
    }
};

int main() {
    int number;
    string line;
    vector<int> nums1;
    vector<int> nums2;
    vector<int> result;

    std::cout <<  "Enter elements of first array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream1(line);
    while(stream1 >> number)
        nums1.push_back(number);

    std::cout <<  "Enter elements of second array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream2(line);
    while(stream2 >> number)
        nums2.push_back(number);

    std::cout << "Intersection of the two arrays: " << std::endl;
    result = Solution::intersect(nums1, nums2);
    Solution::printVector(result);

    return 0;
}