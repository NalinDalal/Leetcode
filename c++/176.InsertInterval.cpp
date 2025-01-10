/* https://leetcode.com/problems/insert-interval/description/
57. Insert Interval
You are given an array of non-overlapping intervals intervals where
intervals[i]= [starti, endi] represent the start and the end of the ith interval
and intervals is sorted in ascending order by starti. You are also given an
interval newInterval = [start, end] that represents the start and end of another
interval.

Insert newInterval into intervals such that intervals is still sorted in
ascending order by starti and intervals still does not have any overlapping
intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array
and return it.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

Constraints:
0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105*/
#include <algorithm>
#include <vector>
using namespace std;

/*Approach
1. `Separate the Intervals`:Traverse the intervals list and add all intervals
that end before newInterval starts.
2. `Merge Overlapping Intervals`:For all intervals that overlap with
newInterval, compute the union of these intervals.
3. `Add Remaining Intervals`:Append all intervals that start after newInterval
ends.*/
class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    vector<vector<int>> result;

    for (const auto& interval : intervals) {
      // Case 1: Non-overlapping, current interval is before newInterval
      if (interval[1] < newInterval[0]) {
        result.push_back(interval);
      }
      // Case 2: Non-overlapping, current interval is after newInterval
      else if (interval[0] > newInterval[1]) {
        result.push_back(newInterval); // Add merged interval
        newInterval = interval;        // Update newInterval to the current one
      }
      // Case 3: Overlapping intervals
      else {
        newInterval[0] = min(newInterval[0], interval[0]);
        newInterval[1] = max(newInterval[1], interval[1]);
      }
    }

    // Add the final merged interval
    result.push_back(newInterval);

    return result;
  }
};

// Time : O(n)
// Space : O(n)
