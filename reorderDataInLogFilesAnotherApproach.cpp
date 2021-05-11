//
// Created by Ankit Batra on 5/11/21.
//

/* You are given an array of logs. Each log is a space-delimited string of words, where the first word is the
 * identifier.
 * There are two types of logs:
 * Letter-logs: All words (except the identifier) consist of lowercase English letters.
 * Digit-logs: All words (except the identifier) consist of digits.
 * Reorder these logs so that:
 * The letter-logs come before all digit-logs.
 * The letter-logs are sorted lexicographically by their contents. If their contents are the same,
 * then sort them lexicographically by their identifiers.
 * The digit-logs maintain their relative ordering.
 * Return the final order of the logs. */

#include <string>
#include <vector>

using std::pair;
using std::string;
using std::vector;

class Solution {
public:
    static bool customSort(pair<string, string>& p1, pair<string, string>& p2) {
        if (p1.second == p2.second) return p1.first < p2.first;
        return p1.second < p2.second;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ans;
        vector<string> digitLogs;
        vector<pair<string, string>> idLetter;

        for (string& l : logs) {
            int idxSpace = l.find(' ');
            if (isdigit(l[idxSpace + 1])) digitLogs.push_back(l);
            else {
                idLetter.push_back({l.substr(0, idxSpace), l.substr(idxSpace + 1)});
            }
        }

        sort(idLetter.begin(), idLetter.end(), customSort);

        for (auto p : idLetter)
            ans.push_back(p.first + " " + p.second);

        for (string d : digitLogs) ans.push_back(d);

        return ans;
    }
};

