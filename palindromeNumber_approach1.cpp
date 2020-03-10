//
// Created by Ankit Batra on 3/6/20.
//
/* Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 Could you solve it without converting the integer to a string?
 Approach 1: Reversing the whole number. */

#include <iostream>

class Solution {
public:
    static bool isPalindrome(int x) {
        if (x < 0) return false;
        int revNum = 0;
        int remainder = 0;
        int num = x;
        while (num != 0) {
            remainder = num % 10;
            if (revNum > INT_MAX / 10 || (revNum == INT_MAX / 10 && remainder > 7)) return false;
            if (revNum < INT_MIN / 10 || (revNum == INT_MIN / 10 && remainder < -8)) return false;
            revNum = revNum * 10 + remainder;
            num = num / 10;
        }

        return x == revNum;
    }
};

int main() {
    int num;
    bool result;
    std::cout << "Enter the number to check if it's a palindrome: " << std::endl;
    std::cin >> num;

    result = Solution::isPalindrome(num);

    if (result)
        std::cout << num << " is a palindrome number." << std::endl;
    else
        std::cout << num << " is not a palindrome number." << std::endl;

    return 0;
}