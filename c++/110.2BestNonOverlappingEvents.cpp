/* POTD- 08/12/2024
2054. Two Best Non-Overlapping Events

You are given a 0-indexed 2D integer array of events where events[i] =
[startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at
endTimei, and if you attend this event, you will receive a value of valuei. You
can choose at most two non-overlapping events to attend such that the sum of
their values is maximized.

Return this maximum sum.

Note that the start time and end time is inclusive: that is, you cannot attend
two events where one of them starts and the other ends at the same time. More
specifically, if you attend an event with end time t, the next event must start
at or after t + 1.


Example 1:
Input: events = [[1,3,2],[4,5,2],[2,4,3]]
Output: 4
Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.

Example 2:
Input: events = [[1,3,2],[4,5,2],[1,5,5]]
Output: 5
Explanation: Choose event 2 for a sum of 5.

Example 3:
Input: events = [[1,5,3],[1,5,1],[6,6,5]]
Output: 8
Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.


Constraints:

2 <= events.length <= 10^5
events[i].length == 3
1 <= startTimei <= endTimei <= 10^9
1 <= valuei <= 10^6*/

/* okay so event i is [startTimei, endTimei, valuei]
so we need to find the max sum of the values of the events that don't overlap

so we need to sort the events by startTimei
then we need to iterate through the events and find the max sum of the values of
the events that don't overlap

we can do this by using a stack
push the startTimei of the first event onto the stack
while the stack is not empty{
    pop the top event off the stack
    if (the top event ends before the current event starts ){
        add the value of the top event to the max sum
        push the startTimei of the current event onto the stack}
    else{
        add the value of the top event to the max sum
        }
    }*/

// greedy approach:
/* Sort the events based on the end time to efficiently find the maximum sum of
non-overlapping events. Track the maximum value of an event that ends before the
current event starts using a variable. */

// Approach:
/*1. Sorting the Events:
First, we will sort the events by their end times. This will help us to easily
check for non-overlapping events while considering events sequentially.

2. Dynamic Programming Approach:
We can use a dynamic programming array to track the best possible sum of values
up to each event. Specifically, we maintain a dp array where dp[i] represents
the maximum sum we can achieve by attending at most one event from the first i
events (sorted by end time).

3. Binary Search for Non-Overlapping Event:
After sorting the events, for each event i, we want to find the most recent
event j such that event j ends before event i starts. This can be efficiently
done using binary search, where we search for the largest endTime[j] <
startTime[i].

4. Combining the Results: For each event i, we compute the maximum sum by
either:
    1. Taking only the current event i.
    2. Combining it with a previously non-overlapping event j (using the dp
array for the best possible sum up to j).*/

// this is also lame

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/* class Solution {
public:
  int maxTwoEvents(vector<vector<int>> &events) {
    int best_previous = -1e9;
    int best = -1e9;

    for (int v : events) {
      int nv = std::max(best_previous, v);
      best_previous = std::max(best_previous, nv);
      best = std::max(best, best_previous + v);
    }

    return best;
  }
};
*/

// 100% solution
/* Approach:
1. Build up an array `time` of size `2*n`
2. Use a loop to proceed from `i=1` to `n-1`: `s=events[i][0], e=events[i][1],
v=events[i][2]`. let `time[2*i]={s, 0, v}; time[2*i+1]={e, 1, v}`
3. sort `time`
4. Traverse the sorted `time`
5. For each iteration, say `[t, isEnd, v]`, if `isEnd` which means it can take
`v` for consideration & update `maxV=max(maxV, v)` otherwise update
`ans=max(ans, maxV+v)
6. 2nd C++ is just packing of info tuple `(time, isEnd, value)` into an
`uint64_t` which speeds up probably twice of the speed.
7. A recursive DP(memo) with binary search is done which is slow as expected. */

class Solution {
public:
  //    using info=tuple<int, bool, int>;
  static int maxTwoEvents(vector<vector<int>> &events) {
    const int n = events.size();
    vector<uint64_t> time(n * 2);
    for (int i = 0; i < n; i++) {
      int s = events[i][0], e = events[i][1], v = events[i][2];
      time[2 * i] = ((uint64_t)s << 21) + v;                 // packing
      time[2 * i + 1] = ((uint64_t)e << 21) + (1 << 20) + v; // packing
    }
    sort(time.begin(), time.end());
    int ans = 0, maxV = 0, n2 = n * 2;
    for (auto info : time) {
      bool isEnd = (info >> 20) & 1;  // extract isEnd from info
      int v = info & ((1 << 20) - 1); // extract v from info
      if (isEnd)
        maxV = max(maxV, v);
      else
        ans = max(ans, maxV + v);
    }
    return ans;
  }
};

auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 'c';
}();

// Time complexity:O(nlogn)

// Space complexity:O(n)
int main() {
  Solution solution;

  // Test case 1
  vector<vector<int>> events1 = {{1, 3, 3}, {3, 6, 4}, {5, 7, 2}, {6, 8, 4}};
  cout << "Max sum of two non-overlapping events: "
       << solution.maxTwoEvents(events1) << endl;

  // Test case 2
  vector<vector<int>> events2 = {{1, 3, 5}, {3, 5, 1}, {4, 7, 2}};
  cout << "Max sum of two non-overlapping events: "
       << solution.maxTwoEvents(events2) << endl;

  return 0;
}
