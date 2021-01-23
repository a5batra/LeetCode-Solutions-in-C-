//
// Created by Ankit Batra on 1/21/21.
//

/* Design and implement a data structure for Least Frequently Used (LFU) cache.
 * Implement the LFUCache class:
 * LFUCache(int capacity) Initializes the object with the capacity of the data structure.
 * int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
 * void put(int key, int value) Sets or inserts the value if the key is not already present.
 * When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item.
 * For this problem, when there is a tie (i.e., two or more keys with the same frequency),
 * the least recently used key would be evicted.
 * Notice that the number of times an item is used is the number of calls to the get and put functions for that
 * item since it was inserted. This number is set to zero when the item is removed. */

#include <list>
#include <unordered_map>

using std::list;
using std::pair;
using std::unordered_map;

class LFUCache {
    unordered_map<int, pair<int, int>> keyToValFreq;
    unordered_map<int, list<int>::iterator> keyToIter;
    unordered_map<int, list<int>> freqToKeyList;
    int sz, minFreq;
public:
    LFUCache(int capacity) {
        sz = capacity;
        minFreq = 0;
    }
    int get(int key) {
        if (keyToValFreq.find(key) == keyToValFreq.end()) return -1;

        int value = keyToValFreq[key].first;
        int freq = keyToValFreq[key].second;
        freqToKeyList[freq].erase(keyToIter[key]);
        freqToKeyList[freq + 1].push_front(key);
        keyToIter[key] = freqToKeyList[freq + 1].begin();
        keyToValFreq[key].second++;

        if(!freqToKeyList[minFreq].size()) minFreq++;

        return value;
    }
    void put(int key, int value) {
        if (sz <= 0) return;
        if (get(key) != -1) {
            keyToValFreq[key].first = value;
            return;
        }

        if (sz == keyToValFreq.size()) {
            // remove the element lfu -> lru
            int keyToRemove = freqToKeyList[minFreq].back();
            freqToKeyList[minFreq].pop_back();
            keyToIter.erase(keyToRemove);
            keyToValFreq.erase(keyToRemove);
        }

        keyToValFreq[key] = {value, 1};
        minFreq = 1;
        freqToKeyList[minFreq].push_front(key);
        keyToIter[key] = freqToKeyList[minFreq].begin();
    }
};

int main() {
    return 0;
}