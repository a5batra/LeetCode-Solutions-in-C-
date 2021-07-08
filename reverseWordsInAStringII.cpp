//
// Created by Ankit Batra on 7/8/21.
//

/* Given a character array s, reverse the order of the words.
 * A word is defined as a sequence of non-space characters. The words in s will be separated by a single space.
 * Your code must solve the problem in-place, i.e. without allocating extra space. */

class Solution {
public:
    void swapper(vector<char>& s, int i, int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    void reverseWords(vector<char>& s) {
        int len = s.size();
        int i = 0, j = 0;

        reverse(s.begin(), s.end());

        i = 0, j = 0;

        while (j < len) {
            if (s[j] == ' ') {
                int lowIdx = i, highIdx = j - 1;
                while (lowIdx <= highIdx) {
                    swapper(s, lowIdx, highIdx);
                    lowIdx++;
                    highIdx--;
                }
                j++;
                i = j;
            }
            else j++;
        }
        int lowIdx = i, highIdx = j - 1;
        while (lowIdx <= highIdx) {
            swapper(s, lowIdx, highIdx);
            lowIdx++;
            highIdx--;
        }
    }
};
