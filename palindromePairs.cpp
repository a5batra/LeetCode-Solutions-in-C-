//
// Created by Ankit Batra on 6/13/21.
//

/* Given a list of unique words, return all the pairs of the distinct indices (i, j) in the given list, so that the
 * concatenation of the two words words[i] + words[j] is a palindrome. */

class Solution {
public:
    bool isPalindrome(string& word) {
        int len = word.length();

        for (int i = 0; i < len / 2 + 1; ++i) {
            if (word[i] != word[len - i - 1]) return false;
        }

        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> dict;
        vector<vector<int>> ans;

        for (int i = 0; i < n; ++i) {
            dict[words[i]] = i;
        }

        // When we have an empty string
        if (dict.count("")) {
            for (int i = 0; i < n; ++i) {
                if (i != dict[""] && isPalindrome(words[i])) {
                    ans.push_back({i, dict[""]});
                    ans.push_back({dict[""], i});
                }
            }
        }

        // reflection exits
        for (int i = 0; i < n; ++i) {
            string reversedWord = words[i];
            reverse(reversedWord.begin(), reversedWord.end());
            if (dict.count(reversedWord) && dict[reversedWord] != i) {
                ans.push_back({i, dict[reversedWord]});
            }
        }

        // checking by making a cut
        for (int i = 0; i < n; ++i) {
            string word = words[i];
            for (int cut = 1; cut < word.length(); ++cut) {
                string left = word.substr(0, cut);
                string right = word.substr(cut);
                if (isPalindrome(left)) {
                    string reversedRight = right;
                    reverse(reversedRight.begin(), reversedRight.end());
                    if (dict.count(reversedRight)) ans.push_back({dict[reversedRight], i});
                }
                if (isPalindrome(right)) {
                    string reversedLeft = left;
                    reverse(reversedLeft.begin(), reversedLeft.end());
                    if (dict.count(reversedLeft)) ans.push_back({i, dict[reversedLeft]});
                }
            }
        }

        return ans;
    }
};

