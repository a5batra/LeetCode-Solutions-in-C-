//
// Created by Ankit Batra on 9/15/20.
//

/* Given a non-empty list of words, return the k most frequent elements.
 * Your answer should be sorted by frequency from highest to lowest.
 * If two words have the same frequency, then the word with the lower alphabetical order comes first.
 *
 * Follow up:
 * Try to solve it in O(n log k) time and O(n) extra space.*/

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using std::pair;
using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
    static bool customSort(pair<string, int>& word1, pair<string, int>& word2) {
        if (word1.second != word2.second)
            return word1.second > word2.second;
        int cmp = (word2.first).compare(word1.first);
        if (cmp > 0)
            return word1 < word2;
        return word2 > word1;
    }
    static vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordToCount;
        vector<string> kFrequent;
        int n = words.size();
        if (n == 0) return kFrequent;

        for (int i = 0; i < n; ++i) {
            if (wordToCount.find(words[i]) != wordToCount.end())
                wordToCount[words[i]] += 1;
            else
                wordToCount[words[i]] = 1;
        }

        vector<pair<string, int>> wordFreq;

        for (auto it = wordToCount.begin(); it != wordToCount.end(); ++it) {
            wordFreq.push_back(make_pair(it->first, it->second));
        }

        sort(wordFreq.begin(), wordFreq.end(), customSort);


        for (int i = 0; i < k; ++i) {
            kFrequent.push_back(wordFreq[i].first);
        }
        return kFrequent;
    }
};

int main() {
    vector<string> words;
    vector<string> kFrequent;
    int k;
    string word;
    string line;

    std::cout << "Enter the list of words separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> word)
        words.push_back(word);

    std::cout << "Enter the value of k: " << std::endl;
    std::cin >> k;

    kFrequent = Solution::topKFrequent(words, k);

    for (int i = 0; i < kFrequent.size(); ++i)
        std::cout << kFrequent[i] << " ";

    return 0;
}