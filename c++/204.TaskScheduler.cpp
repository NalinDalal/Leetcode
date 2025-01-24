/* https://leetcode.com/problems/task-scheduler/description/
621. Task Scheduler

You are given an array of CPU tasks, each labeled with a letter from A to Z, and
a number n. Each CPU interval can be idle or allow the completion of one task.
Tasks can be completed in any order, but there's a constraint: there has to be a
gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
After completing task A, you must wait two intervals before doing A again. The
same applies to task B. In the 3rd interval, neither A nor B can be done, so you
idle. By the 4th interval, you can do A again as 2 intervals have passed.

Example 2:
Input: tasks = ["A","C","A","B","D","B"], n = 1
Output: 6
Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.With a cooling
interval of 1, you can repeat a task after just one other task.

Example 3:
Input: tasks = ["A","A","A", "B","B","B"], n = 3
Output: 10
Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle ->
idle -> A -> B. There are only two types of tasks, A and B, which need to be
separated by 3 intervals. This leads to idling twice between repetitions of
these tasks.



Constraints:
1 <= tasks.length <= 104
tasks[i] is an uppercase English letter.
0 <= n <= 100
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {

    // same task must have a gap of atleast n intervals
    // if no gap is present make gap then of n interval
    // change places in array itself for same task
    // For every cycle, find the most frequent letter that can be placed in this
    // cycle. After placing, decrease the frequency of that letter by one. Use
    // Priority Queue. put all task in PQ with frequency 1 then for every cycle
    // in PQ, find the empty slots with least freq, put them their increase
    // minInterval by 1
    // Calculate the number of intervals needed based on the task with the
    // maximum frequency.
    // Return the total number of intervals required.
    int freq[26] = {0};
    for (char task : tasks) {
      freq[task - 'A']++;
    }
    sort(begin(freq), end(freq));
    int chunk = freq[25] - 1;
    int idel = chunk * n;

    for (int i = 24; i >= 0; i--) {
      idel -= min(chunk, freq[i]);
    }

    return idel < 0 ? tasks.size() : tasks.size() + idel;
  }
};

// Time: O(26 log 26)=O(1)
// Space: O(26)=O(1)
int main() {
  Solution s;
  vector<char> tasks1 = {"A", "A", "A", "B", "B", "B"};
  int n1 = 2;
  cout << s.leastInterval(tasks1, n1) << endl;

  cout << endl;
  vector<char> tasks2 = {"A", "C", "A", "B", "D", "B"};
  int n2 = 1;
  cout << s.leastInterval(tasks2, n2) << endl;
  cout << endl;
  vector<char> tasks3 = {"A", "A", "A", "B", "B", "B"};
  int n3 = 3;
  cout << s.leastInterval(tasks3, n3) << endl;

  return 0;
}

// sub: https://leetcode.com/problems/task-scheduler/submissions/1518684096/
// sol:
// https://leetcode.com/problems/task-scheduler/solutions/6322678/621-task-scheduler100-by-nalindalal2004-j69n/
// 100%
