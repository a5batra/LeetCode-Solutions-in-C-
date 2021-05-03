//
// Created by Ankit Batra on 5/2/21.
//

/* Design a Leaderboard class, which has 3 functions:
 * addScore(playerId, score): Update the leaderboard by adding score to the given player's score.
 * If there is no player with such id in the leaderboard, add him to the leaderboard with the given score.
 * top(K): Return the score sum of the top K players.
 * reset(playerId): Reset the score of the player with the given id to 0 (in other words erase it from the
 * leaderboard). It is guaranteed that the player was added to the leaderboard before calling this function.
 * Initially, the leaderboard is empty. */

#include <queue>
#include <unordered_map>
#include <vector>

using std::priority_queue;
using std::unordered_map;
using std::vector;

class Leaderboard {
    unordered_map<int, int> dict;
public:
    Leaderboard() {

    }

    void addScore(int playerId, int score) {
        dict[playerId] += score;
    }

    int top(int K) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0;
        for (auto it : dict) {
            pq.push(it.second);
            if (pq.size() > K)
                pq.pop();
        }
        while (!pq.empty()) {
            int s = pq.top();
            pq.pop();
            sum += s;
        }
        return sum;
    }

    void reset(int playerId) {
        dict.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */

