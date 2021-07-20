//
// Created by Ankit Batra on 7/20/21.
//

/* We can shift a string by shifting each of its letters to its successive letter.
 * For example, "abc" can be shifted to be "bcd".
 * We can keep shifting the string to form a sequence.
 * For example, we can keep shifting "abc" to form the sequence: "abc" -> "bcd" -> ... -> "xyz".
 * Given an array of strings strings, group all strings[i] that belong to the same shifting sequence.
 * You may return the answer in any order. */

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> dict;

        for (string& s : strings) {
            string key = "";
            char base = s[0];
            for (int i = 0; i < s.length(); ++i) {
                key += to_string((s[i] - base + 26) % 26) + "$";
            }
            if (dict.count(key)) dict[key].push_back(s);
            else dict[key] = {s};
        }

        for (auto& d : dict) {
            ans.push_back(d.second);
        }

        return ans;
    }
};

