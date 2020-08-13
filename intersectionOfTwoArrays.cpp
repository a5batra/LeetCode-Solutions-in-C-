//
// Created by Ankit Batra on 8/12/20.
//

// Given two arrays, write a function to compute their intersection.

#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_set;
using std::vector;

class Solution {
public:
    static void printVector(vector<int> vec) {
        for (int i = 0; i < vec.size(); ++i)
            std::cout << vec[i] << " ";
        std::cout << std::endl;
    }
    static vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if (n == 0) return {};
        if (m == 0) return {};
        vector<int> result;

        unordered_set<int> s1;
        unordered_set<int> s2;

        for (int i = 0; i < n; ++i)
            s1.insert(nums1[i]);

        for (int j = 0; j < m; ++j)
            s2.insert(nums2[j]);

        for (auto it = s1.begin(); it != s1.end(); ++it) {
            if (s2.find(*it) != s2.end())
                result.push_back(*it);
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
    result = Solution::intersection(nums1, nums2);
    Solution::printVector(result);

    return 0;
}

