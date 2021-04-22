//
// Created by ankitb on 4/21/21.
//

// Given a string s, find the length of the longest substring without repeating characters.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (len == 0 || len == 1) return len;
        unordered_map<char, int> lastSeen;

        int left = 0, right = 0;

        int maxLen = 0, currLen = 0;
        while (right < len) {
            if (lastSeen.count(s[right]) > 0) {
                left = max(left, lastSeen[s[right]] + 1);
                lastSeen[s[right]] = right;
                currLen = right - left + 1;
            }
            else {
                currLen++;
                lastSeen[s[right]] = right;
            }
            maxLen = max(maxLen, currLen);
            right++;
        }

        return maxLen;
    }
};