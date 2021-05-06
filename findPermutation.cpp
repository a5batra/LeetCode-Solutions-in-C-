//
// Created by Ankit Batra on 5/5/21.
//

/* A permutation perm of n integers of all the integers in the range [1, n] can be represented as a string s of
 * length n - 1 where:
 * s[i] == 'I' if perm[i] < perm[i + 1], and
 * s[i] == 'D' if perm[i] > perm[i + 1].
 * Given a string s, reconstruct the lexicographically smallest permutation perm and return it. */

#include <vector>

using std::vector;

class Solution {
public:
    void reverse(vector<int>& perm, int start, int end) {
        while (start <= end) {
            int temp = perm[start];
            perm[start] = perm[end];
            perm[end] = temp;
            start++;
            end--;
        }
    }
    vector<int> findPermutation(string s) {
        int n = s.length() + 1;
        vector<int> perm(n);

        for (int i = 0; i < n; ++i)
            perm[i] = i + 1;

        int idx = 0;
        int start = -1, end = -1;
        while (idx < s.length()) {
            if (s[idx] == 'I') {
                if (start != -1) {
                    end = idx;
                    reverse(perm, start, end);
                    start = -1;
                }
            }
            else {
                if (start == -1)
                    start = idx;
            }
            idx++;
        }

        if (start != -1) {
            end = idx;
            reverse(perm, start, end);
        }

        return perm;
    }
};

