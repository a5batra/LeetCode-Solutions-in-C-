//
// Created by ankitb on 8/19/20.
//

//
// Created by Ankit Batra on 8/19/20.
//

/* There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * You may assume nums1 and nums2 cannot be both empty. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        double median = 0;

        if (n > m)
            return findMedianSortedArrays(nums2, nums1);

        int low = 0;
        int high = n;
        while(low <= high) {
            int partition_nums1 = (low + high) / 2;
            int partition_nums2 = (n + m + 1) / 2 - partition_nums1;

            int max_left_nums1 = partition_nums1 == 0 ? INT_MIN : nums1[partition_nums1 - 1];
            int min_right_nums1 = partition_nums1 == n ? INT_MAX : nums1[partition_nums1];

            int max_left_nums2 = partition_nums2 == 0 ? INT_MIN : nums2[partition_nums2 - 1];
            int min_right_nums2 = partition_nums2 == m ? INT_MAX : nums2[partition_nums2];

            if (max_left_nums1 <= min_right_nums2 && max_left_nums2 <= min_right_nums1) {
                if ((n + m) % 2 == 0) {
                    median = (max(max_left_nums1, max_left_nums2) + min(min_right_nums1, min_right_nums2)) / 2.0;
                }
                else
                    median = max(max_left_nums1, max_left_nums2);
                break;
            }

            else if (max_left_nums1 > min_right_nums2)
                high = partition_nums1 - 1;
            else
                low = partition_nums1 + 1;
        }

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
