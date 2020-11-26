//
// Created by Ankit Batra on 11/25/20.
//

/* Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num
 * calculate the number of 1's in their binary representation and return them as an array. */

#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static vector<int> countBits(int num) {
        vector<int> bits(num + 1);
        bits[0] = 0;
        for (int i = 1; i <= num; ++i) {
            if (i % 2 == 0) {
                bits[i] = bits[i / 2];
            }
            else {
                bits[i] = bits[i / 2] + 1;
            }
        }
        return bits;
    }
};

int main() {
    int num;
    vector<int> bits;

    std::cout << "Enter the number num: " << std::endl;
    std::cin >> num;

    bits = Solution::countBits(num);

    for (int i = 0; i < bits.size(); ++i) {
        std::cout << bits[i] << " ";
    }
    return 0;
}
