//
// Created by Ankit Batra on 5/29/21.
//

/* You are given two 0-indexed integer arrays servers and tasks of lengths n​​​​​​ and m​​​​​​ respectively.
 * servers[i] is the weight of the i​​​​​​th​​​​ server, and tasks[j] is the time needed to process the j​​​​​​th​​​​ task in seconds.
 * You are running a simulation system that will shut down after all tasks are processed.
 * Each server can only process one task at a time. You will be able to process the jth task starting from the
 * jth second beginning with the 0th task at second 0.
 * To process task j, you assign it to the server with the smallest weight that is free,
 * and in case of a tie, choose the server with the smallest index.
 * If a free server gets assigned task j at second t,​​​​​​ it will be free again at the second t + tasks[j].
 * If there are no free servers, you must wait until one is free and execute the free tasks as soon as possible.
 * If multiple tasks need to be assigned, assign them in order of increasing index.
 * You may assign multiple tasks at the same second if there are multiple free servers.
 * Build an array ans​​​​ of length m, where ans[j] is the index of the server the j​​​​​​th task will be assigned to.
 * Return the array ans​​​​. */

#include <queue>
#include <vector>

using std::priority_queue;
using std::queue;
using std::vector;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freePq, busyPq;

        int n = servers.size();
        for (int i = 0; i < n; ++i) freePq.push({servers[i], i});

        int m = tasks.size();
        vector<int> ans(m);


        int currTime = 0;
        for (int i = 0; i < m; ++i) {
            if (freePq.empty()) currTime = max(i, busyPq.top().first);
            else currTime = max(i, currTime);

            while (!busyPq.empty() && busyPq.top().first <= currTime) {
                int idx = busyPq.top().second;
                busyPq.pop();
                freePq.push({servers[idx], idx});
            }

            pair<int, int> p = freePq.top();
            freePq.pop();
            int sIdx = p.second;
            ans[i] = sIdx;
            busyPq.push({currTime + tasks[i], sIdx});
        }

        return ans;
    }
};

