//
// Created by Ankit Batra on 10/6/20.
//

// Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    static bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
    static bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i < j) {
            if (s[i] != s[j]) {
                return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
            }
            i++;
            j--;
        }
        return true;
    }
};

int main() {
    string s;

    std::cout << "Enter the string: " << std::endl;
    std::cin >> s;

    std::cout << "Result: " << Solution::validPalindrome(s);
    return 0;
}