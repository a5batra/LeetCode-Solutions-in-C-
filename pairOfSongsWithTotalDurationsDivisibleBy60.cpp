//
// Created by Ankit Batra on 1/11/21.
//

/* You are given a list of songs where the ith song has a duration of time[i] seconds.
 * Return the number of pairs of songs for which their total duration in seconds is divisible by 60.
 * Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0. */

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
    static int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int numPairs = 0;
        if (n == 0) return numPairs;

        unordered_map<int, int> modToCount;

        for (int t : time) {
            if (t % 60 == 0) {
                numPairs += modToCount[t % 60];
            }
            if (modToCount.find(60 - t % 60) != modToCount.end()) {
                numPairs += modToCount[60 - t % 60];
            }
            modToCount[t % 60]++;
        }
        return numPairs;
    }
};

int main() {
    int number;
    string line;
    vector<int> time;

    std::cout << "Enter the array of time: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number) time.push_back(number);

    std::cout << "Result: " << Solution::numPairsDivisibleBy60(time);

    return 0;
}
