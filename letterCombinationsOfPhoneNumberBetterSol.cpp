//
// Created by ankitb on 2/23/21.
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
    unordered_map<char, string> myMap{
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
    };
    vector<string> result;
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return result;
        dfs(digits, 0, "");

        return result;
    }

    void dfs(string digits, int idx, string comb) {
        if (idx == digits.length()) {
            result.push_back(comb);
        }

        string s = myMap[digits[idx]];
        for (char c : s) {
            dfs(digits, idx + 1, comb + c);
        }

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
