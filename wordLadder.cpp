//
// Created by Ankit Batra on 9/21/20.
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
#include <unordered_map>
#include <vector>

using std::pair;
using std::queue;
using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
    static unordered_map<string, vector<string>> preprocessing(vector<string>& wordList) {
        unordered_map<string, vector<string>> statesToWords;
        int L = wordList[0].length();
        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = 0; j < L; ++j) {
                string newWord = wordList[i].substr(0, j) + '*' + wordList[i].substr(j + 1, L);
                if (statesToWords.find(newWord) != statesToWords.end())
                    statesToWords[newWord].push_back(wordList[i]);
                else
                    statesToWords[newWord] = {wordList[i]};
            }
        }
        return statesToWords;
    }
    static int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord.length() == 0 || endWord.length() == 0 || wordList.size() == 0) return 0;
        int L = beginWord.size();
        int n = wordList.size();
        unordered_map<string, vector<string>> statesToWords = preprocessing(wordList);
        queue<pair<string, int>> q;
        unordered_map<string, bool> visited;
        q.push(make_pair(beginWord, 1));
        visited[beginWord] = true;

        while (!q.empty()) {
            pair<string, int> node = q.front();
            q.pop();
            string currWord = node.first;
            int level = node.second;
            for (int i = 0; i < L; ++i) {
                string newWord = currWord.substr(0, i) + '*' + currWord.substr(i + 1, L);
                for (string neighbour : statesToWords[newWord]) {
                    if (visited[neighbour]) continue;
                    else if (neighbour == endWord) return level + 1;
                    else {
                        visited[neighbour] = true;
                        q.push(make_pair(neighbour, level + 1));
                    }
                }

            }
        }
        return 0;
    }
};

int main() {
    string beginWord;
    string endWord;
    vector<string> wordList;
    string line;
    string word;

    std::cout << "Enter the word list: " << std::endl;
    std::getline(std::cin, line);
    std::istringstream stream(line);
    while (stream >> word)
        wordList.push_back(word);
    std::cout << "Enter the beginning word: " << std::endl;
    std::cin >> beginWord;
    std::cout << "Enter the ending word: " << std::endl;
    std::cin >> endWord;

    std::cout << "Length of shortest transformation from begin word to end word: " << Solution::ladderLength(beginWord, endWord, wordList);
}