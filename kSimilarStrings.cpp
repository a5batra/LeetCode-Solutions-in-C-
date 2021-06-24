//
// Created by Ankit Batra on 6/24/21.
//

/* Strings s1 and s2 are k-similar (for some non-negative integer k) if we can swap the positions of two
 * letters in s1 exactly k times so that the resulting string equals s2.
 * Given two anagrams s1 and s2, return the smallest k for which s1 and s2 are k-similar. */

class Solution {
public:
    void swap(string& s, int i, int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    int kSimilarity(string s1, string s2) {
        int len = s1.length();
        queue<pair<string, int>> q;
        int k = 0;

        q.push({s1, 0});
        unordered_set<string> visited;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                pair<string, int> p = q.front();
                q.pop();
                string curr = p.first;
                int idx = p.second;

                if (curr == s2) return k;

                while (curr[idx] == s2[idx]) idx++;

                for (int i = idx + 1; i < len; ++i) {
                    if (curr[i] == s2[idx]) {
                        swap(curr, idx, i);
                        if (visited.count(curr)) {
                            swap(curr, idx, i);
                            continue;
                        }
                        q.push({curr, idx + 1});
                        visited.insert(curr);
                        swap(curr, idx, i);
                    }
                }
            }
            k++;
        }

        return k;
    }
};

