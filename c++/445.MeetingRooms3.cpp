/*2402. Meeting Rooms III
You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi]
means that a meeting will be held during the half-closed time interval [starti,
endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room
becomes free. The delayed meeting should have the same duration as the original
meeting. When a room becomes unused, meetings that have an earlier original
start time should be given the room. Return the number of the room that held the
most meetings. If there are multiple rooms, return the room with the lowest
number.

A half-closed interval [a, b) is the interval between a and b including a and
not including b.



Example 1:

Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0
Explanation:
- At time 0, both rooms are not being used. The first meeting starts in room 0.
- At time 1, only room 1 is not being used. The second meeting starts in room 1.
- At time 2, both rooms are being used. The third meeting is delayed.
- At time 3, both rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 1 finishes. The third meeting starts in room 1
for the time period [5,10).
- At time 10, the meetings in both rooms finish. The fourth meeting starts in
room 0 for the time period [10,11). Both rooms 0 and 1 held 2 meetings, so we
return 0. Example 2:

Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
Output: 1
Explanation:
- At time 1, all three rooms are not being used. The first meeting starts in
room 0.
- At time 2, rooms 1 and 2 are not being used. The second meeting starts in
room 1.
- At time 3, only room 2 is not being used. The third meeting starts in room 2.
- At time 4, all three rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2
for the time period [5,10).
- At time 6, all three rooms are being used. The fifth meeting is delayed.
- At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in
room 1 for the time period [10,12). Room 0 held 1 meeting while rooms 1 and 2
each held 2 meetings, so we return 1.


Constraints:

1 <= n <= 100
1 <= meetings.length <= 105
meetings[i].length == 2
0 <= starti < endi <= 5 * 105
All the values of starti are unique.

Hint 1
Sort meetings based on start times.
Hint 2
Use two min heaps, the first one keeps track of the numbers of all the rooms
that are free. The second heap keeps track of the end times of all the meetings
that are happening and the room that they are in.

Hint 3
Keep track of the number of times each room is used in an array.

Hint 4
With each meeting, check if there are any free rooms. If there are, then use the
room with the smallest number. Otherwise, assign the meeting to the room whose
meeting will end the soonest.
*/

/* 1. Initialize two arrays:

room_availability_time[n] – when each room will be free.

meeting_count[n] – number of meetings each room has handled.

2. Sort meetings by start time.

3. For each meeting:

- Check each room from 0 to n-1.

- If any room is available (i.e., its availability time ≤ meeting start), assign
the meeting there:

    - Update room_availability_time[room] = meeting.end

    - Increment meeting_count[room]

    - Break (stop checking more rooms)

- If no room is available:

    - Find the room that will be free the earliest.

    - Delay the meeting to start when that room is free.

    - Update room_availability_time[room] += duration

    - Increment meeting_count[room]

4. Return the room with the highest meeting_count (and lowest index if tied).
*/

#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
  int mostBooked(int n, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end());
    vector<long long> availability(n, 0);
    vector<int> count(n, 0);

    for (auto& m : meetings) {
      long long start = m[0], end = m[1], duration = end - start;
      bool assigned = false;

      for (int i = 0; i < n; ++i) {
        if (availability[i] <= start) {
          availability[i] = end;
          count[i]++;
          assigned = true;
          break;
        }
      }

      if (!assigned) {
        int earliest = 0;
        for (int i = 1; i < n; ++i)
          if (availability[i] < availability[earliest])
            earliest = i;

        availability[earliest] += duration;
        count[earliest]++;
      }
    }

    int maxRoom = 0;
    for (int i = 1; i < n; ++i)
      if (count[i] > count[maxRoom])
        maxRoom = i;

    return maxRoom;
  }
};

// sub:
// https://leetcode.com/problems/meeting-rooms-iii/submissions/1694451763/?envType=daily-question&envId=2025-07-11
// sol:
// https://leetcode.com/problems/meeting-rooms-iii/solutions/6947194/2402-meeting-rooms-iii-by-nalindalal2004-1sc4/
