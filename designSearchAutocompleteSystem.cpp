//
// Created by Ankit Batra on 6/21/21.
//

/* Design a search autocomplete system for a search engine. Users may input a sentence (at least one word and
 * end with a special character '#').
 * You are given a string array sentences and an integer array times both of length n where sentences[i] is a
 * previously typed sentence and times[i] is the corresponding number of times the sentence was typed.
 * For each input character except '#', return the top 3 historical hot sentences that have the same prefix as
 * the part of the sentence already typed.
 * Here are the specific rules:
 * The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
 * The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one).
 * If several sentences have the same hot degree, use ASCII-code order (smaller one appears first).
 * If less than 3 hot sentences exist, return as many as you can.
 * When the input is a special character, it means the sentence ends, and in this case, you need to return an
 * empty list.
 * Implement the AutocompleteSystem class:
 * AutocompleteSystem(String[] sentences, int[] times) Initializes the object with the sentences and times arrays.
 * List<String> input(char c) This indicates that the user typed the character c.
 * Returns an empty array [] if c == '#' and stores the inputted sentence in the system.
 * Returns the top 3 historical hot sentences that have the same prefix as the part of the sentence already typed.
 * If there are fewer than 3 matches, return them all. */

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    unordered_map<string, int> dict;
    TrieNode() {};
};
class AutocompleteSystem {
private:
    string prefix;
    TrieNode* root = new TrieNode();

    struct myCompare {
        bool operator()(pair<int, string>& p1, pair<int, string>& p2) {
            if (p1.first == p2.first) return p1.second > p2.second;
            return p1.first < p2.first;
        }
    };
    void add(string sentence, int time) {
        TrieNode* curr = root;
        for (char& c : sentence) {
            if (!curr->children[c]) curr->children[c] = new TrieNode();
            curr = curr->children[c];
            curr->dict[sentence] += time;
        }
    }
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for (int i = 0; i < sentences.size(); ++i) {
            add(sentences[i], times[i]);
        }
    }

    vector<string> input(char c) {
        vector<string> ans;

        if (c == '#') {
            add(prefix, 1);
            prefix.clear();
            return ans;
        }
        prefix += c;
        TrieNode* curr = root;
        for (char& c : prefix) {
            if (!curr->children[c]) return ans;
            curr = curr->children[c];
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, myCompare> pq;

        for (auto& d : curr->dict) {
            pq.push({d.second, d.first});
        }

        for (int i = 0; i < 3 && !pq.empty(); ++i) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

