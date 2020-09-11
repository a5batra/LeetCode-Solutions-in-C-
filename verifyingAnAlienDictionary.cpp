//
// Created by Ankit Batra on 9/11/20.
//

/* In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order.
 * The order of the alphabet is some permutation of lowercase letters.
 * Given a sequence of words written in the alien language, and the order of the alphabet,
 * return true if and only if the given words are sorted lexicographicaly in this alien language. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static bool isAlienSorted(vector<string>& words, string order) {
        vector<int> idx(26);
        int n = words.size();
        int flag = 1;

        for (int i = 0; i < order.length(); ++i)
            idx[order[i] - 'a'] = i;

        for (int i = 0; i < n - 1; ++i) {
            string word1 = words[i];
            string word2 = words[i + 1];

            for (int j = 0; j < std::min(word1.length(), word2.length()); ++j) {
                if (word1[j] != word2[j]) {
                    if (idx[word1[j] - 'a'] > idx[word2[j] - 'a']) return false;
                    else {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag != 0 && word1.length() > word2.length()) return false;
            flag = 1;
        }
        return true;
    }
};

int main() {
    string line;
    string word;
    string order;
    vector<string> words;

    std::cout << "Enter the string of words separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> word)
        words.push_back(word);

    std::cout << "Enter the order of alphabets: " << std::endl;
    std::cin >> order;

    std::cout << "Result: " << Solution::isAlienSorted(words, order);
    return 0;
}