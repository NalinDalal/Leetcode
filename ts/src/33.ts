// 57.Insert Interval

function insert(intervals: number[][], newInterval: number[]): number[][] {
  const result: number[][] = [];

  for (const interval of intervals) {
    // Case 1: Non-overlapping, current interval is before newInterval
    if (interval[1] < newInterval[0]) {
      result.push(interval);
    }
    // Case 2: Non-overlapping, current interval is after newInterval
    else if (interval[0] > newInterval[1]) {
      result.push(newInterval); // Add merged interval
      newInterval = interval; // Update newInterval to the current one
    }
    // Case 3: Overlapping intervals
    else {
      newInterval[0] = Math.min(newInterval[0], interval[0]);
      newInterval[1] = Math.max(newInterval[1], interval[1]);
    }
  }

  // Add the final merged interval
  result.push(newInterval);

  return result;
}
// sub: https://leetcode.com/problems/insert-interval/submissions/1504048981/
