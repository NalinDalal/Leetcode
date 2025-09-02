/*3025. Find the Number of Ways to Place People I
You are given a 2D array points of size n x 2 representing integer coordinates
of some points on a 2D plane, where points[i] = [xi, yi].

Count the number of pairs of points (A, B), where

A is on the upper left side of B, and
there are no other points in the rectangle (or line) they make (including the
border). Return the count.



Example 1:

Input: points = [[1,1],[2,2],[3,3]]

Output: 0

Explanation:



There is no way to choose A and B so A is on the upper left side of B.

Example 2:

Input: points = [[6,2],[4,4],[2,6]]

Output: 2

Explanation:



The left one is the pair (points[1], points[0]), where points[1] is on the upper
left side of points[0] and the rectangle is empty. The middle one is the pair
(points[2], points[1]), same as the left one it is a valid pair. The right one
is the pair (points[2], points[0]), where points[2] is on the upper left side of
points[0], but points[1] is inside the rectangle so it's not a valid pair.
Example 3:

Input: points = [[3,1],[1,3],[1,1]]

Output: 2

Explanation:



The left one is the pair (points[2], points[0]), where points[2] is on the upper
left side of points[0] and there are no other points on the line they form. Note
that it is a valid state when the two points form a line. The middle one is the
pair (points[1], points[2]), it is a valid pair same as the left one. The right
one is the pair (points[1], points[0]), it is not a valid pair as points[2] is
on the border of the rectangle.


Constraints:

2 <= n <= 50
points[i].length == 2
0 <= points[i][0], points[i][1] <= 50
All points[i] are distinct.

Hint 1
We can enumerate all the upper-left and lower-right corners.
Hint 2
If the upper-left corner is (x1, y1) and lower-right corner is (x2, y2), check
that there is no point (x, y) such that x1 <= x <= x2 and y2 <= y <= y1.
*/

/*
### Constraints
* Number of points `n` is between 0 and 50.
* We use a **double loop** to traverse all pairs of points.

```
for each pair (i, j):
if (point i cannot be top-left OR point j cannot be bottom-right)
continue
check if any third point lies inside the rectangle
if none found → count this pair

````

To determine whether a point lies within a given rectangle, we only need to
check if its coordinates `(x, y)` fall within the horizontal and vertical limits
of the rectangle. Checking `x` and `y` separately is sufficient. Additionally,
since the problem specifies that the rectangle includes its boundaries, we use
**closed intervals** in our checks.

When there are only two points, the third loop is never entered, so we handle
this as a **special case** directly.

---

### Problem Restatement

We are given up to 50 points. For every **ordered pair of points** `(A, B)`, we
can form a rectangle if we treat `A` as the **top-left** corner and `B` as the
**bottom-right** corner (so `A.x ≤ B.x` and `A.y ≥ B.y`).

We want to count how many such rectangles are **valid**, where no other point
lies **strictly inside** them. Points on the boundary are allowed.

---

### Algorithm

1. **Input**: number of points `n` (`0 ≤ n ≤ 50`), and coordinates
   `p[1..n] = (x, y)`.

2. **Special Case (n == 2)**:
   * With only two points, the rectangle formed by them is always valid (no
     third point exists).
   * Answer is `1`.

3. **General Case (n ≥ 3)**:
   * Use a **double loop** to consider all ordered pairs `(i, j)`:
     ```
     for i = 0 to n-1
         for j = 0 to n-1
     ```
   * Skip invalid pairs:
     - If `i == j`, skip.
     - If `points[i].x > points[j].x` or `points[i].y < points[j].y`, skip
       (since `i` cannot be top-left or `j` cannot be bottom-right).
   * For each valid pair `(i, j)`:
     - Define rectangle limits:
       ```
       xmin = points[i].x
       xmax = points[j].x
       ymax = points[i].y
       ymin = points[j].y
       ```
     - Check every other point `k ≠ i, j`:
       - If `xmin ≤ p[k].x ≤ xmax` and `ymin ≤ p[k].y ≤ ymax`, then `k` lies
         inside or on the boundary.
       - If such a point exists **strictly inside**, mark this rectangle as
         illegal and skip.
   * If no illegal point found, increment `ans`.

4. **Return `ans`**.

---

### Why Closed Intervals?

Because the rectangle includes its boundary, checks must be done with
inequalities of the form:

````

xmin ≤ x ≤ xmax
ymin ≤ y ≤ ymax

```

This way, boundary points are counted as valid.

---

### Pseudocode

```

function numberOfPairs(points):
n = size(points)
if n == 2:
return 1

```
ans = 0
for i in range(0, n):
    for j in range(0, n):
        if i == j: continue
        if points[i].x > points[j].x or points[i].y < points[j].y:
            continue

        valid = true
        for k in range(0, n):
            if k == i or k == j: continue

            if points[i].x <= points[k].x <= points[j].x and
               points[j].y <= points[k].y <= points[i].y:
                valid = false
                break

        if valid:
            ans += 1

return ans
```




*/

class Solution {
public:
  int numberOfPairs(vector<vector<int>>& points) {
    int ans = 0;
    int n = points.size();

    for (int i = 0; i < n; i++) {
      auto& pointA = points[i];
      for (int j = 0; j < n; j++) {
        vector<int> pointB = points[j];
        if (i == j || !(pointA[0] <= pointB[0] && pointA[1] >= pointB[1])) {
          continue;
        }
        if (n == 2) {
          ans++;
          continue;
        }

        bool illegal = false;
        for (int k = 0; k < n; k++) {
          if (k == i || k == j) {
            continue;
          }

          auto& pointTmp = points[k];
          bool isXContained =
              pointTmp[0] >= pointA[0] && pointTmp[0] <= pointB[0];
          bool isYContained =
              pointTmp[1] <= pointA[1] && pointTmp[1] >= pointB[1];
          if (isXContained && isYContained) {
            illegal = true;
            break;
          }
        }
        if (!illegal) {
          ans++;
        }
      }
    }
    return ans;
  }
};
// sub:
// https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/submissions/1757036076/?envType=daily-question&envId=2025-09-02
// sol:
// https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/solutions/7148156/3025-find-the-number-of-ways-to-place-pe-cw1y/
