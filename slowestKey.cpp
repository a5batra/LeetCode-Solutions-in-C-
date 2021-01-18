//
// Created by Ankit Batra on 1/18/21.
//

/* A newly designed keypad was tested, where a tester pressed a sequence of n keys, one at a time.
 * You are given a string keysPressed of length n, where keysPressed[i] was the ith key pressed in the testing sequence,
 * and a sorted list releaseTimes, where releaseTimes[i] was the time the ith key was released.
 * Both arrays are 0-indexed. The 0th key was pressed at the time 0, and every subsequent key was pressed at the exact
 * time the previous key was released.
 * The tester wants to know the key of the keypress that had the longest duration.
 * The ith keypress had a duration of releaseTimes[i] - releaseTimes[i - 1],
 * and the 0th keypress had a duration of releaseTimes[0].
 * Note that the same key could have been pressed multiple times during the test,
 * and these multiple presses of the same key may not have had the same duration.
 *
 * Return the key of the keypress that had the longest duration.
 * If there are multiple such keypresses, return the lexicographically largest key of the keypresses. */

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
    static char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        if (n == 0) return ' ';

        unordered_map<char, int> duration;
        duration[keysPressed[0]] = releaseTimes[0];

        for (int i = 1; i < n; ++i) {
            if (duration.find(keysPressed[i]) != duration.end()) {
                if (duration[keysPressed[i]] < releaseTimes[i] - releaseTimes[i - 1]) {
                    duration[keysPressed[i]] = releaseTimes[i] - releaseTimes[i - 1];
                }
            }
            else {
                duration[keysPressed[i]] = releaseTimes[i] - releaseTimes[i - 1];
            }
        }

        int maxDur = 0;
        char key = ' ';
        for (auto it = duration.begin(); it != duration.end(); ++it) {
            if (it->second > maxDur) {
                key = it->first;
                maxDur = it->second;
            }
            else if (it->second == maxDur) {
                if (it->first > key) key = it->first;
            }
        }
        return key;
    }
};

int main() {
    string keysPressed;
    vector<int> releaseTimes;
    int number;
    string line;

    std::cout << "Enter the array of release times: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number) releaseTimes.push_back(number);

    std::cout << "Enter the string of keys pressed: " << std::endl;
    std::cin >> keysPressed;

    char key = Solution::slowestKey(releaseTimes, keysPressed);

    std::cout << "Key having the longest duration: " << key;

    return 0;
}

