//
// Created by Ankit Batra on 5/24/20.
//

/* Given a positive integer num, write a function which returns True if num is a perfect square else False.
 * Follow up: Do not use any built-in library function such as sqrt. */

#include <iostream>

class Solution {
public:
    static bool isPerfectSquare(int num) {
        if (num < 2) return true;
        int leftNum = 2;
        int rightNum = (num / 2);
        float midNum = 0.0;

        while (leftNum <= rightNum) {
            midNum = leftNum + (rightNum - leftNum) / 2;
            if (midNum == (num / midNum)) return true;
            else if (midNum > (num / midNum)) rightNum = midNum - 1;
            else leftNum = midNum + 1;
        }
        return false;
    }
};

int main() {
    bool result;
    int num;

    std::cout << "Enter the number. " << std::endl;
    std::cin >> num;

    result = Solution::isPerfectSquare(num);
    if (result)
        std::cout << num << " is a perfect square. " << std::endl;
    else
        std::cout << num << " is not a perfect square. " << std::endl;
    return 0;
}

