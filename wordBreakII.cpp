//
// Created by Ankit Batra on 1/9/21.
//

/* Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.
 * Note:
 * The same word in the dictionary may be reused multiple times in the segmentation.
 * You may assume the dictionary does not contain duplicate words. */

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
    unordered_set<string> wordSet;
    unordered_map<string, vector<string>> state;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string word : wordDict) wordSet.insert(word);

        return helper(s);
    }

    vector<string> helper(string s) {
        vector<string> result;
        if (wordSet.find(s) != wordSet.end()) {
            result.push_back(s);
        }
        if (state.find(s) != state.end()) return state[s];
        for (int i = 1; i <= s.length(); ++i) {
            string left = s.substr(0, i);
            if (wordSet.find(left) != wordSet.end()) {
                vector<string> temp = helper(s.substr(i));
                for (string str : temp) {
                    result.push_back(left + " " + str);
                }
            }
        }
        return state[s] = result;
    }
};

int main() {
    string str, s;
    string line;
    vector<string> wordDict;

    std::cout << "Enter words of dictionary: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> str) wordDict.push_back(str);

    std::cout << "Enter the string s: " << std::endl;
    std::cin >> s;

    Solution obj;
    vector<string> result;

    result = obj.wordBreak(s, wordDict);

    for (string str : result) std::cout << str << std::endl;

    return 0;

}