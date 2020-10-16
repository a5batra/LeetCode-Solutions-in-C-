//
// Created by Ankit Batra on 10/15/20.
//

// Given a non-empty array of integers, return the k most frequent elements.

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using std::make_pair;
using std::pair;
using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
    static bool customSort(pair<int, int>& p1, pair<int, int>& p2) {
        return p1.second > p2.second;
    }
    static vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result(k);

        unordered_map<int, int> numToCount;

        for (int i = 0; i < nums.size(); ++i) {
            if (numToCount.find(nums[i]) != numToCount.end()) {
                numToCount[nums[i]] += 1;
            }
            else numToCount[nums[i]] = 1;
        }

        vector<pair<int, int>> numCount;

        for (auto it = numToCount.begin(); it != numToCount.end(); ++it) {
            numCount.push_back(make_pair(it->first, it->second));
        }

        sort(numCount.begin(), numCount.end(), customSort);

        for (int i = 0; i < k; ++i)
            result[i] = numCount[i].first;

        return result;

    }
};

int main() {
    int number;
    string line;
    vector<int> nums;
    vector<int> result;
    int k;

    std::cout << "Enter the elements of array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        nums.push_back(number);

    std::cout << "Enter the value of k: " << std::endl;
    std::cin >> k;

    result = Solution::topKFrequent(nums, k);

    std::cout << "Top k frequent elements: " << std::endl;

    for (int i = 0; i < result.size(); ++i)
        std::cout << result[i] << " ";

    return 0;
}



