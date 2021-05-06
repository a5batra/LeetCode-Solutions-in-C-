//
// Created by Ankit Batra on 5/5/21.
//

/* A permutation perm of n integers of all the integers in the range [1, n] can be represented as a string s of
 * length n - 1 where:
 * s[i] == 'I' if perm[i] < perm[i + 1], and
 * s[i] == 'D' if perm[i] > perm[i + 1].
 * Given a string s, reconstruct the lexicographically smallest permutation perm and return it. */

#include <stack>
#include <vector>

using std::stack;
using std::vector;

class Solution {
public:
    vector<int> findPermutation(string s) {
        stack<int> st;

        vector<int> perm(s.length() + 1);
        int idx = 0;

        for (int i = 1; i <= s.length(); ++i) {
            if (s[i - 1] == 'I') {
                st.push(i);
                while (!st.empty()) {
                    perm[idx++] = st.top();
                    st.pop();
                }
            }
            else st.push(i);
        }
        st.push(s.length() + 1);
        while (!st.empty()) {
            perm[idx++] = st.top();
            st.pop();
        }

        return perm;
    }
};

