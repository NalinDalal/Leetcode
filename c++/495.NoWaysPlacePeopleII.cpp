/*3027. Find the Number of Ways to Place People II
You are given a 2D array points of size n x 2 representing integer coordinates
of some points on a 2D-plane, where points[i] = [xi, yi].

We define the right direction as positive x-axis (increasing x-coordinate) and
the left direction as negative x-axis (decreasing x-coordinate). Similarly, we
define the up direction as positive y-axis (increasing y-coordinate) and the
down direction as negative y-axis (decreasing y-coordinate)

You have to place n people, including Alice and Bob, at these points such that
there is exactly one person at every point. Alice wants to be alone with Bob, so
Alice will build a rectangular fence with Alice's position as the upper left
corner and Bob's position as the lower right corner of the fence (Note that the
fence might not enclose any area, i.e. it can be a line). If any person other
than Alice and Bob is either inside the fence or on the fence, Alice will be
sad.

Return the number of pairs of points where you can place Alice and Bob, such
that Alice does not become sad on building the fence.

Note that Alice can only build a fence with Alice's position as the upper left
corner, and Bob's position as the lower right corner. For example, Alice cannot
build either of the fences in the picture below with four corners (1, 1), (1,
3), (3, 1), and (3, 3), because:

With Alice at (3, 3) and Bob at (1, 1), Alice's position is not the upper left
corner and Bob's position is not the lower right corner of the fence. With Alice
at (1, 3) and Bob at (1, 1), Bob's position is not the lower right corner of the
fence.



Example 1:


Input: points = [[1,1],[2,2],[3,3]]
Output: 0
Explanation: There is no way to place Alice and Bob such that Alice can build a
fence with Alice's position as the upper left corner and Bob's position as the
lower right corner. Hence we return 0. Example 2:


Input: points = [[6,2],[4,4],[2,6]]
Output: 2
Explanation: There are two ways to place Alice and Bob such that Alice will not
be sad:
- Place Alice at (4, 4) and Bob at (6, 2).
- Place Alice at (2, 6) and Bob at (4, 4).
You cannot place Alice at (2, 6) and Bob at (6, 2) because the person at (4, 4)
will be inside the fence. Example 3:


Input: points = [[3,1],[1,3],[1,1]]
Output: 2
Explanation: There are two ways to place Alice and Bob such that Alice will not
be sad:
- Place Alice at (1, 1) and Bob at (3, 1).
- Place Alice at (1, 3) and Bob at (1, 1).
You cannot place Alice at (1, 3) and Bob at (3, 1) because the person at (1, 1)
will be on the fence. Note that it does not matter if the fence encloses any
area, the first and second fences in the image are valid.


Constraints:

2 <= n <= 1000
points[i].length == 2
-109 <= points[i][0], points[i][1] <= 109
All points[i] are distinct.



Hint 1
Sort the points by x-coordinate in non-decreasing order and break the tie by
sorting the y-coordinate in non-increasing order. Hint 2 Now consider two points
upper-left corner points[i] and lower-right corner points[j], such that i < j
and points[i][0] <= points[j][0] and points[i][1] >= points[j][1]. Hint 3
Instead of brute force looping, we can save the largest y-coordinate that is no
larger than points[i][1] when looping on j, say the value is m. And if m <
points[j][1], the upper-left and lower-right corner pair is valid. Hint 4 The
actual values don’t matter, we can compress all x-coordinates and y-coordinates
to the range [1, n]. Can we use prefix sum now?
*/

/*counting valid pairs of points (i, j) where:
- i < j
- points[i].x <= points[j].x
- points[i].y >= points[j].y

1. Sort
    - Sort points by x ascending.
    - If x ties, sort by y descending.

2. Coordinate Compression
    - Extract all unique y values.
    - Map them to [1..n].

3. Iterate over all pairs via FenWick Tree
    - for each `points[j]`, if there exists an earlier point points[i] with `y
>= points[j]*y`; but don't want duplicates
    - Keep track of the maximum y seen so far (but compressed).
    - Insert it into a Fenwick tree so we can query efficiently.
    - When processing `points[j]`, query if any earlier point had `y >=
points[j]*y`.

4. Count valid Pairs
    - For each `points[j]`, query `Fenwick.sum(maxYIndex) -
Fenwick.sum(yIndex[j]-1)` to know if there exists some earlier `y` not smaller
than current.
    - If yes, increment answer.
    - Update the Fenwick with this point’s `y`.

Since the points are already sorted by x, the condition on x
B
j
​

​
  is automatically satisfied. Moreover, as we traverse B
j
​
 , x
B
j
​

​
  is guaranteed to be non-decreasing. This leads to an important observation: if
(A
i
​
 ,B
1
​
 ) is a valid pair and later (A
i
​
 ,B
2
​
 ) is also valid, then

x
B
2
​

​
 ≥x
B
1
​

​
 ,y
B
2
​

​
 ≥y
B
1
​

​
 ,B
1
​


=B
2
​


This observation is crucial: once a legal B
j
​
  is selected, the effective lower and left boundaries shrink monotonically. In
other words, for the same A
i
​
 , the set of valid B
j
​
  extends in a monotonic fashion from the lower-right and upward directions.
This makes it possible to update the boundaries dynamically while selecting
valid pairs.
*/
class Solution {
public:
  int numberOfPairs(vector<vector<int>>& points) {
    int ans = 0;
    sort(points.begin(), points.end(),
         [](const vector<int>& a, const vector<int>& b) {
           return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
         });

    for (int i = 0; i < points.size() - 1; i++) {
      const auto& pointA = points[i];
      int xMin = pointA[0] - 1;
      int xMax = INT_MAX;
      int yMin = INT_MIN;
      int yMax = pointA[1] + 1;

      for (int j = i + 1; j < points.size(); j++) {
        const auto& pointB = points[j];
        if (pointB[0] > xMin && pointB[0] < xMax && pointB[1] > yMin &&
            pointB[1] < yMax) {
          ans++;
          xMin = pointB[0];
          yMin = pointB[1];
        }
      }
    }
    return ans;
  }
};
// sub:
// https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/submissions/1758201028/?envType=daily-question&envId=2025-09-03
// sol:
// https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/solutions/7151371/3027-find-the-number-of-ways-to-place-pe-ds67/
