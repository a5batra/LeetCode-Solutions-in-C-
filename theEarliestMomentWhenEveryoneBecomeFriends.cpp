//
// Created by Ankit Batra on 5/1/21.
//

/* In a social group, there are N people, with unique integer ids from 0 to N-1.
 * We have a list of logs, where each logs[i] = [timestamp, id_A, id_B] contains a non-negative integer timestamp,
 * and the ids of two different people.
 * Each log represents the time in which two different people became friends.
 * Friendship is symmetric: if A is friends with B, then B is friends with A.
 * Let's say that person A is acquainted with person B if A is friends with B, or A is a friend of someone
 * acquainted with B.
 * Return the earliest time for which every person became acquainted with every other person.
 * Return -1 if there is no such earliest time. */

#include <vector>

using std::vector;

class Solution {
public:
    static bool customSort(vector<int>& l1, vector<int>& l2) {
        return l1[0] < l2[0];
    }

    bool areAllFriends(vector<int>& parent) {
        int count = 0;
        for (int p : parent) {
            if (p == -1) count++;
            if (count > 1) return false;
        }
        return count == 1;
    }

    int find(vector<int>& parent, int u) {
        if (parent[u] == -1) return u;

        return parent[u] = find(parent, parent[u]);
    }

    void unionOp(vector<int>& parent, int u, int v) {
        int parentU = find(parent, u);
        int parentV = find(parent, v);
        parent[parentU] = parentV;
    }

    int earliestAcq(vector<vector<int>>& logs, int N) {
        vector<int> parent(N, -1);
        sort(logs.begin(), logs.end(), customSort);

        int ans = -1;
        int prevTime = 0;

        for (vector<int>& log : logs) {
            if (areAllFriends(parent)) {
                ans = prevTime;
                break;
            }
            int time = log[0];
            int u = log[1], v = log[2];
            int parentU = find(parent, u);
            int parentV = find(parent, v);
            if (parentU == parentV) continue;

            unionOp(parent, u, v);

            prevTime = time;
        }

        if (areAllFriends(parent)) ans = prevTime;

        return ans;

    }
};

