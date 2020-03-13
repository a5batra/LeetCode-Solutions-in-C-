//
// Created by Ankit Batra on 3/6/20.
//
/* Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 Could you solve it without converting the integer to a string?
 Approach 2: Reversing only half of the number. */

#include <iostream>

class Solution {
public:
    static bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int revNum = 0;
        int remainder = 0;
        int num = x;
        while (num > revNum) {
            remainder = num % 10;
            revNum = revNum * 10 + remainder;
            num = num / 10;
        }
        return (num == revNum || num == revNum / 10);
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
