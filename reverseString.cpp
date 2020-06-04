//
// Created by Ankit Batra on 6/4/20.
//

/* Write a function that reverses a string. The input string is given as an array of characters char[].
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory. */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static void printString(vector<char>& s) {
        int n = s.size();

        for (int i = 0; i < n; ++i)
            std::cout << s[i] << " ";
    }
    static void reverseString(vector<char>& s) {
        int n = s.size();
        char temp;

        for (int i = 0; i < n / 2; ++i) {
            temp = s[i];
            s[i] = s[n - 1 - i];
            s[n - 1 - i] = temp;
        }
    }
};

int main() {
    char temp;
    string line;
    vector<char> s;

    std::cout << "Enter the array of characters separated by space. " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> temp)
        s.push_back(temp);

    Solution::reverseString(s);

    std::cout << "After reversing the string: " << std::endl;
    Solution::printString(s);

    return 0;
}

