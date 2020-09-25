//
// Created by Ankit Batra on 9/24/20.
//

/* Find the kth largest element in an unsorted array.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static void swap(vector<int>& nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
    static int partition(vector<int>& nums, int left, int right, int pivotIndex) {
        int pivotVal = nums[pivotIndex];
        int lesserItemsTailIdx = left;

        swap(nums, pivotIndex, right);

        for (int i = left; i < right; ++i) {
            if (nums[i] <= pivotVal) {
                swap(nums, lesserItemsTailIdx, i);
                lesserItemsTailIdx++;
            }
        }

        swap(nums, lesserItemsTailIdx, right);

        return lesserItemsTailIdx;
    }
    static int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int pivotIndex = rand()%(right-left + 1) + left;

            int finalIndexOfPivot = partition(nums, left, right, pivotIndex);

            if (finalIndexOfPivot == n - k)
                return nums[finalIndexOfPivot];
            else if (finalIndexOfPivot > n - k) right = finalIndexOfPivot - 1;
            else left = finalIndexOfPivot + 1;
        }
        return -1;
    }
};

int main() {
    string line;
    int number;
    int k;
    vector<int> nums;

    std::cout << "Enter the elements of array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        nums.push_back(number);

    std::cout << "Enter the value of k: " << std::endl;
    std::cin >> k;

    std::cout << "kth largest element of array: " << Solution::findKthLargest(nums, k);

    return 0;
}


