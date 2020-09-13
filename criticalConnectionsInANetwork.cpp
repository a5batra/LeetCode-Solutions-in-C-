//
// Created by Ankit Batra on 9/11/20.
//

/* There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a
 * network where connections[i] = [a, b] represents a connection between servers a and b.
 * Any server can reach any other server directly or indirectly through the network.
 * A critical connection is a connection that, if removed, will make some server unable to reach some other server.
 * Return all critical connections in the network in any order. */

// Note: This is a naive solution, and time limit will be exceeded on larger inputs

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
public:
    static unordered_map<int, unordered_set<int>> buildGraph(int n, vector<vector<int>>& connections) {
        unordered_map<int, unordered_set<int>> adjacencyList;
        for (int i = 0; i < connections.size(); ++i) {
            // cout << connections[i][0] << " " << connections[i][1] << endl;
            adjacencyList[connections[i][0]].insert(connections[i][1]);
            adjacencyList[connections[i][1]].insert(connections[i][0]);
        }
        // for (auto it = adjacencyList.begin(); it != adjacencyList.end(); ++it) {
        //     cout << "Vertex: " << it->first << " " << endl;
        //     cout << "Elements: " << endl;
        //     for (auto iterator = it->second.begin(); iterator != it->second.end(); ++ iterator) {
        //         cout << *iterator << " ";
        //     }
        //     cout << endl;
        // }
        return adjacencyList;
    }

    static void DFS(int& currNode, int parentNode, vector<bool>& visited, unordered_map<int, unordered_set<int>>& graph, int& num) {
        visited[currNode] = true;
        num += 1;

        for (auto it = graph[currNode].begin(); it != graph[currNode].end(); ++it) {
            int neighbour = *it;
            if (neighbour == parentNode) continue;
            if (!visited[neighbour]) {
                DFS(neighbour, currNode, visited, graph, num);
            }

        }
    }

    static int removeConnectionAndDFS(int n, unordered_map<int, unordered_set<int>>& graph, vector<int>& connection) {
        graph[connection[0]].erase(connection[1]);
        graph[connection[1]].erase(connection[0]);
        int num = 0;
        vector<bool> visited(n, false);
        DFS(connection[0], -1, visited, graph, num);
        graph[connection[0]].insert(connection[1]);
        graph[connection[1]].insert(connection[0]);

        return num;
    }

    static vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, unordered_set<int>> adjacencyList;
        vector<vector<int>> critical;
        if (n == 0) return critical;

        adjacencyList = buildGraph(n, connections);

        for (int i = 0; i < connections.size(); ++i) {
            vector<int> connection = connections[i];
            int num = removeConnectionAndDFS(n, adjacencyList, connection);
            if (num != n) {
                critical.push_back(connection);
            }
        }
        return critical;
    }
};

int main() {
    int n = 4;
    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>> critical;

    critical = Solution::criticalConnections(n, connections);

    for (int i = 0; i < critical.size(); ++i)
        std::cout << critical[i][0] << " " << critical[i][1] << std::endl;

    return 0;
}