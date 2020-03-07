//
// Created by ankitb on 3/3/20.
//
#include <iostream>
#include <cmath>

class Solution {
public:
    static int reverse(int x) {
        int revNum = 0;
        int remainder = 0;
        while(x != 0) {
            remainder = x % 10;
            if(revNum > INT_MAX / 10 || (revNum == INT_MAX / 10 && remainder > 7)) return 0;
            if(revNum < INT_MIN / 10 || (revNum == INT_MIN / 10 && remainder < -8)) return 0;
            revNum = revNum * 10 + remainder;
            x = x / 10;
        }
        return revNum;
    }
};

int main() {
    int num;
    int revNum;
    std::cout << "Enter the number to reverse: " << std::endl;
    std::cin >> num;
    revNum = Solution::reverse(num);

    std::cout << "Reverse of " << num << " : " << revNum;

    return 0;
}