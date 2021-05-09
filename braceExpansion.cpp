//
// Created by Ankit Batra on 5/8/21.
//

/* You are given a string s representing a list of words. Each letter in the word has one or more options.
 * If there is one option, the letter is represented as is.
 * If there is more than one option, then curly braces delimit the options.
 * For example, "{a,b,c}" represents options ["a", "b", "c"].
 * For example, if s = "a{b,c}", the first character is always 'a', but the second character can be 'b' or 'c'.
 * The original list is ["ab", "ac"].
 * Return all words that can be formed in this manner, sorted in lexicographical order. */

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
    vector<string> result;
public:
    vector<string> expand(string s) {
        vector<string> choices;
        int n = s.length();
        int i = 0;

        while (i < n) {
            if (s[i] == '{') {
                int j = i + 1;
                string str = "";
                while (j < n && s[j] != '}') {
                    if (s[j] == ',') {
                        j++;
                        continue;
                    }
                    str += s[j];
                    j++;
                }
                choices.push_back(str);
                i = j + 1;
            }
            else {
                string toPush = "";
                toPush += s[i];
                choices.push_back(toPush);
                i++;
            }
        }

        string currStr = "";
        dfs(choices, 0, currStr);

        sort(result.begin(), result.end());

        return result;
    }

    void dfs(vector<string>& choices, int idx, string currStr) {
        if (currStr.length() == choices.size()) {
            result.push_back(currStr);
            return;
        }
        for (char c : choices[idx]) {
            currStr += c;
            dfs(choices, idx + 1, currStr);
            currStr.pop_back();
        }
    }
};


