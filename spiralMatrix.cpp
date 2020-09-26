//
// Created by Ankit Batra on 9/25/20.
//

// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    static vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int n = matrix.size();
        if (n == 0) return result;
        int m = matrix[0].size();

        int rowStart = 0;
        int rowEnd = n - 1;
        int colStart = 0;
        int colEnd = m - 1;

        while (rowStart <= rowEnd && colStart <= colEnd) {
            for (int i = colStart; i <= colEnd; ++i)
                result.push_back(matrix[rowStart][i]);
            rowStart++;

            for (int i = rowStart; i <= rowEnd; ++i)
                result.push_back(matrix[i][colEnd]);
            colEnd--;

            if (rowStart <= rowEnd) {
                for (int i = colEnd; i >= colStart; --i)
                    result.push_back(matrix[rowEnd][i]);
                rowEnd--;
            }

            if (colStart <= colEnd) {
                for (int i = rowEnd; i >= rowStart; --i)
                    result.push_back(matrix[i][colStart]);
                colStart++;
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3,4},
                                  {5,6,7,8},
                                  {9,10,11,12}};
    vector<int> result;
    std::cout << "In spiral order: " << std::endl;

    result = Solution::spiralOrder(matrix);

    for (int i = 0; i < result.size(); ++i)
        std::cout << result[i] << " ";

    return 0;
}

