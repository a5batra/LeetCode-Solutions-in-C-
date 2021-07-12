//
// Created by Ankit Batra on 7/12/21.
//

/* Given two strings s and t, determine if they are isomorphic.
 * Two strings s and t are isomorphic if the characters in s can be replaced to get t.
 * All occurrences of a character must be replaced with another character while preserving the order of
 * characters. No two characters may map to the same character, but a character may map to itself. */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> dict1;
        unordered_map<char, char> dict2;

        for (int i = 0; i < s.length(); ++i) {
            if (dict1.count(s[i])) {
                if (dict1[s[i]] != t[i]) return false;
            }
            else dict1[s[i]] = t[i];
            if (dict2.count(t[i])) {
                if (dict2[t[i]] != s[i]) return false;
            }
            else dict2[t[i]] = s[i];
        }

        return true;
    }
};

