//
// Created by Ankit Batra on 10/8/20.
//

/* Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 * Note:
 * Division between two integers should truncate toward zero.
 * The given RPN expression is always valid.
 * That means the expression would always evaluate to a result and there won't be any divide by zero operation. */

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using std::stack;
using std::string;
using std::vector;

class Solution {
public:
    static int calculateResult(int num1, int num2, string op) {
        if (op == "+") return num1 + num2;
        else if (op == "-") return num1 - num2;
        else if (op == "*") return num1 * num2;
        else return num1 / num2;

    }
    static bool isOperator(string s) {
        if (s == "+" || s == "-" || s == "*" || s == "/") return true;

        return false;
    }
    static int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> digitStack;
        int result = 0;

        for (int i = 0; i < n; ++i) {
            if (isOperator(tokens[i])) {
                int num2 = digitStack.top();
                digitStack.pop();
                int num1 = digitStack.top();
                digitStack.pop();
                result = calculateResult(num1, num2, tokens[i]);
                digitStack.push(result);
            }
            else {
                digitStack.push(stoi(tokens[i]));
            }
        }

        result = digitStack.top();
        digitStack.pop();

        return result;
    }
};

int main() {
    string line;
    string val;
    vector<string> tokens;

    std::cout << "Enter the arithmetic expression in RPN separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> val)
        tokens.push_back(val);

    std::cout << "The value of arithmetic expression is: " << Solution::evalRPN(tokens);

    return 0;
}

