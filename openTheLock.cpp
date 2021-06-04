//
// Created by Ankit Batra on 6/4/21.
//

/* You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6',
 * '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'.
 * Each move consists of turning one wheel one slot.
 * The lock initially starts at '0000', a string representing the state of the 4 wheels.
 * You are given a list of deadends dead ends, meaning if the lock displays any of these codes,
 * the wheels of the lock will stop turning and you will be unable to open it.
 * Given a target representing the value of the wheels that will unlock the lock,
 * return the minimum total number of turns required to open the lock, or -1 if it is impossible. */

/*
push start into q
while q not empty
    pop current string from front
    check if it's equal to target -> if yes, return num of turns made so far
    if equal to deadend -> continue
    for char in current_string:
        add +1 and -1 to get the next neighbor
        push into queue
return -1 if we reach this point
*/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin(), deadends.end());
        int turns = 0;

        string start = "0000";

        queue<string> q;
        q.push(start);
        unordered_set<string> seen;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string curr = q.front();
                q.pop();
                if (curr == target) return turns;
                if (st.count(curr)) continue;
                for (char& c : curr) {
                    int temp = c - '0';
                    int nextInt = (temp + 1) % 10;
                    int prevInt = (temp - 1) % 10;
                    if (prevInt < 0) prevInt = 9;
                    c = nextInt + '0';
                    if (!seen.count(curr)) {
                        seen.insert(curr);
                        q.push(curr);
                    }
                    c = prevInt + '0';
                    if (!seen.count(curr)) {
                        seen.insert(curr);
                        q.push(curr);
                    }
                    c = temp + '0';
                }
            }
            turns++;
        }
        return -1;
    }
};

