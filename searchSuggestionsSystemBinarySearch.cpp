//
// Created by Ankit Batra on 5/12/21.
//

/* Given an array of strings products and a string searchWord.
 * We want to design a system that suggests at most three product names from products after each character of
 * searchWord is typed. Suggested products should have common prefix with the searchWord.
 * If there are more than three products with a common prefix return the three lexicographically minimums products.
 * Return list of lists of the suggested products after each character of searchWord is typed. */

#include <string>
#include <vector>

using std::min;
using std::string;
using std::vector;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        int n = products.size();
        int low = 0, high = n - 1;
        int len = searchWord.length();

        for (int i = 0; i < len; ++i) {
            while (low <= high && (products[low].length() < i || products[low][i] != searchWord[i])) low++;
            while (low <= high && (products[high].length() < i || products[high][i] != searchWord[i])) high--;
            int nums = min(low + 3, high + 1);
            vector<string> res;
            for (int i = low; i < nums; ++i) {
                res.push_back(products[i]);
            }
            ans.push_back(res);
        }
        return ans;
    }
};

