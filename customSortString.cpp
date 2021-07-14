//
// Created by Ankit Batra on 7/14/21.
//

/* order and str are strings composed of lowercase letters. In order, no letter occurs more than once.
 * order was sorted in some custom order previously.
 * We want to permute the characters of str so that they match the order that order was sorted.
 * More specifically, if x occurs before y in order, then x should occur before y in the returned string.
 * Return any permutation of str (as a string) that satisfies this property. */

class Solution {
public:
    string customSortString(string order, string str) {
        unordered_set<char> orderSt(order.begin(), order.end());
        unordered_map<char, int> strMap;

        for (char& c : str) strMap[c]++;

        string res = "";

        for (char& c : order)
            if (strMap.count(c)) res += string(strMap[c], c);

        for (char& c : str)
            if (orderSt.count(c) == 0) res += c;

        return res;


    }
};

