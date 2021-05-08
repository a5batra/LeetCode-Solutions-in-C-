//
// Created by Ankit Batra on 5/7/21.
//

/* You have n processes forming a rooted tree structure. You are given two integer arrays pid and ppid,
 * where pid[i] is the ID of the ith process and ppid[i] is the ID of the ith process's parent process.
 * Each process has only one parent process but may have multiple children processes.
 * Only one process has ppid[i] = 0, which means this process has no parent process (the root of the tree).
 * When a process is killed, all of its children processes will also be killed.
 * Given an integer kill representing the ID of a process you want to kill,
 * return a list of the IDs of the processes that will be killed. You may return the answer in any order. */

#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
    vector<int> ans;
    unordered_map<int, unordered_set<int>> child;
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = ppid.size();
        for (int i = 0; i < n; ++i)
            child[ppid[i]].insert(pid[i]);
        dfs(pid, ppid, kill);

        return ans;
    }

    void dfs(vector<int>& pid, vector<int>& ppid, int kill) {
        ans.push_back(kill);
        if (child.count(kill)) {
            for (auto c : child[kill])
                dfs(pid, ppid, c);
        }
    }
};

