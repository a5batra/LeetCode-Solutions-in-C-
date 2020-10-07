//
// Created by Ankit Batra on 10/6/20.
//

/* Design a HashMap without using any built-in hash table libraries.
 * To be specific, your design should include these functions:
 * put(key, value) : Insert a (key, value) pair into the HashMap.
 * If the value already exists in the HashMap, update the value.
 * get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
 * remove(key) : Remove the mapping for the value key if this map contains the mapping for the key. */

#include <iostream>
#include <list>
#include <vector>

using std::list;
using std::make_pair;
using std::pair;
using std::vector;

class MyHashMap {
    int maxKey;
    vector<list<pair<int, int>>> buckets;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        maxKey = 2069;
        buckets = vector<list<pair<int, int>>>(maxKey, list<pair<int, int>>{});
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        // cout << "Key: " << key << endl;
        int hashKey = key % maxKey;
        for (auto it = buckets[hashKey].begin(); it != buckets[hashKey].end(); ++it) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }
        buckets[hashKey].push_back(make_pair(key, value));
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hashKey = key % maxKey;
        for (auto it = buckets[hashKey].begin(); it != buckets[hashKey].end(); ++it) {
            if (it->first == key)
                return it->second;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hashKey = key % maxKey;

        for (auto it = buckets[hashKey].begin(); it != buckets[hashKey].end(); ++it) {
            if (it->first == key) {
                buckets[hashKey].remove(*it);
                return;
            }
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main() {
    MyHashMap* obj = new MyHashMap();
    obj->put(1, 1);
    obj->put(2, 2);

    std::cout << obj->get(1) << std::endl;
    std::cout << obj->get(3) << std::endl;

    obj->put(2, 1);
    std::cout << obj->get(2) << std::endl;
    obj->remove(2);
    std::cout << obj->get(2) << std::endl;

    return 0;
}
