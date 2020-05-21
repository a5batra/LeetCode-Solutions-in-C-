//
// Created by Ankit Batra on 5/21/20.
//

// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

#include <iostream>
#include <string>
#include <unordered_map>

using std::string;

class Solution {
public:
    static int firstUniqChar(string s) {
        int len = s.length();
        std::unordered_map<char, int> letterToCount;

        for (int i = 0; i < len; ++i) {
            if (letterToCount.find(s[i]) != letterToCount.end())
                letterToCount[s[i]] += 1;
            else
                letterToCount[s[i]] = 1;
        }
        for (int i = 0; i < len; ++i) {
            if (letterToCount[s[i]] == 1) return i;
        }
        return -1;
    }
};

int main() {
    string s;

    std::cout << "Enter the string. " << std::endl;
    std::cin >> s;


    std::cout << "Index of the first non-repeating character: " << Solution::firstUniqChar(s);
    return 0;
}