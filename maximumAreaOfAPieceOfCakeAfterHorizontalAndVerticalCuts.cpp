//
// Created by Ankit Batra on 2/2/21.
//

/* Given a rectangular cake with height h and width w, and two arrays of integers horizontalCuts and verticalCuts
 * where horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and
 * similarly, verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
 * Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided
 * in the arrays horizontalCuts and verticalCuts. Since the answer can be a huge number, return this modulo 10^9 + 7. */

#include <iostream>
#include <vector>

using std::max;
using std::vector;

class Solution {
public:
    static int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long maxA = 0;
        long long mod = 1e9 + 7;
        long long m = horizontalCuts.size(), n = verticalCuts.size();
        if (n == 0 && m == 0) {
            return (h * w) % mod;
        }
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        long long maxDiffH = max(horizontalCuts[0], h - horizontalCuts[m - 1]);
        long long maxDiffV = max(verticalCuts[0], w - verticalCuts[n - 1]);

        for (int i = 1; i < m; ++i) {
            if (horizontalCuts[i] - horizontalCuts[i - 1] > maxDiffH)
                maxDiffH = horizontalCuts[i] - horizontalCuts[i - 1];
        }

        for (int i = 1; i < n; ++i) {
            if (verticalCuts[i] - verticalCuts[i - 1] > maxDiffV)
                maxDiffV = verticalCuts[i] - verticalCuts[i - 1];
        }

        maxA = (maxDiffH * maxDiffV) % mod;

        return (int)maxA;

    }
};


int main() {
    return 0;
}

