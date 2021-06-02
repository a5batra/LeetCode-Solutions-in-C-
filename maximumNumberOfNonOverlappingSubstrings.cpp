//
// Created by Ankit Batra on 6/2/21.
//

/* Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that
 * meet the following conditions:
 * The substrings do not overlap, that is for any two substrings s[i..j] and s[k..l], either j < k or i > l is true.
 * A substring that contains a certain character c must also contain all occurrences of c.
 * Find the maximum number of substrings that meet the above conditions.
 * If there are multiple solutions with the same number of substrings,
 * return the one with minimum total length. It can be shown that there exists a unique solution of minimum total
 * length.
 * Notice that you can return the substrings in any order. */

class Solution {
public:
    static bool customSort(pair<int, int>& p1, pair<int, int>& p2) {
        return p1.second - p1.first < p2.second - p2.first;
    }
    bool isOverlap(vector<pair<int, int>>& arr, int start, int end) {
        if (arr.empty()) return false;

        for (auto idxs : arr) {
            int s = idxs.first, e = idxs.second;
            if (end >= s && e >= start) return true;
        }
        return false;
    }
    vector<string> maxNumOfSubstrings(string s) {
        unordered_map<char, pair<int, int>> dict;
        vector<string> ans;
        for (int i = 0; i < s.length(); ++i) {
            if (dict.count(s[i])) dict[s[i]].second = i;
            else dict[s[i]] = {i, i};
        }


        for (auto& d : dict) {
            int& start = d.second.first;
            int& end = d.second.second;
            stack<pair<int, int>> st;
            st.push({start, end});
            while (!st.empty()) {
                pair<int, int> p = st.top();
                st.pop();
                int currStart = p.first, currEnd = p.second;
                for (int i = currStart; i <= currEnd; ++i) {
                    if (dict[s[i]].first < start) {
                        st.push({dict[s[i]].first, start - 1});
                        start = dict[s[i]].first;
                    }
                    if (dict[s[i]].second > end) {
                        st.push({end + 1, dict[s[i]].second});
                        end = dict[s[i]].second;
                    }
                }
            }
        }

        vector<pair<int, int>> subIdxs;
        for (auto d : dict)
            subIdxs.push_back(d.second);

        sort(subIdxs.begin(), subIdxs.end(), customSort);

        vector<pair<int, int>> seenIdxs;

        for (auto idxs : subIdxs) {
            int start = idxs.first, end = idxs.second;
            if (isOverlap(seenIdxs, start, end)) continue;
            seenIdxs.push_back({start, end});
            ans.push_back(s.substr(start, end - start + 1));
        }

        return ans;
    }
};

