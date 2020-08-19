//
// Created by Ankit Batra on 8/18/20.
//

/* There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * You may assume nums1 and nums2 cannot be both empty. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static vector<int> mergeSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if (n == 0)  return nums2;
        if (m == 0) return nums1;

        vector<int> mergedArray(n + m);
        int i = 0;
        int j = 0;
        int k = 0;

        while (i < n && j < m) {
            if (nums1[i] >= nums2[j])
                mergedArray[k++] = nums2[j++];
            else
                mergedArray[k++] = nums1[i++];
        }

        if (i == n && j != m) {
            for (; j < m; ++j)
                mergedArray[k++] = nums2[j];
        }

        if (j == m && i != n) {
            for (; i < n; ++i)
                mergedArray[k++] = nums1[i];
        }

        return mergedArray;
    }

    static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        double median = 0.0;

        vector<int> mergedArray = mergeSortedArrays(nums1, nums2);

        int k = mergedArray.size();

        if (k % 2 == 0)
            median = (mergedArray[k/2 - 1] + mergedArray[k/2]) / 2.0;
        else
            median = mergedArray[k/2];

        return median;
    }
};

int main() {
    int number;
    string line;

    vector<int> nums1;
    vector<int> nums2;

    std::cout << "Enter the elements of first sorted array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream1(line);
    while (stream1 >> number)
        nums1.push_back(number);

    std::cout << "Enter the elements of second sorted array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream2(line);
    while (stream2 >> number)
        nums2.push_back(number);

    std::cout << "Median of the two sorted arrays: " << Solution::findMedianSortedArrays(nums1, nums2);

    return 0;
}
