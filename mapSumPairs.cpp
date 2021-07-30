//
// Created by Ankit Batra on 7/30/21.
//

/* Implement the MapSum class:
 * MapSum() Initializes the MapSum object.
 * void insert(String key, int val) Inserts the key-val pair into the map.
 * If the key already existed, the original key-value pair will be overridden to the new one.
 * int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the prefix. */

class MapSum {
    unordered_map<string, int> dict;
    struct TrieNode {
        char letter;
        int val;
        TrieNode* children[26];
    };
    TrieNode* getNode(int idx, int v) {
        TrieNode* node = new TrieNode;
        node->letter = idx + 'a';
        node->val = v;
        for (int i = 0; i < 26; ++i) {
            node->children[i] = nullptr;
        }
        return node;
    }
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = getNode('/' - 'a', 0);
    }

    void insert(string key, int val) {
        TrieNode* curr = root;
        int idx = 0;
        bool keyExist = false;
        if (dict.count(key)) keyExist = true;
        for (char& c : key) {
            idx = c - 'a';
            if (!curr->children[idx]) curr->children[idx] = getNode(idx, val);
            else {
                if (keyExist) {
                    curr->children[idx]->val = val - dict[key] + curr->children[idx]->val;
                }
                else {
                    curr->children[idx]->val += val;
                }
            }
            curr = curr->children[idx];
        }
        dict[key] = val;
    }

    int sum(string prefix) {
        TrieNode* curr = root;
        int idx = 0;
        for (char& c : prefix) {
            idx = c - 'a';
            if (!curr->children[idx]) return 0;
            curr = curr->children[idx];
        }

        return curr->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

