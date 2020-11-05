//
// Created by Ankit Batra on 11/4/20.
//

/* Given a list of daily temperatures T, return a list such that, for each day in the input,
 * tells you how many days you would have to wait until a warmer temperature.
 * If there is no future day for which this is possible, put 0 instead.
 * For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73],
 * your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 * Note: The length of temperatures will be in the range [1, 30000].
 * Each temperature will be an integer in the range [30, 100]. */

#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

using std::stack;
using std::string;
using std::vector;

class Solution {
public:
    static vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> result(n);
        if (n == 0) return result;

        stack<int> s;
        result[n - 1] = 0;
        s.push(n - 1);

        for (int i = n - 2; i >= 0; --i) {
            if (T[i] < T[s.top()]) {
                result[i] = s.top() - i;
                s.push(i);
            }
            else {
                while (!s.empty() && T[s.top()] <= T[i]) {
                    s.pop();
                }
                if (s.empty()) result[i] = 0;
                else {
                    result[i] = s.top() - i;
                }
                s.push(i);
            }
        }
        return result;
    }
};

int main() {
    int number;
    string line;
    vector<int> T;
    vector<int> result;

    std::cout << "Enter the elements of array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        T.push_back(number);

    result = Solution::dailyTemperatures(T);

    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }

    return 0;
}

