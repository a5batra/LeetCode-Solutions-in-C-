//
// Created by Ankit Batra on 10/12/20.
//

/* Remove the minimum number of invalid parentheses in order to make the input string valid.
 * Return all possible results.
 * Note: The input string may contain letters other than the parentheses ( and ). */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
    vector<string> result;
public:
    vector<string> removeInvalidParentheses(string s) {
        if (s.length() == 0) return {""};
        int openRem = 0;
        int closeRem = 0;

        for (auto c : s) {
            if (c == '(') openRem++;
            else if (c == ')') {
                if (openRem) openRem--;
                else closeRem++;
            }
        }
        dfs(s, 0, openRem, closeRem);

        return result;
    }
    bool isValid(string s) {
        int bal = 0;
        for (auto c : s) {
            if (c == '(') bal++;
            else if (c == ')') bal--;
            if (bal < 0) return false;
        }

        return bal == 0 ? true : false;
    }
    void dfs(const string& s, int start, int openRem, int closeRem) {
        if (openRem == 0 && closeRem == 0) {
            if (isValid(s)) {
                result.push_back(s);
                return;
            }
        }

        for (int i = start; i < s.length(); ++i) {
            if (i != start && s[i] == s[i - 1]) continue; // skip computation for adjacent duplicates

            if (s[i] == ')' && closeRem > 0) {
                string curr = s;
                curr.erase(i, 1);
                dfs(curr, i, openRem, closeRem - 1);
            }
            else if (s[i] == '(' && openRem > 0) {
                string curr = s;
                curr.erase(i, 1);
                dfs(curr, i, openRem - 1, closeRem);
            }
        }
    }
};

int main() {
    string s;
    vector<string> result;

    std::cout << "Enter the string s: " << std::endl;
    std::cin >> s;

    Solution obj;
    result = obj.removeInvalidParentheses(s);

    std::cout << "After removing minimum number of invalid parentheses: " << std::endl;

    for (auto s : result)
        std::cout << s << " ";

    return 0;
}

