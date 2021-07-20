//
// Created by Ankit Batra on 7/20/21.
//

/* Given an integer array nums, design an algorithm to randomly shuffle the array.
 * All permutations of the array should be equally likely as a result of the shuffling.
 * Implement the Solution class:
 * Solution(int[] nums) Initializes the object with the integer array nums.
 * int[] reset() Resets the array to its original configuration and returns it.
 * int[] shuffle() Returns a random shuffling of the array. */

class Solution {
    vector<int> arr;
public:
    Solution(vector<int>& nums) {
        arr = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr;
    }

    /** Returns a random shuffling of the array. */
    void swapper(vector<int>& arr, int idx1, int idx2) {
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
    }
    vector<int> shuffle() {
        vector<int> randomArray = arr;
        for (int i = arr.size() - 1; i > 0; --i) {
            int randomIdx = rand() % (i + 1);
            swapper(randomArray, randomIdx, i);
        }
        return randomArray;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

