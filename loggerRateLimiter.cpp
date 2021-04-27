//
// Created by Ankit Batra on 4/26/21.
//

/* Design a logger system that receives a stream of messages along with their timestamps.
 * Each unique message should only be printed at most every 10 seconds
 * (i.e. a message printed at timestamp t will prevent other identical messages from being printed until timestamp
 * t + 10).
 * All messages will come in chronological order. Several messages may arrive at the same timestamp.
 * Implement the Logger class:
 * Logger() Initializes the logger object.
 * bool shouldPrintMessage(int timestamp, string message)
 * Returns true if the message should be printed in the given timestamp, otherwise returns false. */

class Logger {
    unordered_map<string, int> dict;
public:
    /** Initialize your data structure here. */
    Logger() {

    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (dict.count(message) > 0) {
            if (dict[message] + 10 > timestamp) {
                return false;
            }
            else {
                dict[message] = timestamp;
                return true;
            }
        }
        dict[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

