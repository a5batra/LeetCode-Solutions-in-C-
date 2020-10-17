//
// Created by Ankit Batra on 10/16/20.
//

// Given a non-empty array of integers, return the k most frequent elements.

#include <iostream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <vector>

using std::make_pair;
using std::pair;
using std::priority_queue;
using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
    static vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == nums.size()) return nums;

        vector<int> result(k);

        unordered_map<int, int> numToCount;

        for (int i = 0; i < nums.size(); ++i) {
            if (numToCount.find(nums[i]) != numToCount.end())
                numToCount[nums[i]] += 1;
            else numToCount[nums[i]] = 1;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<pair<int,int>>> pq;

        for (auto it = numToCount.begin(); it != numToCount.end(); ++it) {
            pq.push({it->second, it->first});
            if (pq.size() > k) pq.pop();
        }

        for (int i = k - 1; i >= 0; --i) {
            pair<int, int> top = pq.top();
            pq.pop();
            result[i] = top.second;
        }
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
