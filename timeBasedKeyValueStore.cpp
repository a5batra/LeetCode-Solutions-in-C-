//
// Created by Ankit Batra on 6/6/21.
//

/* Create a timebased key-value store class TimeMap, that supports two operations.
 * 1. set(string key, string value, int timestamp)
 * Stores the key and value, along with the given timestamp.
 * 2. get(string key, int timestamp)
 * Returns a value such that set(key, value, timestamp_prev) was called previously,
 * with timestamp_prev <= timestamp.
 * If there are multiple such values, it returns the one with the largest timestamp_prev.
 * If there are no values, it returns the empty string (""). */

class TimeMap {
    unordered_map<string, vector<pair<int, string>>> dict;
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        dict[key].push_back(make_pair(timestamp, value));
    }

    int binarySearch(vector<pair<int, string>>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;
        int mid = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (arr[mid].first == target) return mid;
            else if (arr[mid].first < target) low = mid + 1;
            else high = mid - 1;
        }

        return high;
    }

    string get(string key, int timestamp) {
        vector<pair<int, string>>& arr = dict[key];
        int idx = binarySearch(arr, timestamp);
        if (idx == -1) return "";

        string ans = "";
        ans = arr[idx].second;

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

