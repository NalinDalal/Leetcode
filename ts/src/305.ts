//1751. Maximum Number of Events That Can Be Attended II
function maxValue(events: number[][], k: number): number {
  events.sort((a, b) => a[0] - b[0]);
  const n = events.length;

  const startTimes = events.map((e) => e[0]);

  // Binary search to find next event with startTime > endTime
  function findNextIndex(end: number): number {
    let low = 0,
      high = n;
    while (low < high) {
      const mid = (low + high) >> 1;
      if (startTimes[mid] > end) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }

  const nextIndex = new Array<number>(n);
  for (let i = 0; i < n; i++) {
    nextIndex[i] = findNextIndex(events[i][1]);
  }

  const dp: number[][] = Array.from({ length: n + 1 }, () =>
    Array(k + 1).fill(0),
  );

  for (let i = n - 1; i >= 0; i--) {
    for (let j = 1; j <= k; j++) {
      dp[i][j] = Math.max(dp[i + 1][j], events[i][2] + dp[nextIndex[i]][j - 1]);
    }
  }

  return dp[0][k];
}

//sub: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/submissions/1690500122/?envType=daily-question&envId=2025-07-08
//sol: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/solutions/6934148/1751-maximum-number-of-events-that-can-b-xrep/
