/*3197. Find the Minimum Area to Cover All Ones II
You are given a 2D binary array grid. You need to find 3 non-overlapping
rectangles having non-zero areas with horizontal and vertical sides such that
all the 1's in grid lie inside these rectangles.

Return the minimum possible sum of the area of these rectangles.

Note that the rectangles are allowed to touch.



Example 1:
Input: grid = [[1,0,1],[1,1,1]]
Output: 5
Explanation:
The 1's at (0, 0) and (1, 0) are covered by a rectangle of area 2.
The 1's at (0, 2) and (1, 2) are covered by a rectangle of area 2.
The 1 at (1, 1) is covered by a rectangle of area 1.


Example 2:
Input: grid = [[1,0,1,0],[0,1,0,1]]
Output: 5
Explanation:
The 1's at (0, 0) and (0, 2) are covered by a rectangle of area 3.
The 1 at (1, 1) is covered by a rectangle of area 1.
The 1 at (1, 3) is covered by a rectangle of area 1.


Constraints:

1 <= grid.length, grid[i].length <= 30
grid[i][j] is either 0 or 1.
The input is generated such that there are at least three 1's in grid.



Hint 1
Consider covering using 2 rectangles. As the rectangles don’t overlap, one of
the rectangles must either be vertically above or horizontally left to the
other. Hint 2 To find the minimum area, check all possible vertical and
horizontal splits. Hint 3 For 3 rectangles, extend the idea to first covering
using one rectangle, and then try splitting leftover ones both horizontally and
vertically.
*/

/* Intuition:
We want 3 axis-aligned rectangles that cover all the 1s in the grid. Rectangles
must not overlap (but can touch). We want to minimize the sum of rectangle
areas.

1. Bounding box of 1s in any subregion:
For any subgrid, the minimal rectangle that covers all 1s is just:
```
(min_row, min_col) → (max_row, max_col)
```
Area = `(max_row - min_row + 1) * (max_col - min_col + 1)`.

So if we can partition all the 1s into 3 groups (disjoint), the cost is the sum
of the 3 bounding boxes’ areas.

2. Non-overlapping requirement:
Rectangles can’t overlap. This means partitioning must be done by cuts:
    - Vertical cuts (left/right)
    - Horizontal cuts (top/bottom)
    - Or mix (like one rectangle first, then cut the remaining part).

3. Strategy (based on hints):
- First, try splitting grid into 3 parts by straight cuts:
    - 2 vertical cuts (3 vertical stripes) with the left side they split
horizontally.
    - 2 horizontal cuts (3 horizontal stripes) with the top side split
vertically..
    - 1 vertical + 1 horizontal (making 3 rectangles).
- Compute min area cover for each part.
    */
/* Approach:
1. Precompute bounding boxes efficiently for any prefix of rows/cols.

2. Try:
    - 3 vertical stripes
    - 3 horizontal stripes
    - vertical cut + split right horizontally
    - vertical cut + split left horizontally ⟵ (missing before)
    - horizontal cut + split bottom vertically
    - horizontal cut + split top vertically ⟵ (missing before)

3. Take minimum.

- Function `areaOfOnes(r1, r2, c1, c2)` → returns bounding box area of 1s in
subgrid. If no 1s, return INF (invalid).

- Precompute prefix bounding boxes to speed up queries.

- Enumerate all cut positions (≤30), so complexity is fine: O(n³).
*/

class Solution {
public:
  int minimumSum(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    const int INF = 1e9;

    auto rectArea = [&](int r1, int r2, int c1, int c2) {
      int minr = n, maxr = -1, minc = m, maxc = -1;
      for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j) {
          if (grid[i][j]) {
            minr = min(minr, i);
            maxr = max(maxr, i);
            minc = min(minc, j);
            maxc = max(maxc, j);
          }
        }
      }
      if (maxr == -1)
        return INF; // no 1s in this subgrid
      return (maxr - minr + 1) * (maxc - minc + 1);
    };

    int ans = INF;

    // Case 1: three vertical stripes
    for (int c1 = 0; c1 < m - 2; ++c1) {
      for (int c2 = c1 + 1; c2 < m - 1; ++c2) {
        int a1 = rectArea(0, n - 1, 0, c1);
        int a2 = rectArea(0, n - 1, c1 + 1, c2);
        int a3 = rectArea(0, n - 1, c2 + 1, m - 1);
        if (a1 != INF && a2 != INF && a3 != INF)
          ans = min(ans, a1 + a2 + a3);
      }
    }

    // Case 2: three horizontal stripes
    for (int r1 = 0; r1 < n - 2; ++r1) {
      for (int r2 = r1 + 1; r2 < n - 1; ++r2) {
        int a1 = rectArea(0, r1, 0, m - 1);
        int a2 = rectArea(r1 + 1, r2, 0, m - 1);
        int a3 = rectArea(r2 + 1, n - 1, 0, m - 1);
        if (a1 != INF && a2 != INF && a3 != INF)
          ans = min(ans, a1 + a2 + a3);
      }
    }

    // Case 3: vertical cut + split RIGHT horizontally
    for (int c = 0; c < m - 1; ++c) {
      int left = rectArea(0, n - 1, 0, c);
      if (left == INF)
        continue;
      for (int r = 0; r < n - 1; ++r) {
        int a2 = rectArea(0, r, c + 1, m - 1);
        int a3 = rectArea(r + 1, n - 1, c + 1, m - 1);
        if (a2 != INF && a3 != INF)
          ans = min(ans, left + a2 + a3);
      }
    }

    // Case 4: vertical cut + split LEFT horizontally (missing before)
    for (int c = 0; c < m - 1; ++c) {
      int right = rectArea(0, n - 1, c + 1, m - 1);
      if (right == INF)
        continue;
      for (int r = 0; r < n - 1; ++r) {
        int a2 = rectArea(0, r, 0, c);
        int a3 = rectArea(r + 1, n - 1, 0, c);
        if (a2 != INF && a3 != INF)
          ans = min(ans, right + a2 + a3);
      }
    }

    // Case 5: horizontal cut + split BOTTOM vertically
    for (int r = 0; r < n - 1; ++r) {
      int top = rectArea(0, r, 0, m - 1);
      if (top == INF)
        continue;
      for (int c = 0; c < m - 1; ++c) {
        int a2 = rectArea(r + 1, n - 1, 0, c);
        int a3 = rectArea(r + 1, n - 1, c + 1, m - 1);
        if (a2 != INF && a3 != INF)
          ans = min(ans, top + a2 + a3);
      }
    }

    // Case 6: horizontal cut + split TOP vertically (missing before)
    for (int r = 0; r < n - 1; ++r) {
      int bottom = rectArea(r + 1, n - 1, 0, m - 1);
      if (bottom == INF)
        continue;
      for (int c = 0; c < m - 1; ++c) {
        int a2 = rectArea(0, r, 0, c);
        int a3 = rectArea(0, r, c + 1, m - 1);
        if (a2 != INF && a3 != INF)
          ans = min(ans, bottom + a2 + a3);
      }
    }

    return ans;
  }
};
// sub:
// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/submissions/1744906966/?envType=daily-question&envId=2025-08-23
// sol:
// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/solutions/7111782/3197-find-the-minimum-area-to-cover-all-3gb6n/
