//
// Created by Ankit Batra on 7/26/21.
//

/* A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of
 * words beginWord -> s1 -> s2 -> ... -> sk such that:
 * Every adjacent pair of words differs by a single letter.
 * Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
 * sk == endWord
 * Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation
 * sequences from beginWord to endWord, or an empty list if no such sequence exists.
 * Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk]. */

class Solution {
    struct Node {
        string word;
        Node* prev;
        Node(string c) : word(c){
            prev = nullptr;
        }
        Node(string c, Node* p) : word(c), prev(p) {};
    };
    vector<vector<string>> ans;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.count(endWord) == 0) return ans;

        queue<Node*> q;
        q.push(new Node(beginWord));
        unordered_set<string> seen;
        seen.insert(beginWord);

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                Node* curr = q.front();
                q.pop();
                for (string& neighbor : getNeighbors(curr->word, wordSet)) {
                    Node* neigh = new Node(neighbor, curr);
                    if (neighbor == endWord) {
                        addNode(neigh);
                        break;
                    }
                    q.push(neigh);
                }
            }
            if (ans.size() > 0) break;
        }

        return ans;
    }
    vector<string> getNeighbors(string& word, unordered_set<string>& wordSet) {
        wordSet.erase(word);
        vector<string> neighbors;
        for (char& c : word) {
            char temp = c;
            for (int t = 'a'; t <= 'z'; ++t) {
                if (t == temp) continue;
                c = t;
                if (wordSet.count(word)) {
                    neighbors.push_back(word);
                }
            }
            c = temp;
        }

        return neighbors;
    }
    void addNode(Node* node) {
        vector<string> path;
        while (node != nullptr) {
            path.push_back(node->word);
            node = node->prev;
        }
        reverse(path.begin(), path.end());
        ans.push_back(path);
    }
};

