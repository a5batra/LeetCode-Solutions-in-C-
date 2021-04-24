//
// Created by Ankit Batra on 4/24/21.
//


/* Given a list of the scores of different students, items, where items[i] = [IDi, scorei] represents one score
 * from a student with IDi, calculate each student's top five average.
 * Return the answer as an array of pairs result, where result[j] = [IDj, topFiveAveragej] represents the student
 * with IDj and their top five average. Sort result by IDj in increasing order.
 * A student's top five average is calculated by taking the sum of their top five scores and dividing it by 5 using
 * integer division. */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> ans;
        if (items.size() == 0) return ans;
        unordered_map<int, vector<int>> scores;
        for (vector<int>& i : items) {
            int id = i[0], score = i[1];
            if (scores.count(id) > 0) scores[id].push_back(score);
            else scores[id] = {score};
        }

        for (auto it : scores) {
            int id = it.first;
            vector<int> s = it.second;
            sort(s.begin(), s.end());
            int sum = 0;
            int count = 0;
            for (int i = s.size() - 1; i >= 0; --i) {
                if (count == 5) break;
                sum += s[i];
                count++;
            }
            ans.push_back({id, sum / 5});
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    return 0;
}