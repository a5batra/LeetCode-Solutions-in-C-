//
// Created by Ankit Batra on 2/2/21.
//

/* You have an inventory of different colored balls, and there is a customer that wants orders balls of any color.
 * The customer weirdly values the colored balls. Each colored ball's value is the number of balls of that
 * color you currently have in your inventory.
 * For example, if you own 6 yellow balls, the customer would pay 6 for the first yellow ball.
 * After the transaction, there are only 5 yellow balls left, so the next yellow ball is then valued at 5
 * (i.e., the value of the balls decreases as you sell more to the customer).
 * You are given an integer array, inventory, where inventory[i] represents the number of
 * balls of the ith color that you initially own. You are also given an integer orders,
 * which represents the total number of balls that the customer wants. You can sell the balls in any order.
 * Return the maximum total value that you can attain after selling orders colored balls.
 * As the answer may be too large, return it modulo 109 + 7. */

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    static int maxProfit(vector<int>& inventory, int orders) {
        int n = inventory.size();
        std::sort(inventory.begin(), inventory.end());
        int i = n - 1;
        long long count = 1;
        long long ans = 0;

        while (orders > 0) {
            if (i > 0 && inventory[i] - inventory[i - 1] > 0 && orders >= count * (inventory[i] - inventory[i - 1])) {
                ans += count * getSumFromNToX(inventory[i], inventory[i - 1]);
                orders -= count * (inventory[i] - inventory[i - 1]);
            }
            else if (i == 0 || inventory[i] - inventory[i - 1] > 0) {
                long long a = orders / count;
                ans += count * getSumFromNToX(inventory[i], inventory[i] - a);
                long long b = orders % count;
                ans += b * (inventory[i] - a);
                orders = 0;
            }
            ans = ans % 1000000007;
            i--;
            count++;
        }
        return ans;
    }

    static long long getSumFromNToX(long n, long x) {
        return (n * (n + 1) / 2) - (x * (x + 1) / 2);
    }
};
