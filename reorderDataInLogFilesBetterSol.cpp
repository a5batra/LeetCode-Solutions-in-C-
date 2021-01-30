//
// Created by ankitb on 1/29/21.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::pair;
using std::string;
using std::vector;


class Solution {
public:
    static bool customSort(pair<string, string>& p1, pair<string, string>& p2) {
        return p1.second == p2.second ? p1.first < p2.first : p1.second < p2.second;
    }
    bool checkIfNumber(string s) {
        for (char& c : s) {
            if (!isdigit(c)) return false;
        }
        return true;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digitLogs;
        vector<string> result;
        vector<string> letterLogs;

        for (string l : logs) {
            istringstream stream(l);
            string c;
            vector<string> arr(1);
            while (stream >> c) {
                arr[0] = c;
            }
            if (checkIfNumber(arr[0])) digitLogs.push_back(l);
            else letterLogs.push_back(l);
        }

        // for (string d : digitLogs) {
        //     cout << d << endl;
        // }
        vector<pair<string, string>> idLetter;
        int idx = 0;
        for (string l : letterLogs) {
            istringstream stream(l);
            int i = 0;
            string id;
            string log;
            pair<string, string> p;
            while (stream >> id) {
                if (i == 0) {
                    p.first = id;
                    i++;
                }
                else {
                    log += id + " ";
                }
            }
            log.pop_back();
            p.second = log;
            idLetter.push_back(p);
            idx++;
        }

        sort(idLetter.begin(), idLetter.end(), customSort);

        for (pair<string, string>& p : idLetter) {
            result.push_back(p.first + " " + p.second);
        }

        for (int i = 0; i < digitLogs.size(); ++i) {
            result.push_back(digitLogs[i]);
        }

        return result;
    }
};

int main() {
    return 0;
}