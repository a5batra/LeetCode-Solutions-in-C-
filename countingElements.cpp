//
// Created by Ankit Batra on 4/7/20.
//

/* Given an integer array arr, count element x such that x + 1 is also in arr.
 * If there're duplicates in arr, count them separately. */

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using std::string;
using std::vector;
using std::unordered_map;

class Solution {
public:
    static int CountElements(vector<int> arr) {
        int len = arr.size();
        int count = 0;
        unordered_map<int, int> numToCount;

        for (int i = 0; i < len; ++i) {
            if (numToCount.find(arr[i]) != numToCount.end())
                numToCount[arr[i]] += 1;
            else
                numToCount[arr[i]] = 1;
        }

        for (auto it = numToCount.begin(); it != numToCount.end();  ++it) {
            if (numToCount.find(it->first + 1) != numToCount.end())
                count += it->second;
        }
        return count;
    }
};

int main() {
    int count = 0;
    int number;
    string line;
    vector<int> arr;

    std::cout << "Enter the elements of the array separated by space. " << std::endl;
    std::getline(std::cin, line);
    std::istringstream stream(line);

    while (stream >> number)
        arr.push_back(number);

    count = Solution::CountElements(arr);
    std::cout << "The number of elements in the array which satisfy the condition that if x is the array, x + 1 is also in the array: " << count;

    return 0;
}