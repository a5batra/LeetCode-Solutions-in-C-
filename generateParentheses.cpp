//
// Created by Ankit Batra on 9/27/20.
//

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
    vector<string> result;
public:
    vector<string> generateParentheses(int n) {
        dfs("", 0, 0, n);

        return result;
    }
    void dfs(string currString, int open, int close, int n) {
        if (currString.length() == n * 2) {
            result.push_back(currString);
            return;
        }
        if (open < n)
            dfs(currString + "(", open + 1, close, n);
        if (close < open)
            dfs(currString + ")", open, close + 1, n);
    }
};

int main() {
    int n;
    vector<string> result;

    std::cout << "Enter the value of n: " << std::endl;
    std::cin >> n;

    Solution obj;
    result = obj.generateParentheses(n);

    for (int i = 0; i < result.size(); ++i)
        std::cout << result[i] << std::endl;

    return 0;
}
