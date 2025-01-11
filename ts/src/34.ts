//435. Non-overlapping Intervals
function eraseOverlapIntervals(intervals: number[][]): number {
  // Sort intervals by their end time
  intervals.sort((a, b) => a[1] - b[1]);

  const n = intervals.length;
  let end = Number.MIN_SAFE_INTEGER; // Initialize the end of the last included interval
  let removed = 0;

  for (const interval of intervals) {
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
//sub: https://leetcode.com/problems/non-overlapping-intervals/submissions/1505320676/
//soln: https://leetcode.com/problems/non-overlapping-intervals/solutions/6266016/435-non-overlapping-intervals8833-by-nal-5tnk/
