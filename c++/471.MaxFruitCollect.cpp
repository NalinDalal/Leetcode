/*3363. Find the Maximum Number of Fruits Collected
There is a game dungeon comprised of n x n rooms arranged in a grid.

You are given a 2D array fruits of size n x n, where fruits[i][j] represents the
number of fruits in the room (i, j). Three children will play in the game
dungeon, with initial positions at the corner rooms (0, 0), (0, n - 1), and (n -
1, 0).

The children will make exactly n - 1 moves according to the following rules to
reach the room (n - 1, n - 1):

The child starting from (0, 0) must move from their current room (i, j) to one
of the rooms (i + 1, j + 1), (i + 1, j), and (i, j + 1) if the target room
exists. The child starting from (0, n - 1) must move from their current room (i,
j) to one of the rooms (i + 1, j - 1), (i + 1, j), and (i + 1, j + 1) if the
target room exists. The child starting from (n - 1, 0) must move from their
current room (i, j) to one of the rooms (i - 1, j + 1), (i, j + 1), and (i + 1,
j + 1) if the target room exists. When a child enters a room, they will collect
all the fruits there. If two or more children enter the same room, only one
child will collect the fruits, and the room will be emptied after they leave.

Return the maximum number of fruits the children can collect from the dungeon.



Example 1:

Input: fruits = [[1,2,3,4],[5,6,8,7],[9,10,11,12],[13,14,15,16]]

Output: 100

Explanation:



In this example:

The 1st child (green) moves on the path (0,0) -> (1,1) -> (2,2) -> (3, 3).
The 2nd child (red) moves on the path (0,3) -> (1,2) -> (2,3) -> (3, 3).
The 3rd child (blue) moves on the path (3,0) -> (3,1) -> (3,2) -> (3, 3).
In total they collect 1 + 6 + 11 + 16 + 4 + 8 + 12 + 13 + 14 + 15 = 100 fruits.

Example 2:

Input: fruits = [[1,1],[1,1]]

Output: 4

Explanation:

In this example:

The 1st child moves on the path (0,0) -> (1,1).
The 2nd child moves on the path (0,1) -> (1,1).
The 3rd child moves on the path (1,0) -> (1,1).
In total they collect 1 + 1 + 1 + 1 = 4 fruits.



Constraints:

2 <= n == fruits.length == fruits[i].length <= 1000
0 <= fruits[i][j] <= 1000

Hint 1
The child at (0, 0) has only one possible path.
Hint 2
The other two children won’t intersect its path.
Hint 3
Use Dynamic Programming.
*/

/* ### Problem Insight (Clean Version)

There are 3 children starting from different corners of an `n x n` grid of
fruits. Each child moves step by step in specific allowed directions and
collects fruits. No two children are allowed to visit the same cell.

### Key Observations

1. **Child A (starts at (0, 0))**

   * He takes exactly `n - 1` steps to reach the bottom-right corner `(n - 1, n
- 1)`.
   * Because of his movement rules, he must walk only along the **main
diagonal**.
   * So his path is fixed: `(0, 0) → (1, 1) → (2, 2) → ... → (n - 1, n - 1)`.
   * We can directly calculate the sum of fruits on this path.

2. **Child B (starts at (0, n - 1))**

   * To reach `(n - 1, n - 1)` in `n - 1` steps, he must stay **above** the main
diagonal.
   * If he ever steps onto or below the main diagonal, he won't reach the goal
in time.
   * So his entire path must lie **strictly above** the main diagonal.

3. **Child C (starts at (n - 1, 0))**

   * Similar logic applies: he must stay **below** the main diagonal to reach
`(n - 1, n - 1)` in `n - 1` steps.

4. **No Overlapping Cells**

   * Since no two children can collect fruit from the same cell, Child B and
Child C must stay on **opposite sides** of the diagonal.
   * Therefore, we only need to compute **one of these two cases**, and then
**flip the grid along the main diagonal** to reuse the same logic for the other.

---

### Dynamic Programming Approach

We compute the best path for one child (say, the one starting at `(0, n - 1)`)
using DP. Then, we flip the grid to compute the best path for the other side.

Define `dp[i][j]` as the maximum number of fruits that can be collected when
reaching cell `(i, j)`.

Valid only for:

* `1 ≤ i < n - 1`
* `i + 1 ≤ j < n` (to ensure we're above the main diagonal)

Transition:

```
dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]) + fruits[i][j]
```

Initialization:

* For each row `i`, only compute `j` values such that `j > i` (i.e., strictly
above diagonal).
* Start from `j = max(n - 1 - i, i + 1)` to stay on the valid side.


*/
class Solution {
public:
  int maxCollectedFruits(vector<vector<int>>& fruits) {
    int n = fruits.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += fruits[i][i];
    }

    auto dp = [&]() -> int {
      vector<int> prev(n, INT_MIN), curr(n, INT_MIN);
      prev[n - 1] = fruits[0][n - 1];
      for (int i = 1; i < n - 1; ++i) {
        for (int j = max(n - 1 - i, i + 1); j < n; ++j) {
          int best = prev[j];
          if (j - 1 >= 0) {
            best = max(best, prev[j - 1]);
          }
          if (j + 1 < n) {
            best = max(best, prev[j + 1]);
          }
          curr[j] = best + fruits[i][j];
        }
        swap(prev, curr);
      }
      return prev[n - 1];
    };

    ans += dp();

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        swap(fruits[j][i], fruits[i][j]);
      }
    }

    ans += dp();
    return ans;
  }
};
// sub:
// https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/submissions/1726427022/?envType=daily-question&envId=2025-08-07
// sol:
// https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/solutions/7053308/3363-find-the-maximum-number-of-fruits-c-t5zg/
