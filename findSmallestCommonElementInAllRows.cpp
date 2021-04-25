//
// Created by Ankit Batra on 4/25/21.
//

/* Given an m x n matrix mat where every row is sorted in strictly increasing order, return the smallest common
 * element in all rows.
 * If there is no common element, return -1. */

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int ans = -1;
        bool flag = true;

        for (int num : mat[0]) {
            for (int i = 1; i < m; ++i) {
                vector<int> row;
                for (int j = 0; j < n; ++j) {
                    row.push_back(mat[i][j]);
                }
                if (!binary_search(row.begin(), row.end(), num)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = num;
                break;
            }
            else flag = true;
        }
        return ans;
    }
};


