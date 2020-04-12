//
// Created by Ankit Batra on 4/11/20.
//

/* Given two strings S and T, return if they are equal when both are typed into empty text editors.
 * # means a backspace character.
 * Follow up:
 * Can you solve it in O(N) time and O(1) space? */

#include <iostream>
#include <stack>
#include <string>

using std::stack;
using std::string;

class Solution {
public:
    static bool backspaceCompare(string S, string T) {
        int lenS = S.length();
        int lenT = T.length();
        stack<char> stackS;
        stack<char> stackT;

        for (int i = 0; i < lenS; ++i) {
            if (stackS.empty() && S[i] == '#')
                continue;
            else if (!stackS.empty() && S[i] == '#')
                stackS.pop();
            else
                stackS.push(S[i]);
        }

        for (int i = 0; i < lenT; ++i) {
            if (stackT.empty() && T[i] == '#')
                continue;
            else if (!stackT.empty() && T[i] == '#')
                stackT.pop();
            else
                stackT.push(T[i]);
        }

        while (!stackS.empty() && !stackT.empty()) {
            if (stackS.top() != stackT.top())
                return false;
            else {
                stackS.pop();
                stackT.pop();
            }
        }

        return (!stackS.empty() || !stackT.empty()) ? false : true;
    }
};

int main() {
    bool result;
    string S;
    string T;

    std::cout << "Enter the string S. " << std::endl;
    std::cin >> S;
    std::cout << "Enter the string T. " << std::endl;
    std::cin >> T;

    result = Solution::backspaceCompare(S, T);
    if (result)
        std::cout << "The two strings are equal when they are typed into empty text editors. ";
    else
        std::cout << "The two strings are not equal when they are typed into empty text editors. ";

    return 0;
}



