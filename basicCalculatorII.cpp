//
// Created by Ankit Batra on 10/7/20.
//

/* Implement a basic calculator to evaluate a simple expression string.
 * The expression string contains only non-negative integers, +, -, *, / operators and empty spaces .
 * The integer division should truncate toward zero. */

#include <iostream>
#include <stack>
#include <string>

using std::stack;
using std::string;

class Solution {
public:
    static int hasHigherPrecedence(char op1, char op2) {
        int op1Weight = getOperatorWeight(op1);
        int op2Weight = getOperatorWeight(op2);
        if (op1Weight == op2Weight) // operators in question are all left-associative
            return true;

        return op1Weight > op2Weight ? true : false;
    }
    static int getOperatorWeight(char op) {
        int weight = -1;
        switch(op) {
            case '+':
            case '-':
                weight = 1;
                break;
            case '*':
            case '/':
                weight = 2;
        }
        return weight;
    }
    static string infixToPostfix(string s) {
        string postfix = "";
        stack<char> stackChar;

        for (int i = 0; i < s.length();) {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            if (isdigit(s[i])) {
                int num = 0;
                while (isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                postfix += std::to_string(num) + '$';
            }
            else {
                while (!stackChar.empty() && hasHigherPrecedence(stackChar.top(), s[i])) {
                    postfix += stackChar.top();
                    stackChar.pop();
                }
                stackChar.push(s[i]);
                i++;
            }
        }
        while (!stackChar.empty()) {
            postfix += stackChar.top();
            stackChar.pop();
        }
        return postfix;
    }

    static int calculateResult(int num1, int num2, char op) {
        switch(op) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                return num1 / num2;
        }
        return -1;
    }

    static int calculate(string s) {
        string postfix = "";
        int result = 0;

        postfix = infixToPostfix(s);
        stack<int> digitStack;

        for (int i = 0; i < postfix.length();) {
            if (isdigit(postfix[i])) {
                int num = 0;
                while (isdigit(postfix[i])) {
                    num = num * 10 + (postfix[i] - '0');
                    i++;
                }
                digitStack.push(num);
            }
            else if (postfix[i] == '$') {
                i++;
                continue;
            }
            else {
                int num2 = digitStack.top();
                digitStack.pop();
                int num1 = digitStack.top();
                digitStack.pop();
                result = calculateResult(num1, num2, postfix[i]);
                digitStack.push(result);
                i++;
            }
        }

        result = digitStack.top();
        digitStack.pop();

        return result;
    }
};

int main() {
    string s;

    std::cout << "Enter the expression string: " << std::endl;
    std::cin >> s;

    std::cout << "Result is: " << Solution::calculate(s);
    return 0;
}

