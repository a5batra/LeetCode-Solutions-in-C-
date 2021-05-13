//
// Created by Ankit Batra on 5/12/21.
//

/* Given an array of strings products and a string searchWord.
 * We want to design a system that suggests at most three product names from products after each character of
 * searchWord is typed. Suggested products should have common prefix with the searchWord.
 * If there are more than three products with a common prefix return the three lexicographically minimums products.
 * Return list of lists of the suggested products after each character of searchWord is typed. */

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
    vector<vector<string>> ans;
    struct TrieNode {
        char val;
        TrieNode* children[26];
        vector<int> idxs;
        bool endsHere;
    };
    TrieNode* getNode(int idx) {
        TrieNode* node = new TrieNode;
        node->val = idx + 'a';
        for (int i = 0; i < 26; ++i) {
            node->children[i] = nullptr;
        }
        return node;
    }
    TrieNode* root = getNode('/' - 'a');
    void insert(string word, int pIdx) {
        int i = 0;
        TrieNode* curr = root;
        for (char& c : word) {
            i = c - 'a';
            if (!curr->children[i]) {
                curr->children[i] = getNode(i);
                curr->children[i]->idxs.push_back(pIdx);
            }
            curr->children[i]->idxs.push_back(pIdx);
            curr = curr->children[i];
        }
        curr->endsHere = true;
        curr->idxs.push_back(pIdx);
    }
    vector<int> search(string word) {
        int i = 0;
        vector<int> arr;
        unordered_set<int> st;
        TrieNode* curr = root;
        for (char& c : word) {
            i = c - 'a';
            if (!curr->children[i]) {
                return arr;
            }
            curr = curr->children[i];
        }
        for (int j : curr->idxs)
            st.insert(j);
        for (auto index : st)
            arr.push_back(index);

        return arr;
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        string w = "";
        int n = products.size();
        for (int i = 0; i < n; ++i)
            insert(products[i], i);

        int maxNums = 3;
        for (char& c : searchWord) {
            w += c;
            vector<int> idxs = search(w);
            vector<string> res;
            for (int i : idxs)
                res.push_back(products[i]);
            sort(res.begin(), res.end());
            vector<string> top3;
            if (res.size() < maxNums) maxNums = res.size();
            for (int k = 0; k < maxNums; ++k) {
                top3.push_back(res[k]);
            }
            ans.push_back(top3);
        }
        return ans;
    }
};

