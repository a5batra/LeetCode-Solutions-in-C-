//
// Created by Ankit Batra on 8/2/21.
//

/* You are given a string s containing lowercase English letters, and a matrix shift,
 * where shift[i] = [directioni, amounti]:
 * directioni can be 0 (for left shift) or 1 (for right shift).
 * amounti is the amount by which string s is to be shifted.
 * A left shift by 1 means remove the first character of s and append it to the end.
 * Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
 * Return the final string after all operations. */

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int totalLeftShift = 0;
        int totalRightShift = 0;

        for (vector<int>& s : shift) {
            if (s[0] == 0) totalLeftShift += s[1];
            else totalRightShift += s[1];
        }

        string ans = "";
        int len = s.length();

        int actualShift = totalLeftShift - totalRightShift;
        if (actualShift < 0) { // rightshift
            int shift = abs(actualShift) % len;
            ans += s.substr(len - abs(shift));
            ans += s.substr(0, len - abs(shift));
        }
        else if (actualShift > 0){ // left shift
            int shift = abs(actualShift) % len;
            ans += s.substr(shift);
            ans += s.substr(0, shift);
        }
        else ans = s;

        return ans;
    }
};

