/*3100. Water Bottles II
You are given two integers numBottles and numExchange.

numBottles represents the number of full water bottles that you initially have.
In one operation, you can perform one of the following operations:

Drink any number of full water bottles turning them into empty bottles.
Exchange numExchange empty bottles with one full water bottle. Then, increase
numExchange by one. Note that you cannot exchange multiple batches of empty
bottles for the same value of numExchange. For example, if numBottles == 3 and
numExchange == 1, you cannot exchange 3 empty water bottles for 3 full bottles.

Return the maximum number of water bottles you can drink.



Example 1:


Input: numBottles = 13, numExchange = 6
Output: 15
Explanation: The table above shows the number of full water bottles, empty water
bottles, the value of numExchange, and the number of bottles drunk. Example 2:


Input: numBottles = 10, numExchange = 3
Output: 13
Explanation: The table above shows the number of full water bottles, empty water
bottles, the value of numExchange, and the number of bottles drunk.


Constraints:

1 <= numBottles <= 100
1 <= numExchange <= 100

Hint 1
Simulate the process step by step. At each step, drink numExchange bottles of
water then exchange them for a full bottle. Keep repeating this step until you
cannot exchange bottles anymore.
*/

/*You can drink all the full bottles → they turn into empty bottles.

You can exchange numExchange empties for one new full bottle.

But after each exchange, numExchange increases by 1, making it harder to
exchange again.
*/

class Solution {
public:
  int maxBottlesDrunk(int numBottles, int numExchange) {
    int total = 0;
    int empty = 0;

    while (numBottles > 0) {
      // Drink all current bottles
      total += numBottles;
      empty += numBottles;
      numBottles = 0;

      // Try to exchange if possible
      if (empty >= numExchange) {
        empty -= numExchange; // spend empty bottles
        numBottles = 1;       // gain a new full bottle
        numExchange++;        // harder next time
      }
    }
    return total;
  }
};
// sub:
// https://leetcode.com/problems/water-bottles-ii/submissions/1789010150/?envType=daily-question&envId=2025-10-02
// sol:
// https://leetcode.com/problems/water-bottles-ii/solutions/7242122/3100-water-bottles-ii-by-nalindalal2004-1361/
