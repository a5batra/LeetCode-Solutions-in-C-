//
// Created by Ankit Batra on 4/30/21.
//

/* Given an integer array sorted in ascending order, write a function to search target in nums.
 * If target exists, then return its index, otherwise return -1. However, the array size is unknown to you.
 * You may only access the array using an ArrayReader interface, where ArrayReader.get(k)
 * returns the element of the array at index k (0-indexed).
 * You may assume all integers in the array are less than 10000, and if you access the array out of bounds,
 * ArrayReader.get will return 2147483647. */

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int low = 0, high = 1, mid = 0;

        while (reader.get(high) < target) {
            low = high;
            high <<= 1;
        }

        while (low <= high) {
            mid = low + (high - low) / 2;
            if (reader.get(mid) == target) return mid;
            else if (reader.get(mid) > target) high = mid - 1;
            else low = mid + 1;
        }

        return -1;
    }
};

