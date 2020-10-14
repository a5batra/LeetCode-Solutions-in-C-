//
// Created by Ankit Batra on 10/13/20.
//

/* You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
 * You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
 * DO NOT allocate another 2D matrix and do the rotation. */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    static void transpose(vector<vector<int>>& matrix) {
        int temp = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
    static void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;

        int temp = 0;

        transpose(matrix);

        int i = 0;
        int j = n - 1;

        while (i < j) {
            for (int k = 0; k < n; ++k) {
                temp = matrix[k][i];
                matrix[k][i] = matrix[k][j];
                matrix[k][j] = temp;
            }
            i++;
            j--;
        }
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3},
                                  {4,5,6},
                                  {7,8,9}};

    std::cout << "After rotation: " << std::endl;

    Solution::rotate(matrix);

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }

    return 0;
}
