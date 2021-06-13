//
// Created by Ankit Batra on 6/12/21.
//

/* A car travels from a starting position to a destination which is target miles east of the starting position.
 * Along the way, there are gas stations.  Each station[i] represents a gas station that is station[i][0]
 * miles east of the starting position, and has station[i][1] liters of gas.
 * The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it.
 * It uses 1 liter of gas per 1 mile that it drives.
 * When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into
 * the car.
 * What is the least number of refueling stops the car must make in order to reach its destination?
 * If it cannot reach the destination, return -1.
 * Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there.
 * If the car reaches the destination with 0 fuel left, it is still considered to have arrived. */

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();

        priority_queue<int> pq;

        int canReach = startFuel;
        int stops = 0;

        for (vector<int>& s : stations) {
            int dist = s[0], fuel = s[1];
            while (canReach < dist) {
                if (pq.empty()) return -1;
                canReach += pq.top();
                pq.pop();
                stops++;
            }
            pq.push(fuel);
        }

        while (canReach < target) {
            if (pq.empty()) return -1;
            canReach += pq.top();
            pq.pop();
            stops++;
        }

        return stops;
    }
};

