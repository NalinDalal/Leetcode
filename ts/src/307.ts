//3440. Reschedule Meetings for Maximum Free Time II
function maxFreeTime(
  eventTime: number,
  startTime: number[],
  endTime: number[],
): number {
  const n = startTime.length;
  const q = new Array<boolean>(n).fill(false);

  let t1 = 0,
    t2 = 0;

  for (let i = 0; i < n; i++) {
    if (endTime[i] - startTime[i] <= t1) {
      q[i] = true;
    }
    t1 = Math.max(t1, startTime[i] - (i === 0 ? 0 : endTime[i - 1]));

    const j = n - i - 1;
    if (endTime[j] - startTime[j] <= t2) {
      q[j] = true;
    }
    t2 = Math.max(t2, (i === 0 ? eventTime : startTime[n - i]) - endTime[j]);
  }

  let res = 0;
  for (let i = 0; i < n; i++) {
    const left = i === 0 ? 0 : endTime[i - 1];
    const right = i === n - 1 ? eventTime : startTime[i + 1];
    if (q[i]) {
      res = Math.max(res, right - left);
    } else {
      res = Math.max(res, right - left - (endTime[i] - startTime[i]));
    }
  }

  return res;
}
//sub: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/submissions/1692934048/?envType=daily-question&envId=2025-07-10
//sol: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/solutions/6942151/3440-reschedule-meetings-for-maximum-fre-r0s2/
