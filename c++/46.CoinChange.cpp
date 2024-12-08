/*
322. Coin Change

You are given an integer array coins representing coins of different
denominations and an integer amount representing a total amount of money. Return
the fewest number of coins that you need to make up that amount. If that amount
of money cannot be made up by any combination of the coins, return -1. You may
assume that you have an infinite number of each kind of coin.

Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0


Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/

/*
Take coins=[1,2,5] and amount = 11 as an example,

If I use one 1, I need to know the fewest number of coins I need to make up 10,
i.e., dp[10]. Overall I need 1+dp[10] coins. If I use one 2, I need 1+dp[9]
coins. If I use one 5, I need 1+dp[6] coins. Therefore, I need to calculate dp
from 1 to amount.
*/

// Test Cases
/*
[1,2,5]
11
[2]
3
[1]
0
[1,2,5]
100
[186,419,83,408]
6249
[3,7,405,436]
8839
[176,6,366,357,484,226,1,104,160,331]
5557
[19,28,176,112,30,260,491,128,70,137,253]
8539
*/

// Breakdown
/*
Inputs:
coins: an array of integers where each element represents a coin denomination.
(e.g., [1, 2, 5] means you have coins of 1, 2, and 5 units). amount: an integer
representing the target amount of money. Outputs: Return the minimum number of
coins required to make up the given amount. If it's not possible to make the
amount using the given coins, return -1.

    */

// finding the optimal combination of coins to make up the total amount,
// minimizing the total number of coins

// Can't apply greedy
// apply dp

// idea->
/*
Start with the smallest amount (0) and build up to the target amount.
For each coin, try to update the DP table by checking if you can use that coin
to minimize the number of coins needed for the current amount.
    */

// Aprroach
/*
Initialize a DP array of size amount + 1 with values set to infinity (Infinity)
because initially, we assume it's impossible to make any amount. Set dp[0] = 0
since 0 coins are needed to make the amount 0.

For each coin in the coins array, update the DP array for all amounts from coin
to amount. If you can form the amount i using coin, then update dp[i] =
min(dp[i], dp[i - coin] + 1).

After processing all coins, if dp[amount] is still Infinity, return -1 (since
the amount can't be formed). Otherwise, return dp[amount].
*/

#include <vector>
using namespace std;

class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0; // Base case: 0 coins needed to make amount 0

    // Loop through each coin
    for (int coin : coins) {
      // Loop through all amounts from the coin value to the target amount
      for (int i = coin; i <= amount; i++) {
        if (dp[i - coin] !=
            INT_MAX) { // Check if the subproblem has a valid solution
          dp[i] = std::min(dp[i], dp[i - coin] + 1);
        }
      }
    }

    // If dp[amount] is still INT_MAX, return -1 (meaning it's not possible to
    // make the amount)
    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};

// Time Complexity: O(n * amount), where n is the number of coins and amount is
// the target amount. Space Complexity: O(amount) for the dp array

/*JS
function coinChange(coins, amount) {
    const dp = new Array(amount + 1).fill(Infinity);
    dp[0] = 0;  // Base case: 0 coins needed to make amount 0

    // Loop over each coin
    for (let coin of coins) {
        // For each amount from the coin's value up to the total amount
        for (let i = coin; i <= amount; i++) {
            // Update dp[i] by considering the current coin
            dp[i] = Math.min(dp[i], dp[i - coin] + 1);
        }
    }

    return dp[amount] === Infinity ? -1 : dp[amount];
}

*/

int main() {
  Solution solution;
  std::vector<int> coins1 = {1, 2, 5};
  int amount1 = 11;

  int result1 = solution.coinChange(coins1, amount1);
  cout << result << endl; // Output: 3
  return 0;
}
