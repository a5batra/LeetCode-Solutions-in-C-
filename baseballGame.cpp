//
// Created by Ankit Batra on 1/16/21.
//

/* You are keeping score for a baseball game with strange rules. The game consists of several rounds,
 * where the scores of past rounds may affect future rounds' scores.
 * At the beginning of the game, you start with an empty record.
 * You are given a list of strings ops, where ops[i] is the ith operation you must apply to the record and
 * is one of the following:
 * An integer x - Record a new score of x.
 * "+" - Record a new score that is the sum of the previous two scores.
 * It is guaranteed there will always be two previous scores.
 * "D" - Record a new score that is double the previous score.
 * It is guaranteed there will always be a previous score.
 * "C" - Invalidate the previous score, removing it from the record.
 * It is guaranteed there will always be a previous score.
 *
 * Return the sum of all the scores on the record. */

#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

using std::stack;
using std::string;
using std::vector;

class Solution {
public:
    static int calPoints(vector<string>& ops) {
        stack<int> s;

        for (string str : ops) {
            if (str == "C") s.pop();
            else if (str == "D") {
                int num = s.top();
                s.push(num * 2);
            }
            else if (str == "+") {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.push(num1);
                s.push(num1 + num2);
            }
            else {
                s.push(stoi(str));
            }
        }

        int result = 0;

        while (!s.empty()) {
            int num = s.top();
            s.pop();
            result += num;
        }

        return result;
    }
};

int main() {
    string str;
    string line;
    vector<string> ops;

    std::cout << "Enter the vector of records: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> str) ops.push_back(str);

    std::cout << "Result: " << Solution::calPoints(ops);

    return 0;
}
