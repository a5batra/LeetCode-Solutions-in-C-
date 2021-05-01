//
// Created by Ankit Batra on 5/1/21.
//

/* You have some apples, where arr[i] is the weight of the i-th apple.
 * You also have a basket that can carry up to 5000 units of weight.
 * Return the maximum number of apples you can put in the basket. */

#include <vector>

using std::vector;

class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 0, currWt = 0;
        int idx = 0;

        while (idx < arr.size()) {
            if (currWt + arr[idx] > 5000) break;
            currWt += arr[idx];
            ans++;
            idx++;
        }

        return ans;
    }
};

