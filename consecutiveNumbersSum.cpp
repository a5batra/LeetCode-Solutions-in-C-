//
// Created by Ankit Batra on 9/16/20.
//

// Given a positive integer N, how many ways can we write it as a sum of consecutive positive integers?

#include <iostream>


class Solution {
public:
    static int consecutiveNumbersSum(int N) {
        int n = 2;
        double startingNum = 0.0;
        int numWays = 1;

        while ((2 * N + n - n * n) > 0) {
            startingNum = (2.0 * N + n - n * n) / (2.0 * n);
            // cout << "Int num: " << (2 * N + n - n * n) / (2 * n) << endl;
            // cout << "Starting num: " << startingNum << endl;
            if ((startingNum - (2 * N + n - n * n) / (2 * n) == 0)) {
                // cout << startingNum << " " << startingNum + n - 1 << " " << n << endl;
                numWays++;
            }
            n++;
        }

        return numWays;
    }
};

int main() {
    int N;

    std::cout << "Enter the value of N: " << std::endl;
    std::cin >> N;

    std::cout << "Number of ways: " << Solution::consecutiveNumbersSum(N) << std::endl;
    return 0;
}

