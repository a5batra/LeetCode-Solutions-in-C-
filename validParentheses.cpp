//
// Created by Ankit Batra on 3/12/20.
//
/* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is
 * valid.
 * An input string is valid if:
    1. Open brackets must be closed by the same type of brackets.
    2. Open brackets must be closed in the correct order.
Note that an empty string is also considered valid. */

#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    static bool isValid(std::string s) {
        int len = s.length();
        std::stack<char> stackOfBrackets;

        for (int i = 0; i < len; ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                stackOfBrackets.push(s[i]);
            else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (stackOfBrackets.empty()) return false;
                else {
                    char top = stackOfBrackets.top();
                    if ((s[i] == ')' && top != '(') || (s[i] == '}' && top != '{') || (s[i] == ']' && top != '[') )
                        return false;
                    else
                        stackOfBrackets.pop();
                }
            }
        }

        return stackOfBrackets.empty() ? true : false;
    }
};

int main() {
    bool result;
    std::string str;

    std::cout << "Enter the input string: " << std::endl;
    std::cin >> str;

    result = Solution::isValid(str);

    if (result)
        std::cout << str << " is a valid string." << std::endl;
    else
        std::cout << str << " is not a valid string." << std::endl;

    return 0;
}

