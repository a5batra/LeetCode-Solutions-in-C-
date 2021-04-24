//
// Created by Ankit Batra on 4/24/21.
//

/* Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order, return a sorted array of
 * only the integers that appeared in all three arrays. */

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;

        int i = 0, j = 0, k = 0;

        while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                ans.push_back(arr1[i]);
                i++, j++, k++;
            }
            else {
                if (arr1[i] < arr2[j]) i++;
                else if (arr2[j] < arr3[k]) j++;
                else k++;
            }
        }

        return ans;
    }
};

