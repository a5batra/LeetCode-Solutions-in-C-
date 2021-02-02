//
// Created by Ankit Batra on 2/1/21.
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

using std::string;
using std::vector;

class Solution {
public:
    static int calPoints(vector<string>& ops) {
        vector<int> s;

        for (string op : ops) {
            if (op == "C") s.pop_back();
            else if (op == "D") {
                s.push_back(s.back() * 2);
            }
            else if (op == "+") {
                int sc = s[s.size() - 1] + s[s.size() - 2];
                s.push_back(sc);
            }
            else {
                s.push_back(stoi(op));
            }
        }
        int sum = 0;

        for (int sc : s) sum += sc;

        return sum;
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