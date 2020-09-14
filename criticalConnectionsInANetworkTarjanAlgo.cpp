//
// Created by Ankit Batra on 9/13/20.
//

/* There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a
 * network where connections[i] = [a, b] represents a connection between servers a and b.
 * Any server can reach any other server directly or indirectly through the network.
 * A critical connection is a connection that, if removed, will make some server unable to reach some other server.
 * Return all critical connections in the network in any order. */

// Note: This is a naive solution, and time limit will be exceeded on larger inputs

#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::list;
using std::min;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
    list<int>* graph;
    int time;
    vector<vector<int>> critical;
    int* visitedTimes;
    int* lowTimes;
// minimum of visited time of all vertices reachable from a vertex
public:
    void buildGraph(vector<vector<int>>& connections, list<int>* graph) {
        for (int i = 0; i < connections.size(); ++i) {
            int u = connections[i][0];
            int v = connections[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    void dfs(bool visited[], int currNode, int parentNode) {
        visited[currNode] = true;
        visitedTimes[currNode] = lowTimes[currNode] = time++;

        for (int neighbour : graph[currNode]) {
            if (neighbour == parentNode) continue;
            if (!visited[neighbour]) {
                dfs(visited, neighbour, currNode);
                lowTimes[currNode] = min(lowTimes[currNode], lowTimes[neighbour]);
                if (visitedTimes[currNode] < lowTimes[neighbour]) {
                    critical.push_back({currNode, neighbour});
                }
            }
            else {
                lowTimes[currNode] = min(lowTimes[currNode], visitedTimes[neighbour]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        visitedTimes = new int[n];
        lowTimes = new int[n];
        graph = new list<int>[n];
        buildGraph(connections, graph);
        bool* visited = new bool[n];
        for (int i = 0; i < n; ++i)
            visited[i] = false;
        dfs(visited, 0, -1);

        return critical;
    }

};

int main() {
    int n = 4;
    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>> critical;
    Solution obj;
    critical = obj.criticalConnections(n, connections);

    for (int i = 0; i < critical.size(); ++i)
        std::cout << critical[i][0] << " " << critical[i][1] << std::endl;

    return 0;
}