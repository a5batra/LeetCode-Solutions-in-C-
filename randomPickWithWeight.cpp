//
// Created by Ankit Batra on 6/5/20.
//

/* Given an array w of positive integers, where w[i] describes the weight of index i,
 * write a function pickIndex which randomly picks an index in proportion to its weight. */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
    vector<int> weights;
public:
    Solution(vector<int>& w) {
        int n = w.size();
        for (int i = 0; i < n; ++i)
            weights.push_back(w[i]);
    }

    int pickIndex() {
        int n = weights.size();
        int totalWeight = 0;
        for (int i = 0; i < n; ++i)
            totalWeight += weights[i];

        int randomNumber = rand() % totalWeight;
        for (int i = 0; i < n; ++i) {
            if (randomNumber < weights[i]) return i;
            else randomNumber -= weights[i];
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

int main() {
    vector<int> w = {1, 3};
    Solution* obj = new Solution(w);

    for (int i = 0; i < 4; ++i)
        std::cout << obj->pickIndex() << std::endl;

    return 0;
}

