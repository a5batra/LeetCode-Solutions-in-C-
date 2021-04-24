//
// Created by Ankit Batra on 4/24/21.
//

/* There is a special keyboard with all keys in a single row.
 * Given a string keyboard of length 26 indicating the layout of the keyboard (indexed from 0 to 25).
 * Initially, your finger is at index 0. To type a character, you have to move your finger to the index of the
 * desired character. The time taken to move your finger from index i to index j is |i - j|.
 * You want to type a string word. Write a function to calculate how much time it takes to type it with one finger. */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int n = keyboard.length();
        vector<int> idx(n);

        for (int i = 0; i < n; ++i) {
            idx[keyboard[i] - 'a'] = i;
        }

        int init = 0, ans = 0;

        for (int i = 0; i < word.length(); ++i) {
            ans += abs(idx[word[i] - 'a'] - init);
            init = idx[word[i] - 'a'];
        }
        return ans;
    }
};

int main() {
    return 0;
}

