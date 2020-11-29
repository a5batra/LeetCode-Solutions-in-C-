//
// Created by Ankit Batra on 11/27/20.
//

/* Write an efficient algorithm that searches for a target value in an m x n integer matrix.
 * The matrix has the following properties:
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom. */
#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    static bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;

        int row = 0, col = m - 1;

        while (row < n && col >= 0) {
            if (matrix[row][col] == target) return true;

            else if (target < matrix[row][col]) col--;
            else row++;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,4,7,11,15},
                                  {2,5,8,12,19},
                                  {3,6,9,16,22},
                                  {10,13,14,17,24},
                                  {18,21,23,26,30}};


    std::cout << "Result: " << Solution::searchMatrix(matrix, 5);

    return 0;
}

