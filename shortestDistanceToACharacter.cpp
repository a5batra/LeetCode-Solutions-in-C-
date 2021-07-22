//
// Created by Ankit Batra on 7/21/21.
//

/* Given a string s and a character c that occurs in s, return an array of integers answer where answer.length == s.
 * length and answer[i] is the distance from index i to the closest occurrence of character c in s.
 * The distance between two indices i and j is abs(i - j), where abs is the absolute value function. */

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> left(n, -1);
        left[0] = s[0] == c ? 0 : -1;
        vector<int> right(n, -1);
        right[n - 1] = s[n - 1] == c ? n - 1 : -1;

        for (int i = 1; i < n; ++i) {
            if (s[i] == c) {
                left[i] = i;
            }
            else left[i] = left[i - 1];
        }

        for (int i = n - 2; i >= 0; --i) {
            if (s[i] == c) {
                right[i] = i;
            }
            else right[i] = right[i + 1];
        }

        vector<int> ans(n);

        for (int i = 0; i < n; ++i) {
            if (s[i] == c) ans[i] = 0;
            else {
                if (left[i] != -1 && right[i] != -1) {
                    ans[i] = min(i - left[i], right[i] - i);
                }
                else if (left[i] != -1 && right[i] == -1) ans[i] = i - left[i];
                else ans[i] = right[i] - i;
            }
        }

        return ans;
    }
};

