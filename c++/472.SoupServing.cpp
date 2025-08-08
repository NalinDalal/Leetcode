/*808. Soup Servings
You have two soups, A and B, each starting with n mL. On every turn, one of the
following four serving operations is chosen at random, each with probability
0.25 independent of all previous turns:

pour 100 mL from type A and 0 mL from type B
pour 75 mL from type A and 25 mL from type B
pour 50 mL from type A and 50 mL from type B
pour 25 mL from type A and 75 mL from type B
Note:

There is no operation that pours 0 mL from A and 100 mL from B.
The amounts from A and B are poured simultaneously during the turn.
If an operation asks you to pour more than you have left of a soup, pour all
that remains of that soup. The process stops immediately after any turn in which
one of the soups is used up.

Return the probability that A is used up before B, plus half the probability
that both soups are used up in the same turn. Answers within 10-5 of the actual
answer will be accepted.



Example 1:
Input: n = 50
Output: 0.62500
Explanation:
If we perform either of the first two serving operations, soup A will become
empty first. If we perform the third operation, A and B will become empty at the
same time. If we perform the fourth operation, B will become empty first. So the
total probability of A becoming empty first plus half the probability that A and
B become empty at the same time, is 0.25 * (1 + 1 + 0.5 + 0) = 0.625.


Example 2:
Input: n = 100
Output: 0.71875
Explanation:
If we perform the first serving operation, soup A will become empty first.
If we perform the second serving operations, A will become empty on performing
operation [1, 2, 3], and both A and B become empty on performing operation 4. If
we perform the third operation, A will become empty on performing operation [1,
2], and both A and B become empty on performing operation 3. If we perform the
fourth operation, A will become empty on performing operation 1, and both A and
B become empty on performing operation 2. So the total probability of A becoming
empty first plus half the probability that A and B become empty at the same
time, is 0.71875.


Constraints:
0 <= n <= 109
*/

/*Intuition:
1. Serving Operations:
    - (100,0)
    - (75,25)
    - (50,50)
    - (25,75)

2. If soup runs out-> stop
    - if(A<=0 && B<=0)return 1.0
    - if(A<=0 && B<=0) return 0.5
    - if(B<=0 && A>0) return 0.0

3. since batch of 25 ml so `n=ceil(n/25)`

4. for(n>=4800) probability>0.99999
    */

/* Approach:
1. Use `unordered_map` or a 2D `vector` for memoization.

2. Use recursion to simulate the 4 operations.

3. Return the average probability across the four operations.

4. Base cases handle when A or B runs out.

5. Optimize for large `n` using a threshold
    */

class Solution {
public:
  double soupServings(int n) {
    if (n >= 4800)
      return 1.0;          // Optimization: limit to where probability ~1
    int N = (n + 24) / 25; // Scale down the problem
    vector<vector<double>> memo(N + 1, vector<double>(N + 1, -1.0));
    return dfs(N, N, memo);
  }

  double dfs(int a, int b, vector<vector<double>>& memo) {
    if (a <= 0 && b <= 0)
      return 0.5;
    if (a <= 0)
      return 1.0;
    if (b <= 0)
      return 0.0;
    if (memo[a][b] >= 0)
      return memo[a][b];

    memo[a][b] = 0.25 * (dfs(max(a - 4, 0), b, memo) +
                         dfs(max(a - 3, 0), max(b - 1, 0), memo) +
                         dfs(max(a - 2, 0), max(b - 2, 0), memo) +
                         dfs(max(a - 1, 0), max(b - 3, 0), memo));

    return memo[a][b];
  }
};
// sub:
// https://leetcode.com/problems/soup-servings/submissions/1727551578/?envType=daily-question&envId=2025-08-08
// sol:
// https://leetcode.com/problems/soup-servings/solutions/7056532/808-soup-servings-by-nalindalal2004-ylkh/
