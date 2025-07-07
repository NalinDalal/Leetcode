/* 1353. Maximum Number of Events That Can Be Attended

You are given an array of events where events[i] = [startDayi, endDayi]. Every
event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. You
can only attend one event at any time d.

Return the maximum number of events you can attend.



Example 1:


Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.
Example 2:

Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4


Constraints:

1 <= events.length <= 105
events[i].length == 2
1 <= startDayi <= endDayi <= 105

Hint 1
Sort the events by the start time and in case of tie by the end time in
ascending order. Hint 2 Loop over the sorted events. Attend as much as you can
and keep the last day occupied. When you try to attend new event keep in mind
the first day you can attend a new event in.
*/

// Solution
/* 1. Sort the events by start day. If tie, sort by end day.

2. Use a min-heap (priority queue) to always attend the event that ends the
soonest.

3. Loop day-by-day from the earliest start to the latest end:

- Add events that start today to the heap.

- Remove events from heap that already ended.

- If heap not empty: attend the event with earliest end day (pop it).


*/

#include <algorithm>
#include <queue>
#include <vector>

class Solution {
public:
  int maxEvents(std::vector<std::vector<int>>& events) {
    // Sort events by start day, then end day
    std::sort(events.begin(), events.end());

    // Min-heap to store end times of active events
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    int day = 1, i = 0, n = events.size(), count = 0;

    // Loop from day 1 to max end day
    int lastDay = 0;
    for (auto& e : events)
      lastDay = std::max(lastDay, e[1]);

    for (day = 1; day <= lastDay; ++day) {
      // Add all events starting today
      while (i < n && events[i][0] == day)
        minHeap.push(events[i++][1]);

      // Remove expired events
      while (!minHeap.empty() && minHeap.top() < day)
        minHeap.pop();

      // Attend one event with earliest end
      if (!minHeap.empty()) {
        minHeap.pop();
        count++;
      }
    }

    return count;
  }
};

// sub:
// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/submissions/1689670013/
// sol:
// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/solutions/6931541/1353-maximum-number-of-events-that-can-b-bcl7/
