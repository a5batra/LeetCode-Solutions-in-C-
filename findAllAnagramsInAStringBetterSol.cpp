//
// Created by ankitb on 4/1/21.
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
    bool checkAllZero(vector<int>& nums) {
        for (int n : nums) {
            if (n != 0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> arr(26);
        for (char& c : p) {
            arr[c - 'a']++;
        }

        vector<int> result;

        if (s.length() == 0 || p.length() > s.length()) return result;

        int left = 0, right = p.length();

        for (int i = left; i < right; ++i) {
            arr[s[i] - 'a']--;
        }
        if (checkAllZero(arr)) result.push_back(left);

        while (right < s.length()) {
            arr[s[right] - 'a']--;
            arr[s[left] - 'a']++;
            left++;
            right++;
            if (checkAllZero(arr)) result.push_back(left);
        }

        return result;
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