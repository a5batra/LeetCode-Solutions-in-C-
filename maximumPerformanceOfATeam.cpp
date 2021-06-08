//
// Created by ankitb on 6/7/21.
//

/* You are given two integers n and k and two integer arrays speed and efficiency both of length n.
 * There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed and efficiency of
 * the ith engineer respectively.
 * Choose at most k different engineers out of the n engineers to form a team with the maximum performance.
 * The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among
 * their engineers.
 * Return the maximum performance of this team. Since the answer can be a huge number,
 * return it modulo 109 + 7. */

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; ++i) {
            arr[i] = make_pair(efficiency[i], speed[i]);
        }

        sort(arr.begin(), arr.end(), greater<pair<int, int>>());

        priority_queue<int, vector<int>, greater<int>> pq;

        long totalSpeed = 0;
        long ans = 0;
        int mod = 1000000007;

        for (int i = 0; i < n; ++i) {
            totalSpeed += arr[i].second;
            pq.push(arr[i].second);
            if (pq.size() > k) {
                totalSpeed -= pq.top();
                pq.pop();
            }
            if (arr[i].first * totalSpeed > ans) {
                ans = arr[i].first * totalSpeed;
            }
        }

        return ans % mod;
    }
};