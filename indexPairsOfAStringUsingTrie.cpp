//
// Created by Ankit Batra on 5/20/21.
//

/* Given a text string and words (a list of strings), return all index pairs [i, j] so that the substring
 * text[i]...text[j] is in the list of words. */

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
    vector<vector<int>> ans;
    struct TrieNode {
        char val;
        int endsHere;
        TrieNode* children[26];
    };
    TrieNode* getNode(int idx) {
        TrieNode* node = new TrieNode;
        node->val = idx + 'a';
        node->endsHere = 0;
        for (int i = 0; i < 26; ++i) {
            node->children[i] = nullptr;
        }
        return node;
    }
    TrieNode* root;
public:
    Solution() {
        root = getNode('/' - 'a');
    }
    void insert(string& word) {
        int idx = 0;
        TrieNode* curr = root;
        for (char& c : word) {
            idx = c - 'a';
            if (!curr->children[idx]) curr->children[idx] = getNode(idx);
            curr = curr->children[idx];
        }
        curr->endsHere += 1;
    }
    void search(string& text, int& i) {
        TrieNode* curr = root;
        int j = i;
        while (j < text.length() && curr->children[text[j] - 'a']) {
            if (curr->endsHere)
                ans.push_back({i, j - 1});
            curr = curr->children[text[j] - 'a'];
            j++;
        }
        if (curr->endsHere)
            ans.push_back({i, j - 1});
    }
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        for (string& w : words)
            insert(w);

        for (int i = 0; i < text.length(); ++i)
            search(text, i);

        return ans;
    }
};

