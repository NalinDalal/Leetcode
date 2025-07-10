/*3440. Reschedule Meetings for Maximum Free Time II

You are given an integer eventTime denoting the duration of an event. You are
also given two integer arrays startTime and endTime, each of length n.

These represent the start and end times of n non-overlapping meetings that occur
during the event between time t = 0 and time t = eventTime, where the ith
meeting occurs during the time [startTime[i], endTime[i]].

You can reschedule at most one meeting by moving its start time while
maintaining the same duration, such that the meetings remain non-overlapping, to
maximize the longest continuous period of free time during the event.

Return the maximum amount of free time possible after rearranging the meetings.

Note that the meetings can not be rescheduled to a time outside the event and
they should remain non-overlapping.

Note: In this version, it is valid for the relative ordering of the meetings to
change after rescheduling one meeting.



Example 1:

Input: eventTime = 5, startTime = [1,3], endTime = [2,5]

Output: 2

Explanation:



Reschedule the meeting at [1, 2] to [2, 3], leaving no meetings during the time
[0, 2].

Example 2:

Input: eventTime = 10, startTime = [0,7,9], endTime = [1,8,10]

Output: 7

Explanation:



Reschedule the meeting at [0, 1] to [8, 9], leaving no meetings during the time
[0, 7].

Example 3:

Input: eventTime = 10, startTime = [0,3,7,9], endTime = [1,4,8,10]

Output: 6

Explanation:



Reschedule the meeting at [3, 4] to [8, 9], leaving no meetings during the time
[1, 7].

Example 4:

Input: eventTime = 5, startTime = [0,1,2,3,4], endTime = [1,2,3,4,5]

Output: 0

Explanation:

There is no time during the event not occupied by meetings.



Constraints:

1 <= eventTime <= 109
n == startTime.length == endTime.length
2 <= n <= 105
0 <= startTime[i] < endTime[i] <= eventTime
endTime[i] <= startTime[i + 1] where i lies in the range [0, n - 2].

Hint 1
If we reschedule a meeting earlier or later, we need to find a gap of length at
least endTime[i] - startTime[i]. Try maintaining the gaps in some sorted data
structure.
*/

// intuition
// ans must be all gap b/w eventTime
// so endTime[i]-startTime[i] must be all summation of gaps
// then minus it from eventTime
// return the diff
// wrong after a few times
// If an event can be "squeezed" into the idle time around it (i.e., it's short
// enough), you may completely skip its time from the calculation.

// Approach:
/*## ✅ Code Logic Breakdown

### Part 1: Flag compressible events using two sweeps

```cpp
vector<bool> q(n);
for (int i = 0, t1 = 0, t2 = 0; i < n; i++) {
```

#### 🟡 Left-to-right sweep:

```cpp
if (endTime[i] - startTime[i] <= t1)
    q[i] = true;
t1 = max(t1, startTime[i] - (i == 0 ? 0 : endTime[i - 1]));
```

* `t1` tracks the **free time between events** seen **so far**.
* If the duration of current event fits in the previous free gap → mark `q[i] =
true`.

#### 🔵 Right-to-left sweep:

```cpp
if (endTime[n - i - 1] - startTime[n - i - 1] <= t2)
    q[n - i - 1] = true;
t2 = max(t2, (i == 0 ? eventTime : startTime[n - i]) - endTime[n - i - 1]);
```

* Same logic, but reversed direction.
* Allows checking if event fits in the **next** gap too.

So `q[i] == true` means this event is small enough to be hidden inside the free
gap either before or after it.

---

### Part 2: Find the longest free time

```cpp
int left = i == 0 ? 0 : endTime[i - 1];
int right = i == n - 1 ? eventTime : startTime[i + 1];
```

You're now examining **gap around event i**: `[endTime[i - 1], startTime[i +
1]]`

Two cases:

#### 1. If `q[i]` is true:

→ This event can be ignored.

```cpp
res = max(res, right - left);
```

#### 2. Else:

→ This event *eats up* some of the free time.

```cpp
res = max(res, right - left - (endTime[i] - startTime[i]));
```

---

## 💡 Final Insight:

The trick is:

* Use **bi-directional sweeps** to find events that are “short enough” to hide.
* Then, **when evaluating max free time**, skip those events.
 */
class Solution {
public:
  int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
    int n = startTime.size();
    vector<bool> q(n);
    for (int i = 0, t1 = 0, t2 = 0; i < n; i++) {
      if (endTime[i] - startTime[i] <= t1) {
        q[i] = true;
      }
      t1 = max(t1, startTime[i] - (i == 0 ? 0 : endTime[i - 1]));

      if (endTime[n - i - 1] - startTime[n - i - 1] <= t2) {
        q[n - i - 1] = true;
      }
      t2 =
          max(t2, (i == 0 ? eventTime : startTime[n - i]) - endTime[n - i - 1]);
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
      int left = i == 0 ? 0 : endTime[i - 1];
      int right = i == n - 1 ? eventTime : startTime[i + 1];
      if (q[i]) {
        res = max(res, right - left);
      } else {
        res = max(res, right - left - (endTime[i] - startTime[i]));
      }
    }
    return res;
  }
};
// sub:
// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/submissions/1692927953/?envType=daily-question&envId=2025-07-10
// sol:
// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/solutions/6942151/3440-reschedule-meetings-for-maximum-fre-r0s2/
