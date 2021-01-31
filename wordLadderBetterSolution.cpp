//
// Created by Ankit Batra on 1/30/21.
//

/*  Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation
 * sequence from beginWord to endWord, such that: Only one letter can be changed at a time.
 * Each transformed word must exist in the word list.
 * Note:
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same. */

#include <iostream>
#include <queue>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using std::pair;
using std::queue;
using std::string;
using std::unordered_set;
using std::unordered_map;
using std::vector;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;
        for (string w : wordList) wordSet.insert(w);

        if (wordSet.find(endWord) == wordSet.end()) return 0;

        queue<string> q;
        q.push(beginWord);
        int level = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string s = q.front();
                q.pop();
                if (s == endWord) return level + 1;
                for (int i = 0; i < s.length(); ++i) {
                    string temp = s;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp[i] = c;
                        if (temp == s) continue;
                        else if (wordSet.find(temp) != wordSet.end()) {
                            q.push(temp);
                            wordSet.erase(temp);
                        }
                    }
                }
            }
            level++;
        }

        return 0;
    }
};