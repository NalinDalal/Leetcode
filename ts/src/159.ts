//56. Merge Intervals
function merge(intervals: number[][]): number[][] {
  if (intervals.length === 0) return [];

  // Sort intervals based on start time
  intervals.sort((a, b) => a[0] - b[0]);

  const merged: number[][] = [];

  for (const interval of intervals) {
    if (merged.length === 0 || merged[merged.length - 1][1] < interval[0]) {
      // No overlap, push new interval
      merged.push(interval);
    } else {
      // Overlapping intervals, merge them
      merged[merged.length - 1][1] = Math.max(
        merged[merged.length - 1][1],
        interval[1],
      );
    }
  }

  return merged;
}

//sub: https://leetcode.com/problems/merge-intervals/submissions/1572140957/
//sol: https://leetcode.com/problems/merge-intervals/solutions/6531398/56-merge-intervals-by-nalindalal2004-uam4/
