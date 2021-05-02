//
// Created by Ankit Batra on 5/2/21.
//

/* Given a grid where each entry is only 0 or 1, find the number of corner rectangles.
 * A corner rectangle is 4 distinct 1s on the grid that form an axis-aligned rectangle.
 * Note that only the corners need to have the value 1. Also, all four 1s used must be distinct. */

#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size();
        unordered_map<int, int> dict;

        int count = 0;
        for (auto row : grid) {
            for (int i = 0; i < row.size(); ++i) {
                for (int j = i + 1; j < row.size(); ++j) {
                    if (row[i] == 0 || row[j] == 0) continue;
                    if (!dict.count(row.size() * i + j)) dict[row.size() * i + j] = 0;
                    else {
                        count += dict[row.size() * i + j] + 1;
                        dict[row.size() * i + j]++;
                    }
                }
            }
        }
        return count;
    }
};

