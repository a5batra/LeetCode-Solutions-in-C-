//
// Created by Ankit Batra on 9/22/20.
//

/* Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
 * determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 * Note:
 * The same word in the dictionary may be reused multiple times in the segmentation.
 * You may assume the dictionary does not contain duplicate words. */

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_set;
using std::unordered_map;
using std::vector;

class Solution {
public:
    static bool dfs(string s, unordered_set<string>& wordSet, unordered_map<string, bool>& substrPresent) {
        if (s.length() == 0) return true;
        if (substrPresent.find(s) != substrPresent.end())
            return substrPresent[s];
        for (int i = 1; i <= s.length(); ++i) {
            if (wordSet.find(s.substr(0, i)) != wordSet.end() && dfs(s.substr(i, s.length()), wordSet, substrPresent)) {
                substrPresent[s.substr(i, s.length())] = true;
                return true;
            }
        }
        substrPresent[s] = false;
        return false;
    }
    static bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        unordered_map<string, bool> substrPresent;

        for (int i = 0; i < wordDict.size(); ++i)
            wordSet.insert(wordDict[i]);

        return dfs(s, wordSet, substrPresent);

    }
};

int main() {
    vector<string> wordDict;
    string word;
    string s;
    string line;

    std::cout << "Enter the words of dictionary separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> word)
        wordDict.push_back(word);

    std::cout << "Enter the string s: " << std::endl;
    std::cin >> s;

    std::cout << "Result is: " << Solution::wordBreak(s, wordDict);


    return 0;
}