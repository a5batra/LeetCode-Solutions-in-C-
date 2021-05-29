//
// Created by Ankit Batra on 5/26/21.
//

/* Given two vectors of integers v1 and v2, implement an iterator to return their elements alternately.
 * Implement the ZigzagIterator class:
 * ZigzagIterator(List<int> v1, List<int> v2) initializes the object with the two vectors v1 and v2.
 * boolean hasNext() returns true if the iterator still has elements, and false otherwise.
 * int next() returns the current element of the iterator and moves the iterator to the next element. */

#include <queue>
#include <vector>

using std::pair;
using std::queue;
using std::vector;

class ZigzagIterator {
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.size())
            q.push(make_pair(v1.begin(), v1.end()));
        if (v2.size())
            q.push(make_pair(v2.begin(), v2.end()));
    }

    int next() {
        pair<vector<int>::iterator, vector<int>::iterator> p = q.front();
        q.pop();
        auto startIt = p.first, endIt = p.second;
        int val = *startIt;
        ++startIt;
        if (startIt != endIt) q.push(make_pair(startIt, endIt));
        return val;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

