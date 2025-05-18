/* 1931. Painting a Grid With Three Different Colors
You are given two integers m and n. Consider an m x n grid where each cell is
initially white. You can paint each cell red, green, or blue. All cells must be
painted.

Return the number of ways to color the grid with no two adjacent cells having
the same color. Since the answer can be very large, return it modulo 109 + 7.


Example 1:
Input: m = 1, n = 1
Output: 3
Explanation: The three possible colorings are shown in the image above.

Example 2:
Input: m = 1, n = 2
Output: 6
Explanation: The six possible colorings are shown in the image above.

Example 3:
Input: m = 5, n = 5
Output: 580986


Constraints:
1 <= m <= 5
1 <= n <= 1000

Hint 1: Represent each colored column by a bitmask based on each cell color.
Hint 2: Use bitmasks DP with state (currentCell, prevColumn).
*/

/* each cell 3 clour, no neighbour has same colour
dp state to reprensent num ways to colour grid
dp[i][j] for ixj grid

when n or m are 1, we can calculate directly
if previous has some colour, then present has only 2 choices
hence dp[m][n]=(ways to color the previous columns)×(choices for the new column)

make sure results are modulo 10E9+7

first calculate like dp[1][1], dp[1][2], then slowly fill all

1. **Ternary Representation**:
   Each row of the grid uses colors: red (0), green (1), blue (2). So, a
coloring of `m` columns is like a ternary number (base-3) of length `m`.

2. **Enumerating Possibilities**:
   We loop through all ternary numbers from `0` to `3^m - 1` to generate every
possible coloring scheme for one row.

3. **Valid Row Check**:
   A row is valid if no two adjacent columns have the same color (i.e., no
repeated digits in the ternary number).

4. **Dynamic Programming (DP) Setup**:
   Let `f[i][mask]` represent the number of ways to color rows `0` to `i`, with
row `i` colored as `mask`.

5. **State Transition**:
   For each valid `mask` for row `i`, add all values `f[i-1][mask']` where
`mask'` is valid for row `i-1` and has different colors at each column
(position-wise) from `mask`.

6. **Base Case**:
   For the first row (`i = 0`), set `f[0][mask] = 1` if the coloring is valid
(no adjacent duplicates); otherwise, set it to `0`.

7. **Optimization**:
   Since only `f[i-1][..]` is needed at each step, we can save memory using two
arrays of size `3^m` and alternate between them.
*/
class Solution {
private:
  static constexpr int mod = 1000000007;

public:
  int colorTheGrid(int m, int n) {
    // Hash mapping stores all valid coloration schemes for a single row
    // that meet the requirements The key represents mask, and the value
    // represents the ternary string of mask (stored as a list)
    unordered_map<int, vector<int>> valid;

    // Enumerate masks that meet the requirements within the range [0, 3^m)
    int mask_end = pow(3, m);
    for (int mask = 0; mask < mask_end; ++mask) {
      vector<int> color;
      int mm = mask;
      for (int i = 0; i < m; ++i) {
        color.push_back(mm % 3);
        mm /= 3;
      }
      bool check = true;
      for (int i = 0; i < m - 1; ++i) {
        if (color[i] == color[i + 1]) {
          check = false;
          break;
        }
      }
      if (check) {
        valid[mask] = move(color);
      }
    }

    // Preprocess all (mask1, mask2) binary tuples, satisfying mask1 and
    // mask2 When adjacent rows, the colors of the two cells in the same
    // column are different
    unordered_map<int, vector<int>> adjacent;
    for (const auto& [mask1, color1] : valid) {
      for (const auto& [mask2, color2] : valid) {
        bool check = true;
        for (int i = 0; i < m; ++i) {
          if (color1[i] == color2[i]) {
            check = false;
            break;
          }
        }
        if (check) {
          adjacent[mask1].push_back(mask2);
        }
      }
    }

    vector<int> f(mask_end);
    for (const auto& [mask, _] : valid) {
      f[mask] = 1;
    }
    for (int i = 1; i < n; ++i) {
      vector<int> g(mask_end);
      for (const auto& [mask2, _] : valid) {
        for (int mask1 : adjacent[mask2]) {
          g[mask2] += f[mask1];
          if (g[mask2] >= mod) {
            g[mask2] -= mod;
          }
        }
      }
      f = move(g);
    }

    int ans = 0;
    for (int num : f) {
      ans += num;
      if (ans >= mod) {
        ans -= mod;
      }
    }
    return ans;
  }
};
// sub:
// https://leetcode.com/problems/painting-a-grid-with-three-different-colors/submissions/1637070388/?envType=daily-question&envId=2025-05-18
