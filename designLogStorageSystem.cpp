//
// Created by Ankit Batra on 5/24/21.
//

/* You are given several logs, where each log contains a unique ID and timestamp.
 * Timestamp is a string that has the following format: Year:Month:Day:Hour:Minute:Second,
 * for example, 2017:01:01:23:59:59. All domains are zero-padded decimal numbers.
 * Implement the LogSystem class:
 * LogSystem() Initializes the LogSystem object.
 * void put(int id, string timestamp) Stores the given log (id, timestamp) in your storage system.
 * int[] retrieve(string start, string end, string granularity)
 * Returns the IDs of the logs whose timestamps are within the range from start to end inclusive.
 * start and end all have the same format as timestamp, and granularity means how precise the range should be
 * (i.e. to the exact Day, Minute, etc.). For example, start = "2017:01:01:23:59:59", end = "2017:01:02:23:59:59",
 * and granularity = "Day" means that we need to find the logs within the inclusive range from Jan. 1st 2017 to
 * Jan. 2nd 2017, and the Hour, Minute, and Second for each log entry can be ignored. */

#include <map>
#include <string>
#include <vector>

using std::multimap;
using std::string;
using std::multimap;

class LogSystem {
    multimap<string, int> m;
public:
    LogSystem() {

    }

    void put(int id, string timestamp) {
        m.emplace(timestamp, id);
    }

    vector<int> retrieve(string start, string end, string granularity) {
        vector<int> ids;
        string s = "";
        string e = "";
        if (granularity == "Year") {
            s = start.substr(0, 4) + ":01:01:00:00:00";
            e = end.substr(0, 4) + ":12:31:23:59:59";
        }
        else if (granularity == "Month") {
            s = start.substr(0, 7) + ":01:00:00:00";
            e = end.substr(0, 7) + ":31:23:59:59";
        }
        else if (granularity == "Day") {
            s = start.substr(0, 10) + ":00:00:00";
            e = end.substr(0, 10) + ":23:59:59";
        }
        else if (granularity == "Hour") {
            s = start.substr(0, 13) + ":00:00";
            e = end.substr(0, 13) + ":59:59";
        }
        else if (granularity == "Minute") {
            s = start.substr(0, 16) + ":00";
            e = end.substr(0, 16) + ":59";
        }
        else {
            s = start;
            e = end;
        }
        auto startIt = m.lower_bound(s), endIt = m.upper_bound(e);
        for (auto it = startIt; it != endIt; ++it) {
            ids.push_back(it->second);
        }

        return ids;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */

