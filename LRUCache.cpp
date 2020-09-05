//
// Created by Ankit Batra on 9/4/20.
//

/* Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity,
 * it should invalidate the least recently used item before inserting a new item.
 * The cache is initialized with a positive capacity.
 *
 * Follow up:
 * Could you do both operations in O(1) time complexity?*/

#include <iostream>
#include <list>
#include <unordered_map>

using std::list;
using std::unordered_map;

class LRUCache {
    int size = 0;
    unordered_map<int, int> keyToValue;
    list<int> cache;
    unordered_map<int, list<int>::iterator> keyToIterator;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    int get(int key) {
        if (keyToValue.find(key) != keyToValue.end()) {
            cache.erase(keyToIterator[key]);
            cache.push_front(key);
            keyToIterator[key] = cache.begin();
            return keyToValue[key];
        }
        return -1;
    }
    void put(int key, int value) {
        if (keyToValue.size() == size && keyToValue.find(key) == keyToValue.end()) {
            keyToValue.erase(cache.back());
            keyToIterator.erase(cache.back());
            cache.pop_back();
            keyToValue[key] = value;
            cache.push_front(key);
            keyToIterator[key] = cache.begin();
        }
        else {
            if (keyToValue.find(key) != keyToValue.end())
                cache.erase(keyToIterator[key]);
            cache.push_front(key);
            keyToIterator[key] = cache.begin();
            keyToValue[key] = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache* obj = new LRUCache(2);
    obj->put(2, 2);
    obj->put(1, 1);
    obj->put(2, 3);
    obj->put(4, 1);
    int param_1 = obj->get(1);
    int param_2 = obj->get(2);

    std::cout << param_1 << " " << param_2 << std::endl;

    return 0;
}