//
// Created by Ankit Batra on 5/23/21.
//

/* Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.
 * Note:
 * The same word in the dictionary may be reused multiple times in the segmentation.
 * You may assume the dictionary does not contain duplicate words. */

class Solution {
    vector<string> ans;
    unordered_set<string> wordSet;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string curr = "";
        for (string& w : wordDict) wordSet.insert(w);

        helper(s, curr);

        return ans;
    }

    void helper(string s, string curr) {
        if (s.length() == 0) {
            curr.pop_back();
            ans.push_back(curr);
            return;
        }

        for (int i = 1; i <= s.length(); ++i) {
            string left = s.substr(0, i);
            if (wordSet.count(left)) {
                string right = s.substr(i);
                helper(right, curr + left + ' ');
            }
        }
    }
};

