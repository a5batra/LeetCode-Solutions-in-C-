//
// Created by Ankit Batra on 6/2/21.
//

/* Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
 * An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such
 * that:
 * s = s1 + s2 + ... + sn
 * t = t1 + t2 + ... + tm
 * |n - m| <= 1
 * The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
 * Note: a + b is the concatenation of strings a and b. */

class Solution {
    unordered_map<string, bool> state;
public:
    bool helper(string s1, string s2, string s3, int idx1, int idx2, int idx3) {
        if (idx3 == s3.length())
            return (idx1 == s1.length() && idx2 == s2.length());

        string key = to_string(idx1) + "*" + to_string(idx2) + "*" + to_string(idx3);

        if (state.count(key)) return state[key];

        if (idx1 == s1.length())
            return state[key] = s2[idx2] == s3[idx3] ? helper(s1, s2, s3, idx1, idx2 + 1, idx3 + 1) : false;
        if (idx2 == s2.length())
            return state[key] = s1[idx1] == s3[idx3] ? helper(s1, s2, s3, idx1 + 1, idx2, idx3 + 1) : false;

        bool res1 = false, res2 = false;
        if (s1[idx1] == s3[idx3])
            res1 = helper(s1, s2, s3, idx1 + 1, idx2, idx3 + 1);
        if (s2[idx2] == s3[idx3])
            res2 = helper(s1, s2, s3, idx1, idx2 + 1, idx3 + 1);

        return state[key] = res1 or res2;


        if (state.count(key)) return state[key];
    }
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if (len3 != len1 + len2) return false;

        return helper(s1, s2, s3, 0, 0, 0);

    }
};

