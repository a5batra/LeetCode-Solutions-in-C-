//
// Created by Ankit Batra on 10/1/20.
//

/* Given a string containing digits from 2-9 inclusive, return all possible letter combinations that
 * the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 * Note that 1 does not map to any letters. */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

class Solution {
    unordered_map<char, string> digitToLetters;
    vector<string> result;
    string comb = "";
public:
    void backtrack(string digits, int idx) {
        if (idx == digits.length()) {
            result.push_back(comb);
            return;
        }
        for (int i = 0; i < digitToLetters[digits[idx]].length(); ++i) {
            comb += digitToLetters[digits[idx]][i];
            backtrack(digits, idx + 1);
            comb.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return result;
        digitToLetters = {
                            {'2', "abc"},
                            {'3', "def"},
                            {'4', "ghi"},
                            {'5', "jkl"},
                            {'6', "mno"},
                            {'7', "pqrs"},
                            {'8', "tuv"},
                            {'9', "wxyz"}
                        };
        backtrack(digits, 0);

        return result;
    }
};

int main() {
    string digits;
    vector<string> result;

    std::cout << "Enter the string of digits: " << std::endl;
    std::cin >> digits;

    Solution obj;

    result = obj.letterCombinations(digits);

    for (int i = 0; i < result.size(); ++i)
        std::cout << result[i] << " ";

    return 0;
}

