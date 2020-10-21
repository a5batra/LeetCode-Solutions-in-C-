//
// Created by Ankit Batra on 10/18/20.
//

/* Given a reference of a node in a connected undirected graph.
 * Return a deep copy (clone) of the graph.
 * Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.
 * Test case format:
 * For simplicity sake, each node's value is the same as the node's index (1-indexed).
 * For example, the first node with val = 1, the second node with val = 2, and so on.
 * The graph is represented in the test case using an adjacency list.
 * Adjacency list is a collection of unordered lists used to represent a finite graph.
 * Each list describes the set of neighbors of a node in the graph.
 * The given node will always be the first node with val = 1.
 * You must return the copy of the given node as a reference to the cloned graph. */

#include <queue>
#include <unordered_map>
#include <vector>

using std::queue;
using std::unordered_map;
using std::vector;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    static Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;
        unordered_map<Node*, Node*> visited;

        visited[node] = new Node(node->val);
        queue<Node*> q;
        q.push(node);

        while(!q.empty()) {
            Node* currNode = q.front();
            q.pop();
            for (auto neighbor : currNode->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                visited[currNode]->neighbors.push_back(visited[neighbor]);
            }
        }
        return visited[node];
    }
};



