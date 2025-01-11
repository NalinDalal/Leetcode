/* https://leetcode.com/problems/non-overlapping-intervals/description/

435. Non-overlapping Intervals

Given an array of intervals intervals where intervals[i] = [starti, endi],
return the minimum number of intervals you need to remove to make the rest of
the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For
example, [1, 2] and [2, 3] are non-overlapping.



Example 1:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are
non-overlapping.

Example 2:
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals
non-overlapping.

Example 3:
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already
non-overlapping.


Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104*/

/* Sort the intervals by their end time: This ensures we can greedily find the
maximum number of non-overlapping intervals. Iterate through intervals: Track
the end of the last included interval and count overlapping intervals. Remove
Overlaps: If an interval overlaps with the last included interval, increment the
count of removed intervals.*/

#include <algorithms>
#include <vector>

using std::vector;
class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // Sort intervals by end time
    sort(
        intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });

    int n = intervals.size();
    int end = INT_MIN; // Initialize the end of the last included interval
    int removed = 0;

    for (const auto& interval : intervals) {
      if (interval[0] >= end) {
        // Non-overlapping interval, update the end
        end = interval[1];
      } else {
        // Overlapping interval, remove it
        removed++;
      }
    }

    return removed;
  }
};
// Time: O(n log n)
// Space: O(1)
// 88.33%
// sub:
// https://leetcode.com/problems/non-overlapping-intervals/submissions/1505320676/
// sol:
// https://leetcode.com/problems/non-overlapping-intervals/solutions/6266016/435-non-overlapping-intervals8833-by-nal-5tnk/
