//
// Created by Ankit Batra on 1/17/21.
//

/* There are 8 prison cells in a row, and each cell is either occupied or vacant.
 * Each day, whether the cell is occupied or vacant changes according to the following rules:
 * If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
 * Otherwise, it becomes vacant.
 * (Note that because the prison is a row, the first and the last cells in the row can't
 * have two adjacent neighbors.)
 * We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.
 *
 * Given the initial state of the prison, return the state of the prison after N days
 * (and N such changes described above.) */

#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    static vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if (N == 0) return cells;
        vector<vector<int>> states;
        vector<int> temp(cells.size());

        while (N--) {
            for (int i = 1; i < cells.size() - 1; ++i)
                temp[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;

            if (states.size() > 0 && states.front() == temp)
                return states[N % states.size()];

            states.push_back(temp);
            cells = temp;
        }

        return temp;
    }
};

int main() {
    int number;
    string line;
    vector<int> cells;

    std::cout << "Enter the array: " << std::endl;
    std::getline(std::cin, line);

    std::istringstream stream(line);
    while (stream >> number) cells.push_back(number);

    int N;
    std::cout << "Enter the value of N: " << std::endl;
    std::cin >> N;

    vector<int> result = Solution::prisonAfterNDays(cells, N);

    for (int val : result)
        std::cout << val << " ";

    return 0;
}

