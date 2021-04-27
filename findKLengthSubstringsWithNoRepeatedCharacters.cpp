//
// Created by Ankit Batra on 4/26/21.
//

// Given a string S, return the number of substrings of length K with no repeated characters.

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    bool uniqueChars(vector<int>& arr) {
        for (int n : arr) {
            if (n > 1) return false;
        }
        return true;
    }
    int numKLenSubstrNoRepeats(string S, int K) {
        int len = S.length();
        int ans = 0;
        if (len < K) return ans;

        vector<int> arr(26);
        int start = 0, end = K - 1;
        while (start <= end) {
            arr[S[start] - 'a']++;
            start++;
        }
        if (uniqueChars(arr)) ans++;

        start = 0;

        while (end < len) {
            arr[S[start] - 'a']--;
            start++;
            end++;
            if (end == len) break;
            arr[S[end] - 'a']++;
            if (uniqueChars(arr)) {
                ans += 1;
            }
        }
        return ans;
    }
};

