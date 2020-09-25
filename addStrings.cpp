//
// Created by Ankit Batra on 9/25/20.
//

// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    static string addStrings(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        string result = "";
        int carry = 0;
        int i = len1 - 1;
        int j = len2 - 1;
        int sum = 0;
        while (i >= 0 || j >= 0) {
            sum = ((i < 0) ? 0 : num1[i] - '0') + ((j < 0) ? 0 : num2[j] - '0') + carry;
            carry = sum / 10;
            sum = sum % 10;
            result += std::to_string(sum);
            i--;
            j--;
        }

        if (carry > 0) {
            result += std::to_string(carry);
        }
        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    string num1;
    string num2;

    std::cout << "Enter the two numbers to add: " << std::endl;
    std::cin >> num1 >> num2;

    std::cout << "After addition: " << Solution::addStrings(num1, num2);
    return 0;
}

