//
// Created by Ankit Batra on 9/24/20.
//

/* Find the kth largest element in an unsorted array.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element. */

#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

using std::priority_queue;
using std::string;
using std::vector;

class Solution {
public:
    static int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, std::greater<int>> q;

        for (int i = 0; i < nums.size(); ++i) {
            q.push(nums[i]);
            if (q.size() > k)  q.pop();
        }

        return q.top();
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