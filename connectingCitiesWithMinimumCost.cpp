//
// Created by Ankit Batra on 4/19/21.
//

/* There are N cities numbered from 1 to N.
 * You are given connections, where each connections[i] = [city1, city2, cost]
 * represents the cost to connect city1 and city2 together.
 * (A connection is bidirectional: connecting city1 and city2 is the same as connecting city2 and city1.)
 * Return the minimum cost so that for every pair of cities, there exists a path of connections
 * (possibly of length 1) that connects those two cities together.
 * The cost is the sum of the connection costs used. If the task is impossible, return -1. */

class Solution {
public:
    static bool customSort(vector<int>& c1, vector<int>& c2) {
        return c1[2] < c2[2];
    }
    int find(int c, vector<int>& parent) {
        if (parent[c] == -1) return c;
        return find(parent[c], parent);
    }
    void unionOp(int u, int v, vector<int>& parent) {
        u = find(u, parent);
        v = find(v, parent);
        parent[u] = v;
    }
    int minimumCost(int N, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), customSort);
        int cost = 0;
        vector<int> parent(N, -1);
        for (vector<int>& c : connections) {
            int u = find(c[0] - 1, parent);
            int v = find(c[1] - 1, parent);
            if (u == v) continue;

            unionOp(u, v, parent);
            cost += c[2];
        }

        int connectedComps = 0;
        for (int p : parent) {
            if (p == -1) connectedComps++;
        }

        return connectedComps == 1 ? cost : -1;
    }
};

int main() {
    return 0;
}
