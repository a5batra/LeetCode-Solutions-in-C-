//
// Created by Ankit Batra on 5/31/20.
//

/* Given a non-negative integer num represented as a string, remove k digits from the number so that
 * the new number is the smallest possible.
 * Note:
 * The length of num is less than 10002 and will be ≥ k.
 * The given num does not contain any leading zero. */

#include <iostream>
#include <stack>
#include <string>

using std::string;

class Solution {
public:
    static string removeKdigits(string num, int k) {
        int len = num.length();
        if (len == k) return "0";

        std::stack<char> stackOfDigits;
        string smallestNum = "";

        for (int i = 0; i < len; ++i) {
            while (!stackOfDigits.empty() && k > 0 && stackOfDigits.top() > num[i]) {
                stackOfDigits.pop();
                k--;
            }
            stackOfDigits.push(num[i]);
        }
        while (k--)
            stackOfDigits.pop();

        while(!stackOfDigits.empty()) {
            smallestNum += stackOfDigits.top();
            stackOfDigits.pop();
        }
        reverse(smallestNum.begin(), smallestNum.end());

        // Remove the leading zeros, if any
        int nonZeroIdx = 0;
        while (nonZeroIdx < smallestNum.length()) {
            if (smallestNum[nonZeroIdx] == '0') {
                nonZeroIdx++;
                continue;
            } else break;
        }

        return smallestNum.substr(nonZeroIdx) == "" ? "0" : smallestNum.substr(nonZeroIdx);
    }
};

int main() {
    int k;
    string num;

    std::cout << "Enter the non-negative number. " << std::endl;
    std::cin >> num;
    std::cout << "Enter the number of digits to remove. " << std::endl;
    std::cin >> k;

    std::cout << "After removing " << k << " digits from the number, the smallest number is: " << Solution::removeKdigits(num, k);

    return 0;
}



