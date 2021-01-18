//
// Created by Ankit Batra on 1/18/21.
//

/* Given a palindromic string palindrome, replace exactly one character by any lowercase English letter
 * so that the string becomes the lexicographically smallest possible string that isn't a palindrome.
 * After doing so, return the final string.  If there is no way to do so, return the empty string. */

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    static string breakPalindrome(string palindrome) {
        int len = palindrome.length();
        if (len == 0 || len == 1) return "";

        for (int i = 0; i < len / 2; ++i) {
            char& c = palindrome[i];
            if (c != 'a') {
                c = 'a';
                return palindrome;
            }
        }

        palindrome[len - 1] = 'b';

        return palindrome;
    }
};

int main() {
    string palindrome;

    std::cout << "Enter the palindrome string: " << std::endl;
    std::cin >> palindrome;

    std::cout << "Result: " << Solution::breakPalindrome(palindrome);

    return 0;
}

