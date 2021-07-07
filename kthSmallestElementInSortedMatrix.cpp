//
// Created by Ankit Batra on 7/7/21.
//

/* Given an n x n matrix where each of the rows and columns are sorted in ascending order,
 * return the kth smallest element in the matrix.
 * Note that it is the kth smallest element in the sorted order, not the kth distinct element. */

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        priority_queue<int> pq;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pq.push(matrix[i][j]);
                if (pq.size() > k) pq.pop();
            }
        }

        return pq.top();
    }
};

