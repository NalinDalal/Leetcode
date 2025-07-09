/*3439. Reschedule Meetings for Maximum Free Time I
You are given an integer eventTime denoting the duration of an event, where the
event occurs from time t = 0 to time t = eventTime.

You are also given two integer arrays startTime and endTime, each of length n.
These represent the start and end time of n non-overlapping meetings, where the
ith meeting occurs during the time [startTime[i], endTime[i]].

You can reschedule at most k meetings by moving their start time while
maintaining the same duration, to maximize the longest continuous period of free
time during the event.

The relative order of all the meetings should stay the same and they should
remain non-overlapping.

Return the maximum amount of free time possible after rearranging the meetings.

Note that the meetings can not be rescheduled to a time outside the event.



Example 1:
Input: eventTime = 5, k = 1, startTime = [1,3], endTime = [2,5]
Output: 2
Explanation:
Reschedule the meeting at [1, 2] to [2, 3], leaving no meetings during the time
[0, 2].

Example 2:
Input: eventTime = 10, k = 1, startTime = [0,2,9], endTime = [1,4,10]
Output: 6
Explanation:
Reschedule the meeting at [2, 4] to [1, 3], leaving no meetings during the time
[3, 9].

Example 3:
Input: eventTime = 5, k = 2, startTime = [0,1,2,3,4], endTime = [1,2,3,4,5]
Output: 0
Explanation:
There is no time during the event not occupied by meetings.



Constraints:

1 <= eventTime <= 109
n == startTime.length == endTime.length
2 <= n <= 105
1 <= k <= n
0 <= startTime[i] < endTime[i] <= eventTime
endTime[i] <= startTime[i + 1] where i lies in the range [0, n - 2].

Hint 1
In a sequence of K meetings and K + 1 gaps, you could move all meetings to the
start of the sequence to get the max free time.
Hint 2
Use a sliding window of K+ 1 size to store sum of gaps and take the maximum.
*/
/*
Intuition:
When shifting k adjacent meetings to the beginning of the event timeline, you
can potentially merge k + 1 free time intervals (the ones before, between, and
after these k meetings). This gives the maximum possible free time, assuming
optimal placement.

Let’s define:

n = total number of available meetings

eventTime = total time duration

startTime[], endTime[] = arrays representing start and end of each meeting

## Key Observations
For a window of k adjacent meetings, we aim to compute:

left: start of the available time before the first of these k meetings

right: end of the available time after the last of these k meetings

totalDuration: sum of durations of these k meetings

Then:

Total free time = (right - left) - totalDuration
  */

/*# Approach

### Key Idea

Once the `k` adjacent meetings to be shifted are fixed, let:

* the **start time of the first free time interval to be merged** be `left`
* the **end time of the last free time interval to be merged** be `right`

Then, the **total length of the merged `k+1` free intervals** is equal to:

```
(right − left) − total_duration_of_k_meetings
```

---

## Efficient Calculation with Prefix Sums

We **precompute prefix sums** of meeting durations to compute the total duration
of any `k` adjacent meetings efficiently.

Let:

* `sum[i]` = prefix sum of durations up to `i` (exclusive)
* `duration[i] = endTime[i] - startTime[i]`

So:

```text
total_duration = sum[i+1] - sum[i-k+1]
```

where `i` is the index of the **rightmost meeting** among the `k` adjacent ones
(`i ≥ k−1`).

---

## Left & Right Boundary Calculation

Let the current window of `k` meetings be from `[i-k+1, i]`.

Then:

* **Left boundary** (i.e., end of the previous meeting):
$$
left_i =
\begin{cases}
0 & \text{if } i \leq k - 1 \\
endTime[i - k] & \text{if } i > k - 1
\end{cases}
$$

* **Right boundary** (i.e., start of next meeting):
$$
right_i =
\begin{cases}
eventTime & \text{if } i = n - 1 \\
startTime[i + 1] & \text{otherwise}
\end{cases}
$$

---

## Final Formula

For each valid `i` (`i ≥ k−1`), compute:

```text
free_time_i = (right_i − left_i) − (sum[i+1] − sum[i−k+1])
```

Return the **maximum** of all such `free_time_i`.
         */

class Solution {
public:
  int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                  vector<int>& endTime) {
    int n = startTime.size(), res = 0;
    vector<int> sum(n + 1);
    for (int i = 0; i < n; i++) {
      sum[i + 1] = sum[i] + endTime[i] - startTime[i];
    }
    for (int i = k - 1; i < n; i++) {
      int right = i == n - 1 ? eventTime : startTime[i + 1];
      int left = i == k - 1 ? 0 : endTime[i - k];
      res = max(res, right - left - (sum[i + 1] - sum[i - k + 1]));
    }
    return res;
  }
};
// sub:
// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/submissions/1691438382/?envType=daily-question&envId=2025-07-09
// sol:
// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/solutions/6937189/3439-reschedule-meetings-for-maximum-fre-1152/
