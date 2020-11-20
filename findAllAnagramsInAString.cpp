//
// Created by Ankit Batra on 11/19/20.
//

/* Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
 * Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
 * The order of output does not matter. */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static bool areAllZeroes(vector<int>& charCount) {
        for (int i = 0; i < 26; ++i) {
            if (charCount[i] != 0) return false;
        }
        return true;
    }
    static vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<int> indices;
        if (n == 0 || m > n) return indices;

        vector<int> charCount(26);
        int i = 0;

        for (; i < m; ++i) {
            charCount[p[i] - 'a']++;
            charCount[s[i] - 'a']--;
        }

        for (; i < n; ++i) {
            if (areAllZeroes(charCount)) {
                indices.push_back(i - m);
            }
            charCount[s[i - m] - 'a']++;
            charCount[s[i] - 'a']--;
        }

        return indices;
    }
};

int main() {
    string s, p;
    vector<int> indices;

    std::cout << "Enter the string s: " << std::endl;
    std::cin >> s;

    std::cout << "Enter the string p: " << std::endl;
    std::cin >> p;

    indices = Solution::findAnagrams(s, p);

    std::cout << "Indices are: " << std::endl;
    for (int i = 0; i < indices.size(); ++i) {
        std::cout << indices[i] << " ";
    }

    return 0;
}

