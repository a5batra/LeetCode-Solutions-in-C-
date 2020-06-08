//
// Created by Ankit Batra on 6/8/20.
//

// Given an integer, write a function to determine if it is a power of two.

#include <iostream>

class Solution {
public:
    static bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        long x = n;

        if ((x & -x) == x) return true;
        return false;
    }
};

int main() {
    int n;
    bool result;

    std::cout << "Enter the integer. " << std::endl;
    std::cin >> n;

    result = Solution::isPowerOfTwo(n);

    if (result)
        std::cout << n << " is a power of two. " << std::endl;
    else
        std::cout << n << " is not a power of two." << std::endl;

    return 0;
}

