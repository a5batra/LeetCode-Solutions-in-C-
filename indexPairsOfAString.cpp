//
// Created by Ankit Batra on 5/19/21.
//

/* Given a text string and words (a list of strings), return all index pairs [i, j] so that the substring
 * text[i]...text[j] is in the list of words. */

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<char, unordered_set<int>> dict;

        for (string& w : words) {
            char firstChar = w[0];
            for (int i = 0; i < text.length(); ++i) {
                if (firstChar == text[i]) {
                    dict[firstChar].insert(i);
                }
            }
        }

        bool found = false;
        for (string& w : words) {
            unordered_set<int> idxs = dict[w[0]];
            for (int i : idxs) {
                int k = 0;
                int j = i;
                while (j < i + w.length()) {
                    if (text[j] != w[k]) {
                        break;
                    }
                    else {
                        j++;
                        k++;
                    }
                }
                found = (j == i + (int)w.length() ? true : false);
                if (found) {
                    ans.push_back({i, i + (int)w.length() - 1});
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

