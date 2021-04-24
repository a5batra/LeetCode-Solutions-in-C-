//
// Created by Ankit Batra on 4/24/21.
//

/* Given two lists Aand B, and B is an anagram of A. B is an anagram of A means B is made by randomizing
 * the order of the elements in A.
 * We want to find an index mapping P, from A to B. A mapping P[i] = j means the ith element in A appears in
 * B at index j.
 * These lists A and B may contain duplicates. If there are multiple answers, output any of them. */

#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        unordered_map<int, int> idx;

        for (int i = 0; i < n; ++i) {
            idx[B[i]] = i;
        }

        for (int i = 0; i < n; ++i) {
            ans[i] = idx[A[i]];
        }
        return ans;
    }
};

int main() {
    return 0;
}

