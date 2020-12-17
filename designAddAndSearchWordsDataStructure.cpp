//
// Created by Ankit Batra on 12/11/20.
//

/* Design a data structure that supports adding new words and finding if a string matches any previously added string.
 * Implement the WordDictionary class:
 * WordDictionary() Initializes the object.
 * void addWord(word) Adds word to the data structure, it can be matched later.
 * bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise.
 * word may contain dots '.' where dots can be matched with any letter. */

#include <iostream>
#include <string>

class WordDictionary {
    struct TrieNode {
        char val;
        int count = 0;
        int endsHere = 0;
        TrieNode* child[26];
    };
    TrieNode* getNode(int idx) {
        TrieNode* node = new TrieNode;
        node->val = 'a' + idx;
        node->count = node->endsHere = 0;
        for (int i = 0; i < 26; ++i) {
            node->child[i] = nullptr;
        }
        return node;
    }
    TrieNode* root = getNode('/' - 'a');

    void trieInsert(string word) {
        TrieNode* curr = root;
        int idx = 0;
        for (char c : word) {
            idx = c - 'a';
            if (curr->child[idx] == nullptr) curr->child[idx] = getNode(idx);
            curr->child[idx]->count += 1;
            curr = curr->child[idx];
        }
        curr->endsHere += 1;
    }
    bool trieSearch(string word, TrieNode* curr, int pos, int n) {
        if (word[pos] == '.') {
            bool result = false;
            TrieNode* current = curr;
            for (int i = 0; i < 26; ++i) {
                if (pos == n - 1 && curr->child[i]) {
                    current = curr->child[i];
                    result |= current->endsHere > 0 ? true : false;
                }
                else if (curr->child[i] && trieSearch(word, curr->child[i], pos + 1, n))
                    return true;
            }
            return result;
        }
        else if (curr->child[word[pos] - 'a']) {
            if (pos == n - 1) {
                curr = curr->child[word[pos] - 'a'];
                return curr->endsHere > 0 ? true : false;
            }
            return trieSearch(word, curr->child[word[pos] - 'a'], pos+1, n);
        }
        return false;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
    }

    void addWord(string word) {
        trieInsert(word);
    }

    bool search(string word) {
        return trieSearch(word, root, 0, word.length());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {

    return 0;
}
