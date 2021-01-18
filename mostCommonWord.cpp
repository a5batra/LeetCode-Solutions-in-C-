//
// Created by Ankit Batra on 1/17/21.
//

/* Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.
 * It is guaranteed there is at least one word that isn't banned, and that the answer is unique.
 * Words in the list of banned words are given in lowercase, and free of punctuation.
 * Words in the paragraph are not case sensitive.  The answer is in lowercase. */

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
public:
    static string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet;
        for (string word : banned) bannedSet.insert(word);

        for (char& c : paragraph) c = isalpha(c) ? tolower(c) : ' ';

        std::istringstream stream(paragraph);

        unordered_map<string, int> counts;
        string str;
        while (stream >> str) {
            if (counts.find(str) != counts.end()) counts[str] += 1;
            else counts[str] = 1;
        }

        int maxCount = 0;
        string res;
        for (auto it = counts.begin(); it != counts.end(); ++it) {
            if (bannedSet.find(it->first) == bannedSet.end()) {
                if (it->second > maxCount) {
                    res = it->first;
                    maxCount = it->second;
                }
            }
        }
        return res;
    }
};

int main() {
    string paragraph;
    string str, line;
    vector<string> banned;

    std::cout << "Enter the list of banned words: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> str) banned.push_back(str);

    std::cout << "Enter paragraph: " << std::endl;
    std::cin >> paragraph;

    std::cout << "Result: " << Solution::mostCommonWord(paragraph, banned);

    return 0;
}

