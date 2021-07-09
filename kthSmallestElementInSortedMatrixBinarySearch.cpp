//
// Created by Ankit Batra on 7/9/21.
//

/* Given an n x n matrix where each of the rows and columns are sorted in ascending order,
 * return the kth smallest element in the matrix.
 * Note that it is the kth smallest element in the sorted order, not the kth distinct element. */

class Solution {
    pair<int, int> p; // largest number smaller than mid, smallest number larger than mid
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        int mid = 0;

        while (low < high) {
            mid = low + (high - low) / 2;
            p = {matrix[0][0], matrix[n - 1][n - 1]};
            int count = lessThanEqualToMid(matrix, mid);
            if (count == k) return p.first;
            else if (count < k) low = p.second;
            else high = p.first;
        }

        return low;
    }

    int lessThanEqualToMid(vector<vector<int>>& matrix, int target) {
        int count = 0;
        int n = matrix.size();
        int i = n - 1, j = 0;

        while (i >= 0 && j < n) {
            if (matrix[i][j] <= target) {
                p.first = max(p.first, matrix[i][j]);
                count += i + 1;
                j++;
            }
            else {
                p.second = min(p.second, matrix[i][j]);
                i--;
            }
        }

        return count;
    }
};

