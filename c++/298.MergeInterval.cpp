/* 56. Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all
overlapping intervals, and return an array of the non-overlapping intervals that
cover all the intervals in the input.



Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.


Constraints:
1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // basically merge the overlapping intervals
    // overlapping interval->say int1,int2
    // now if int1.end>=int2.start then  int2 is deleted and int1.end is
    // replaced by int2.end

    /*    vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++) {
          if (i == 0) {
            ans.push_back(intervals[i]);
            continue;
          }
          if (intervals[i][0] <= ans.back()[1]) {
            max(ans.back()[1] , intervals[i][1])
          } else {
            ans.push_back(intervals[i]);
          }
        }
        return ans;
      */
    if (intervals.empty())
      return {}; // Handle empty input case

    vector<vector<int>> ans;
    // start with starti then uske endi ko leke check for other starti
    sort(intervals.begin(),
         intervals.end()); // Sort intervals based on start time

    for (const auto& interval : intervals) {
      if (ans.empty() || ans.back()[1] < interval[0]) {
        // No overlap, push new interval
        ans.push_back(interval);
      } else {
        // Overlapping intervals, merge them
        ans.back()[1] = max(ans.back()[1], interval[1]);
      }
    }
    return ans;
  }
};

/* # Approach
- Handle for empty input
- sort given intervals
- check for overlap
- if no overlap found then push into new array
- else merge the overlaps*/

// Time: O(nlogn)
// Space: O(n)
// sub: https://leetcode.com/problems/merge-intervals/submissions/1572135675/
// sol:
// https://leetcode.com/problems/merge-intervals/solutions/6531398/56-merge-intervals-by-nalindalal2004-uam4/
