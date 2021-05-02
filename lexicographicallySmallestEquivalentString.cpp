//
// Created by Ankit Batra on 5/2/21.
//

/* Given strings A and B of the same length, we say A[i] and B[i] are equivalent characters.
 * For example, if A = "abc" and B = "cde", then we have 'a' == 'c', 'b' == 'd', 'c' == 'e'.
 * Equivalent characters follow the usual rules of any equivalence relation:
 * Reflexivity: 'a' == 'a'
 * Symmetry: 'a' == 'b' implies 'b' == 'a'
 * Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'
 * For example, given the equivalency information from A and B above, S = "eed", "acd", and "aab" are
 * equivalent strings, and "aab" is the lexicographically smallest equivalent string of S.
 * Return the lexicographically smallest equivalent string of S by using the equivalency information from A and B. */


class Solution {
public:
    int find(vector<int>& parent, char u) {
        if (parent[u - 'a'] == -1) return (u - 'a');
        return find(parent, parent[u - 'a'] + 'a');
    }
    void unionOp(vector<int>& parent, char u, char v) {
        int parentU = find(parent, u);
        int parentV = find(parent, v);
        if (parentU < parentV) {
            parent[parentV] = parentU;
        }
        else parent[parentU] = parentV;
    }
    string smallestEquivalentString(string A, string B, string S) {
        int n = A.length();
        vector<int> parent(26, -1);

        for (int i = 0; i < n; ++i) {
            char u = A[i], v = B[i];
            int parentU = find(parent, u);
            int parentV = find(parent, v);
            if (parentU == parentV) continue;

            unionOp(parent, u, v);
        }

        string ans = "";
        for (char c : S) {
            char t;
            if (parent[c - 'a'] == -1) t = c;
            else  t = find(parent, c) + 'a';
            ans += t;
        }

        return ans;
    }
};

