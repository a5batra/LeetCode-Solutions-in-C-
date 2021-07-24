//
// Created by Ankit Batra on 7/22/21.
//

/* There is a new alien language that uses the English alphabet. However, the order among the letters is unknown
 * to you.
 * You are given a list of strings words from the alien language's dictionary,
 * where the strings in words are sorted lexicographically by the rules of this new language.
 * Return a string of the unique letters in the new alien language sorted in lexicographically increasing order
 * by the new language's rules. If there is no solution, return "".
 * If there are multiple solutions, return any of them.
 * A string s is lexicographically smaller than a string t if at the first letter where they differ,
 * the letter in s comes before the letter in t in the alien language.
 * If the first min(s.length, t.length) letters are the same, then s is smaller if and only if s.length < t.length.*/

class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        unordered_map<char, unordered_set<char>> adjList;
        vector<int> indegree(26);

        for (string& w : words) {
            for (char& c : w) {
                if (adjList.count(c)) continue;
                else adjList[c] = {};
            }
        }

        for (int i = 1; i < n; ++i) {
            string firstWord = words[i - 1];
            string secondWord = words[i];
            int minLen = min(firstWord.length(), secondWord.length());
            int start = 0;
            while (start < minLen) {
                if (firstWord[start] != secondWord[start]) {
                    if (adjList[firstWord[start]].count(secondWord[start]) == 0) {
                        adjList[firstWord[start]].insert(secondWord[start]);
                        indegree[secondWord[start] - 'a']++;
                    }
                    break;
                }
                start++;
            }
            if (start == minLen) {
                if (firstWord.length() > secondWord.length()) {
                    return "";
                }
            }
        }

        queue<char> q;
        for (auto& e : adjList) {
            if (indegree[e.first - 'a'] == 0) q.push(e.first);
        }

        string res = "";
        while (!q.empty()) {
            char& c = q.front();
            q.pop();
            res += c;
            for (auto& neighbor : adjList[c]) {
                indegree[neighbor - 'a']--;
                if (indegree[neighbor - 'a'] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return res.length() == adjList.size() ? res : "";
    }
};

