//
// Created by Ankit Batra on 11/28/20.
//

/* Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row. */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    static bool findTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = n * m - 1;
        int mid = 0;
        int row = 0;
        int col = 0;

        while (low <= high) {
            mid = low + (high - low) / 2;
            row = mid / m, col = mid % m;
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
    static bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;


        bool result = findTarget(matrix, target);

        return result;

    }
};

int main() {
    vector<vector<int>> matrix = {{1,3,5,7},
                                  {10,11,16,20},
                                  {23,30,34,50}};


    std::cout << "Result: " << Solution::searchMatrix(matrix, 30);

    return 0;
}

