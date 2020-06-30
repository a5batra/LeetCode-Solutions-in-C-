//
// Created by Ankit Batra on 6/29/20.
//

/* The set [1,2,3,...,n] contains a total of n! unique permutations.
 * By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
 * 1. "123"
 * 2. "132"
 * 3. "213"
 * 4. "231"
 * 5. "312"
 * 6. "321"
 * Given n and k, return the kth permutation sequence.
 *
 * Note:
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive. */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static string getPermutation(int n, int k) {
        vector<int> nums(n);
        vector<int> factorialBase(n);
        string permutation = "";

        factorialBase[0] = 1;
        nums[0] = 1;

        for (int i = 1; i < n; ++i) {
            factorialBase[i] = factorialBase[i - 1] * i;
            nums[i] = i + 1;
        }

        --k;

        for (int i = n - 1; i > -1; --i) {
            int idx = k / factorialBase[i];
            k -= idx * factorialBase[i];
            permutation += std::to_string(nums[idx]);
            nums.erase(nums.begin() + idx);
        }
        return permutation;
    }
};

int main() {
    int n;
    int k;

    std::cout << "Enter the value of n: " << std::endl;
    std::cin >> n;

    std::cout << "Enter the value of k: " << std::endl;
    std::cin >> k;

    std::cout << "The resulting permutation is: " << Solution::getPermutation(n, k) << std::endl;

    return 0;
}
