//
// Created by Ankit Batra on 1/19/21.
//

/* We are given some website visits: the user with name username[i] visited the website website[i] at time timestamp[i].
 * A 3-sequence is a list of websites of length 3 sorted in ascending order by the time of their visits.
 * (The websites in a 3-sequence are not necessarily distinct.)
 * Find the 3-sequence visited by the largest number of users.
 * If there is more than one solution, return the lexicographically smallest such 3-sequence. */

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::map;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
public:
    static vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n = username.size();
        unordered_map<string, map<int, string>> m;
        for (int i = 0; i < n; ++i) m[username[i]][timestamp[i]] = website[i];
        unordered_map<string, int> cnt;
        string res;
        int count = 0;

        for (auto u : m) {
            unordered_set<string> ts;
            for (auto it = begin(u.second); it != end(u.second); ++it) {
                for (auto it1 = next(it); it1 != end(u.second); ++it1) {
                    for (auto it2 = next(it1); it2 != end(u.second); ++it2) {
                        ts.insert(it->second + "$" + it1->second + "#" + it2->second);
                    }
                }
            }
            for (auto s : ts) cnt[s]++;
        }

        for (auto it : cnt) {
            if (it.second >= count) {
                res = res == "" || it.second > count ? it.first : std::min(res, it.first);
                count = it.second;
            }
        }

        auto p1 = res.find("$"), p2 = res.find("#");

        return {res.substr(0, p1), res.substr(p1 + 1, p2 - p1 - 1), res.substr(p2 + 1)};
    }
};

int main() {
    // Solution inspired from:
    // https://leetcode.com/problems/analyze-user-website-visit-pattern/discuss/357252/C%2B%2B-maps-and-sets
    return 0;
}

