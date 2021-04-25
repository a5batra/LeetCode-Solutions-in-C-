//
// Created by Ankit Batra on 4/24/21.
//

/* You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements
 * may also be integers or other lists.
 * The depth of an integer is the number of lists that it is inside of.
 * For example, the nested list [1,[2,2],[[3],2],1] has each integer's value set to its depth.
 * Return the sum of each integer in nestedList multiplied by its depth. */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
    int ans;
public:
    Solution() {
        ans = 0;
    }
    void dfs(NestedInteger& nestInt, int depth) {
        if (nestInt.isInteger()) {
            ans += depth * nestInt.getInteger();
        }
        else {
            vector<NestedInteger> list = nestInt.getList();
            for (NestedInteger n : list) {
                dfs(n, depth + 1);
            }
        }
    }
    int depthSum(vector<NestedInteger>& nestedList) {
        for (NestedInteger& n : nestedList) {
            dfs(n, 1);
        }
        return ans;
    }
};

