//
// Created by Ankit Batra on 4/6/20.
//

/* Given an array of strings, group anagrams together.
 *
 * Note:
 * 1. All inputs will be in lowercase.
 * 2. The order of your output does not matter. */

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using std::string;
using std::vector;
using std::unordered_map;

class Solution {
public:
    static void printVector(vector<string>& strs) {
        int len = strs.size();
        for (int i = 0; i < len; ++i)
            std::cout << strs[i] << " ";
        std::cout << std::endl;
    }
    static vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        unordered_map<string, vector<string>> wordToAnagram;
        int len = strs.size();

        for (int i = 0; i < len; ++i) {
            string t = strs[i];
            std::sort(t.begin(), t.end());
            if (wordToAnagram.find(t) != wordToAnagram.end())
                wordToAnagram[t].push_back(strs[i]);
            else
                wordToAnagram[t] = {strs[i]};
        }

        for (auto it = wordToAnagram.begin(); it != wordToAnagram.end(); ++it)
            anagrams.push_back(it->second);
        return anagrams;
    }
};

int main() {
    string line;
    string str;
    vector<string> strs;
    vector<vector<string>> anagrams;

    std::cout << "Enter the list of strings separated by space. " << std::endl;
    std::getline(std::cin, line);
    std::istringstream stream(line);

    while (stream >> str)
        strs.push_back(str);

    std::cout << "After grouping anagram together: " << std::endl;
    anagrams = Solution::groupAnagrams(strs);

    for (int i = 0; i < anagrams.size(); ++i)
        Solution::printVector(anagrams[i]);

    return 0;
}


