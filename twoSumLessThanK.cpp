//
// Created by Ankit Batra on 8/30/20.
//

/*  Given an array A of integers and integer K, return the maximum S such that there exists i < j with A[i] + A[j] = S
 * and S < K. If no i, j exist satisfying this equation, return -1. */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static int twoSumLessThanK(vector<int>& A, int K) {
        int n = A.size();
        int sum = -1;
        if (n == 0) return sum;

        sort(A.begin(), A.end());

        int low = 0;
        int high = n - 1;

        while (low < high) {
            if (A[low] + A[high] < K) {
                if (A[low] + A[high] > sum)
                    sum = A[low] + A[high];
                low++;
            }
            else high--;
        }
        return sum;
    }
};

int main() {
    int number;
    string line;
    vector<int> A;
    int K;

    std::cout << "Enter the elements of array separated by space: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number)
        A.push_back(number);

    std::cout << "Enter the value of K: " << std::endl;
    std::cin >> K;

    std::cout << "Maximum S that satisfies the given constraint: " << Solution::twoSumLessThanK(A, K);

    return 0;
}


