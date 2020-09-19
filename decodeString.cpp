//
// Created by Ankit Batra on 9/17/20.
//

/* Given an encoded string, return its decoded string.
 * The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated
 * exactly k times. Note that k is guaranteed to be a positive integer.
 * You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
 * Furthermore, you may assume that the original data does not contain any digits and that digits are only for
 * those repeat numbers, k. For example, there won't be input like 3a or 2[4]. */

#include <iostream>
#include <stack>
#include <string>

using std::stack;
using std::string;

class Solution {
public:
    static string decodeString(string s) {
        int len = s.length();
        stack<int> digitStack;
        stack<string> stringStack;
        string res = "";
        int idx = 0;

        while (idx < len) {
            if (isdigit(s[idx])) {
                int count = 0;
                while (isdigit(s[idx])) {
                    count = 10 * count + (s[idx] - '0');
                    idx++;
                }
                digitStack.push(count);
            }
            else if(s[idx] == '[') {
                stringStack.push(res);
                res = "";
                idx++;
            }
            else if(s[idx] == ']') {
                string temp = stringStack.top();
                stringStack.pop();
                int count = digitStack.top();
                digitStack.pop();
                for (int i = 0; i < count; ++i)
                    temp.append(res);
                res = temp;
                idx++;
            }
            else {
                res += s[idx];
                idx++;
            }
        }
        return res;
    }
};

int main() {
    string s;
    std::cout << "Enter the string to decode: " << std::endl;
    std::cin >> s;

    std::cout << "Decoded string: " << Solution::decodeString(s) << std::endl;

    return 0;
}


