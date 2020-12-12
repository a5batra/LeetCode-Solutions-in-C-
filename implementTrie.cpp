//
// Created by Ankit Batra on 12/10/20.
//

// Implement a trie with insert, search, and startsWith methods.

#include <iostream>
#include <string>

using std::string;

class Trie {
    struct TrieNode {
        char val;
        int count = 0;
        int endsHere = 0;
        TrieNode* child[26];
    };
    TrieNode* root;

    TrieNode* getNode(int idx) {
        TrieNode* node = new TrieNode;
        node->count = node->endsHere = 0;
        node->val = 'a' + idx;
        for (int i = 0; i < 26; ++i) {
            node->child[i] = nullptr;
        }
        return node;
    }

public:
    /** Initialize your data structure here. */
    Trie() {
        root = getNode('/' - 'a');
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        int idx = 0;
        for (char c : word) {
            idx = c - 'a';
            if (curr->child[idx] == nullptr) {
                curr->child[idx] = getNode(idx);
            }
            curr->child[idx]->count += 1;
            curr = curr->child[idx];
        }
        curr->endsHere += 1;
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        int idx = 0;
        for (char c : word) {
            idx = c - 'a';
            if (curr->child[idx] == nullptr) return false;
            curr = curr->child[idx];
        }
        return curr->endsHere > 0;
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        int idx = 0;
        for (char c : prefix) {
            idx = c - 'a';
            if (curr->child[idx] == nullptr) return false;
            curr = curr->child[idx];
        }
        return curr->count > 0;
    }
};