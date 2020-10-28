//
// Created by Ankit Batra on 10/28/20.
//

/* Given a string S, check if the letters can be rearranged so that two characters
 * that are adjacent to each other are not the same.
 * If possible, output any possible result.  If not possible, return the empty string. */

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using std::pair;
using std::priority_queue;
using std::string;
using std::unordered_map;
using std::vector;

class myCompare {
public:
    bool operator()(pair<char, int>& p1, pair<char, int>& p2) {
        return p1.second < p2.second;
    }
};

class Solution {
public:
    static string reorganizeString(string S) {
        if (S.length() == 0) return "";

        unordered_map<char, int> charCount;
        string res = "";

        for (int i = 0; i < S.length(); ++i) {
            if (charCount.find(S[i]) != charCount.end()) {
                charCount[S[i]] += 1;
            }
            else charCount[S[i]] = 1;
        }

        priority_queue<pair<char, int>, vector<pair<char, int>>, myCompare> pq;

        for (auto it = charCount.begin(); it != charCount.end(); ++it) {
            pq.push({it->first, it->second});
        }

        while (pq.size() > 1) {
            pair<char, int> p1 = pq.top();
            pq.pop();
            char curr = p1.first;
            int currCount = p1.second;
            res += curr;
            pair<char, int> p2 = pq.top();
            pq.pop();
            char next = p2.first;
            int nextCount = p2.second;
            res += next;

            if (--currCount > 0) {
                pq.push({curr, currCount});
            }
            if (--nextCount > 0) {
                pq.push({next, nextCount});
            }
        }

        if (!pq.empty()) {
            if (pq.top().second > 1) return "";
            else res += pq.top().first;
            pq.pop();
        }

        return res;
    }
};


int main() {
    string S;

    std::cout << "Enter the string S: " << std::endl;
    std::cin >> S;

    std::cout << "Resulting string is: " << Solution::reorganizeString(S);
}