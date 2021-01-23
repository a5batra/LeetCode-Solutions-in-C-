//
// Created by Ankit Batra on 1/23/21.
//

/* Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
 * Implement the LRUCache class:
 * LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
 * int get(int key) Return the value of the key if the key exists, otherwise return -1.
 * void put(int key, int value) Update the value of the key if the key exists.
 * Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
 * Follow up:
 * Could you do get and put in O(1) time complexity? */

#include <iostream>
#include <list>
#include <unordered_map>

using std::list;
using std::unordered_map;

class LRUCache {
    unordered_map<int, int> keyToVal;
    list<int> cache;
    unordered_map<int, list<int>::iterator> keyToIter;
    int sz;
public:
    LRUCache(int capacity) {
        sz = capacity;
    }

    int get(int key) {
        if (keyToVal.find(key) == keyToVal.end()) return -1;

        int val = keyToVal[key];
        cache.erase(keyToIter[key]);
        cache.push_front(key);
        keyToIter[key] = cache.begin();

        return val;
    }

    void put(int key, int value) {
        if (sz <= 0) return;
        if (get(key) != -1) {
            keyToVal[key] = value;
            return;
        }

        if (sz == keyToVal.size()) {
            // remove lru element
            int keyToRemove = cache.back();
            cache.pop_back();
            keyToVal.erase(keyToRemove);
            keyToIter.erase(keyToRemove);
        }

        cache.push_front(key);
        keyToVal[key] = value;
        keyToIter[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
