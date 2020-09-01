//
// Created by Ankit Batra on 8/31/20.
//

/* The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence,
 * such that each number is the sum of the two preceding ones, starting from 0 and 1. */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    static int fib(int N) {
        if (N == 0 || N == 1) return N;

        vector<int> F(N+1);
        F[0] = 0;
        F[1] = 1;

        for (int i = 2; i < N + 1; ++i)
            F[i] = F[i - 1] + F[i - 2];

        return F[N];
    }
};

int main() {
    int N;

    std::cout << "Enter the value of N: " << std::endl;
    std::cin >> N;

    std::cout << "Fibonacci of N is: " << Solution::fib(N) << std::endl;

    return 0;
}