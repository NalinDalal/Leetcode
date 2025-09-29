/*1039. Minimum Score Triangulation of Polygon
You have a convex n-sided polygon where each vertex has an integer value. You
are given an integer array values where values[i] is the value of the ith vertex
in clockwise order.

Polygon triangulation is a process where you divide a polygon into a set of
triangles and the vertices of each triangle must also be vertices of the
original polygon. Note that no other shapes other than triangles are allowed in
the division. This process will result in n - 2 triangles.

You will triangulate the polygon. For each triangle, the weight of that triangle
is the product of the values at its vertices. The total score of the
triangulation is the sum of these weights over all n - 2 triangles.

Return the minimum possible score that you can achieve with some triangulation
of the polygon.


Example 1:
Input: values = [1,2,3]
Output: 6
Explanation: The polygon is already triangulated, and the score of the only
triangle is 6.

Example 2:
Input: values = [3,7,4,5]
Output: 144
Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 =
245, or 3*4*5 + 3*4*7 = 144. The minimum score is 144.

Example 3:
Input: values = [1,3,1,4,1,5]
Output: 1
Explanation: The minimum score triangulation is 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1
= 13.


Constraints:
n == values.length
3 <= n <= 50
1 <= values[i] <= 100


Hint 1
Without loss of generality, there is a triangle that uses adjacent vertices A[0]
and A[N-1] (where N = A.length). Depending on your choice K of it, this breaks
down the triangulation into two subproblems A[1:K] and A[K+1:N-1].
*/
/*N sided polygon
        values[i] is length of ith side
        triangulate the polygon- returns n-2 triangles
        wt triangle=product of all sides
    score=sum of all wt
        find minimum score

If we pick a triangle `(i, k, j)` inside polygon vertices, the total cost is:
```
dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[j] *
values[k])
```

We try every possible `k` between `i` and `j`.

Base case: If `j - i < 2`, no triangle possible → `dp[i][j] = 0`.

`dp[i][j]` = minimum triangulation score of polygon slice between vertex `i` and
`j`

Final answer = `dp[0][N-1]`.
*/

class Solution {
public:
  int minScoreTriangulation(vector<int>& values) {
    int N = values.size();
    vector<vector<int>> dp(N, vector<int>(N, 0));

    // gap is the distance between i and j
    for (int gap = 2; gap < N; gap++) {
      for (int i = 0; i + gap < N; i++) {
        int j = i + gap;
        dp[i][j] = INT_MAX;
        for (int k = i + 1; k < j; k++) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] +
                                       values[i] * values[j] * values[k]);
        }
      }
    }
    return dp[0][N - 1];
  }
};
// sub:
// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/submissions/1786008385/?envType=daily-question&envId=2025-09-29
// sol:
// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/solutions/7232926/1039-minimum-score-triangulation-of-poly-66z1/
