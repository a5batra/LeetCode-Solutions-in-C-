//
// Created by Ankit Batra on 5/23/20.
//

/* Given a positive integer num, output its complement number.
 * The complement strategy is to flip the bits of its binary representation. */

#include <iostream>

class Solution {
public:
    static int findComplement(int num) {
        int complement = 0;
        int numBits = 0;
        int numToXOR = 0;
        int n = num;

        while (n != 0) {
            n = n >> 1;
            numBits += 1;
        }

        numToXOR = ((1 << (numBits - 1)) - 1 << 1) | 1;
        complement = num ^ numToXOR;

        return complement;
    }
};

int main() {
    int num;

    std::cout << "Enter the number. " << std::endl;
    std::cin >> num;

    std::cout << "The complement of this number is: " << Solution::findComplement(num);

    return 0;
}



