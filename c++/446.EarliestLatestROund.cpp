/*1900. The Earliest and Latest Rounds Where Players Compete
There is a tournament where n players are participating. The players are
standing in a single row and are numbered from 1 to n based on their initial
standing position (player 1 is the first player in the row, player 2 is the
second player in the row, etc.).

The tournament consists of multiple rounds (starting from round number 1). In
each round, the ith player from the front of the row competes against the ith
player from the end of the row, and the winner advances to the next round. When
the number of players is odd for the current round, the player in the middle
automatically advances to the next round.

For example, if the row consists of players 1, 2, 4, 6, 7
Player 1 competes against player 7.
Player 2 competes against player 6.
Player 4 automatically advances to the next round.
After each round is over, the winners are lined back up in the row based on the
original ordering assigned to them initially (ascending order).

The players numbered firstPlayer and secondPlayer are the best in the
tournament. They can win against any other player before they compete against
each other. If any two other players compete against each other, either of them
might win, and thus you may choose the outcome of this round.

Given the integers n, firstPlayer, and secondPlayer, return an integer array
containing two values, the earliest possible round number and the latest
possible round number in which these two players will compete against each
other, respectively.



Example 1:

Input: n = 11, firstPlayer = 2, secondPlayer = 4
Output: [3,4]
Explanation:
One possible scenario which leads to the earliest round number:
First round: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
Second round: 2, 3, 4, 5, 6, 11
Third round: 2, 3, 4
One possible scenario which leads to the latest round number:
First round: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
Second round: 1, 2, 3, 4, 5, 6
Third round: 1, 2, 4
Fourth round: 2, 4
Example 2:

Input: n = 5, firstPlayer = 1, secondPlayer = 5
Output: [1,1]
Explanation: The players numbered 1 and 5 compete in the first round.
There is no way to make them compete in any other round.


Constraints:

2 <= n <= 28
1 <= firstPlayer < secondPlayer <= n

Hint 1
Brute force using bitmasks and simulate the rounds.
Hint 2
Calculate each state one time and save its solution.
*/

/*We keep track of:
- n players
- Positions a (min of firstPlayer and secondPlayer) and b (max of firstPlayer
and secondPlayer)
- The round number r starting from 1

store states in a DP map to avoid recomputation:
 - Key: (n, a, b) — number of players and positions of the best two players
 - Value: [earliest_round, latest_round] they can meet

1. If a + b == n + 1 (i.e., they're matched from opposite ends), they play this
round.
2. Otherwise, simulate all possible outcomes for the rest of the matches,
keeping a and b alive until they meet.
*/

class Solution {
public:
  map<tuple<int, int, int>, pair<int, int>> dp;

  pair<int, int> dfs(int n, int a, int b) {
    if (a > b)
      swap(a, b);
    if (a + b == n + 1)
      return {1, 1}; // They face each other now

    auto key = make_tuple(n, a, b);
    if (dp.count(key))
      return dp[key];

    int minRound = INT_MAX, maxRound = 0;

    // Enumerate all subsets of winners from the rest of the players
    // Simulate all matchups and check where a and b land in next round
    for (int mask = 0; mask < (1 << (n / 2)); ++mask) {
      vector<int> next;
      int ai = 0, bi = 0;
      bool aliveA = false, aliveB = false;
      for (int i = 1; i <= n / 2; ++i) {
        int left = i;
        int right = n - i + 1;

        int winner = (mask & (1 << (i - 1))) ? left : right;

        if (winner == a)
          aliveA = true;
        if (winner == b)
          aliveB = true;
        next.push_back(winner);
      }
      if (n % 2 == 1) {
        int mid = (n + 1) / 2;
        next.push_back(mid);
        if (mid == a)
          aliveA = true;
        if (mid == b)
          aliveB = true;
      }

      if (!aliveA || !aliveB)
        continue;

      // Reassign new positions
      sort(next.begin(), next.end());
      int newA = -1, newB = -1;
      for (int i = 0; i < next.size(); ++i) {
        if (next[i] == a)
          newA = i + 1;
        if (next[i] == b)
          newB = i + 1;
      }

      auto [earliest, latest] = dfs(next.size(), newA, newB);
      minRound = min(minRound, 1 + earliest);
      maxRound = max(maxRound, 1 + latest);
    }

    return dp[key] = {minRound, maxRound};
  }

  vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
    auto [earliest, latest] = dfs(n, firstPlayer, secondPlayer);
    return {earliest, latest};
  }
};

// sub:
// https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/submissions/1695451476/?envType=daily-question&envId=2025-07-12
//  sol:
//  https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/solutions/6950405/1900-the-earliest-and-latest-rounds-wher-knph/
