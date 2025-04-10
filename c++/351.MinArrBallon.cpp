/* 452. Minimum Number of Arrows to Burst Balloons

There are some spherical balloons taped onto a flat wall that represents the
XY-plane. The balloons are represented as a 2D integer array points where
points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches
between xstart and xend. You do not know the exact y-coordinates of the
balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from
different points along the x-axis. A balloon with xstart and xend is burst by an
arrow shot at x if xstart <= x <= xend. There is no limit to the number of
arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting
any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to
burst all balloons.



Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
Example 2:

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Explanation: One arrow needs to be shot for each balloon for a total of 4
arrows. Example 3:

Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
- Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].


Constraints:

1 <= points.length <= 105
points[i].length == 2
-231 <= xstart < xend <= 231 - 1
*/

// Intuition:
//  given xstart and xend, find how many ballons overlap with each other
//  like [[10,16],[2,8],[1,6],[7,12]]:
//[2,8] overlap with [1,6]- count=1
//[10,16] overlap with [7,12]-count=2
//  return count
//[[1,2],[3,4],[5,6],[7,8]]
//  total 4
//[[1,2],[2,3],[3,4],[4,5]]
//  total 2{[1,2],[2,3] can be taken as 1; [3,4],[4,5] can be taken as 1}
//  Approach:
//- Sort intervals by their end coordinate
//- Initialize arrowCount = 1 (since at least one is needed)
//- Track the end of the last arrow shot
//- For each balloon, if its start is greater than end, shoot a new arrow
class Solution {
public:
  int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty())
      return 0;

    // Sort by the end of the interval
    sort(points.begin(), points.end(),
         [](auto& a, auto& b) { return a[1] < b[1]; });

    int arrows = 1;
    int end = points[0][1];

    for (const auto& point : points) {
      if (point[0] > end) {
        arrows++;
        end = point[1];
      }
    }

    return arrows;
  }
};
// sub:
// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/submissions/1602551533/?envType=study-plan-v2&envId=top-interview-150
// sol:
// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/solutions/6636009/452-minimum-number-of-arrows-to-burst-ba-9inp/
