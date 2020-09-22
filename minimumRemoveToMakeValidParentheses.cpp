//
// Created by Ankit Batra on 9/21/20.
//

/* Given a string s of '(' , ')' and lowercase English characters.
 * Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that
 * the resulting parentheses string is valid and return any valid string.
 * Formally, a parentheses string is valid if and only if:
 * It is the empty string, contains only lowercase characters, or
 * It can be written as AB (A concatenated with B), where A and B are valid strings, or
 * It can be written as (A), where A is a valid string. */

#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>

using std::make_pair;
using std::pair;
using std::stack;
using std::string;
using std::unordered_set;

class Solution {
public:
    static string minRemoveToMakeValid(string s) {
        if (s.length() == 0) return "";
        stack<pair<char, int>> charIdxStack;
        string result = "";
        unordered_set<int> indices;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') charIdxStack.push(make_pair(s[i], i));
            else if (s[i] == ')') {
                if (charIdxStack.empty()) charIdxStack.push(make_pair(s[i], i));
                else if (charIdxStack.top().first == '(') charIdxStack.pop();
                else charIdxStack.push(make_pair(s[i], i));
            }
        }

        while (!charIdxStack.empty()) {
            indices.insert(charIdxStack.top().second);
            charIdxStack.pop();
        }

        for (int i = 0; i < s.length(); ++i) {
            if (indices.find(i) != indices.end()) continue;
            result += s[i];
        }
        return result;
    }
};

int main() {
    string s;
    std::cout << "Enter the string s: " << std::endl;
    std::cin >> s;

    std::cout << "Minimum remove to make valid parentheses: " << Solution::minRemoveToMakeValid(s);

    return 0;
}

