//
// Created by Ankit Batra on 9/4/20.
//

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static vector<string> splitLog(string log) {
        vector<string> split(2);
        string s = "";
        int i = 0;
        for (; i < log.length(); ++i) {
            if (log[i] == ' ') {
                split[0] = s;
                s = "";
                break;
            }
            else
                s += log[i];
        }
        split[1] = log.substr(i + 1, log.length() - i);
        return split;

    }

    static bool comparator(string log1, string log2) {
        vector<string> split1 = splitLog(log1);
        vector<string> split2 = splitLog(log2);

        bool isDigit1 = isdigit(split1[1][0]);
        bool isDigit2 = isdigit(split2[1][0]);

        // both are letter-logs
        if (!isDigit1 && !isDigit2) {
            int cmp = split1[1].compare(split2[1]);
            if (cmp > 0) return 0;
            else if (cmp < 0) return 1;
            return split2[0].compare(split1[0]);
        }
        // one of logs is digit log
        if (!isDigit1 && isDigit2)
            return 1;
        else if (isDigit1 && !isDigit2)
            return 0;
        else {
            return 0;
        }; // both are digit-log
    }
    static vector<string> reorderLogFiles(vector<string>& logs) {
        if (logs.size() == 0) return logs;
        stable_sort(logs.begin(), logs.end(), comparator);

        return logs;
    }
};

int main() {
    vector<string> logs = {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
    logs = Solution::reorderLogFiles(logs);

    for (int i = 0; i < logs.size(); ++i)
        std::cout << logs[i] <<  std::endl;

    return 0;
}