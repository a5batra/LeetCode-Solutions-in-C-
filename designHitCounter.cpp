//
// Created by Ankit Batra on 5/4/21.
//


/* Design a hit counter which counts the number of hits received in the past 5 minutes (i.e., the past 300 seconds).
 * Your system should accept a timestamp parameter (in seconds granularity), and you may assume that calls are
 * being made to the system in chronological order (i.e., timestamp is monotonically increasing).
 * Several hits may arrive roughly at the same time.
 * Implement the HitCounter class:
 * HitCounter() Initializes the object of the hit counter system.
 * void hit(int timestamp) Records a hit that happened at timestamp (in seconds).
 * Several hits may happen at the same timestamp.
 * int getHits(int timestamp) Returns the number of hits in the past 5 minutes from timestamp
 * (i.e., the past 300 seconds). */

#include <queue>

using std::queue;

class HitCounter {
    queue<int> q;
public:
    /** Initialize your data structure here. */
    HitCounter() {

    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        q.push(timestamp);
        while (!q.empty() && timestamp - q.front() > 300) q.pop();
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int minTime = timestamp - 300;

        while (!q.empty() && q.front() <= minTime) q.pop();

        return q.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
