//
// Created by Ankit Batra on 1/16/21.
//

/* Given a list of words (without duplicates), please write a program that returns all concatenated words in the
 * given list of words.
 * A concatenated word is defined as a string that is comprised entirely of at least
 * two shorter words in the given array. */

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
    vector<string> result;
    unordered_set<string> wordSet;
    unordered_map<string, bool> state;
    int minLen =  INT_MAX;
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (string word : words) {
            if (word.length() != 0) {
                wordSet.insert(word);
                if (word.length() < minLen) minLen = word.length();
            }
        }

        for (auto it = wordSet.begin(); it != wordSet.end(); ++it) {
            if (canForm(*it)) result.push_back(*it);
        }
        return result;
    }

    bool canForm(string word) {
        if (state.find(word) != state.end()) return state[word];
        for (int i = 1; i <= word.length(); ++i) {
            string left = word.substr(0, i);
            string right = word.substr(i);
            if (wordSet.find(left) != wordSet.end() && (wordSet.find(right) != wordSet.end() || canForm(right)))
                return state[word] = true;
        }
        return state[word] = false;
    }
};

int main() {
    string str;
    string line;
    vector<string> words;

    std::cout << "Enter the words: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> str) words.push_back(str);

    Solution obj;
    vector<string> result = obj.findAllConcatenatedWordsInADict(words);

    for (string word : result) std::cout << word << " ";

    return 0;
}