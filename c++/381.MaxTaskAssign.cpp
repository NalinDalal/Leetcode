/* 2071. Maximum Number of Tasks You Can Assign
You have n tasks and m workers. Each task has a strength requirement stored in a
0-indexed integer array tasks, with the ith task requiring tasks[i] strength to
complete. The strength of each worker is stored in a 0-indexed integer array
workers, with the jth worker having workers[j] strength. Each worker can only be
assigned to a single task and must have a strength greater than or equal to the
task's strength requirement (i.e., workers[j] >= tasks[i]).

Additionally, you have pills magical pills that will increase a worker's
strength by strength. You can decide which workers receive the magical pills,
however, you may only give each worker at most one magical pill.

Given the 0-indexed integer arrays tasks and workers and the integers pills and
strength, return the maximum number of tasks that can be completed.



Example 1:

Input: tasks = [3,2,1], workers = [0,3,3], pills = 1, strength = 1
Output: 3
Explanation:
We can assign the magical pill and tasks as follows:
- Give the magical pill to worker 0.
- Assign worker 0 to task 2 (0 + 1 >= 1)
- Assign worker 1 to task 1 (3 >= 2)
- Assign worker 2 to task 0 (3 >= 3)
Example 2:

Input: tasks = [5,4], workers = [0,0,0], pills = 1, strength = 5
Output: 1
Explanation:
We can assign the magical pill and tasks as follows:
- Give the magical pill to worker 0.
- Assign worker 0 to task 0 (0 + 5 >= 5)
Example 3:

Input: tasks = [10,15,30], workers = [0,10,10,10,10], pills = 3, strength = 10
Output: 2
Explanation:
We can assign the magical pills and tasks as follows:
- Give the magical pill to worker 0 and worker 1.
- Assign worker 0 to task 0 (0 + 10 >= 10)
- Assign worker 1 to task 1 (10 + 10 >= 15)
The last pill is not given because it will not make any worker strong enough for
the last task.


Constraints:

n == tasks.length
m == workers.length
1 <= n, m <= 5 * 104
0 <= pills <= m
0 <= tasks[i], workers[j], strength <= 109

Hint 1: Is it possible to assign the first k smallest tasks to the workers?
Hint 2: How can you efficiently try every k?
*/

// ith task->task[i] strength
// jth worker->workers[j] strength
// workers[j]>=tasks[i]
// pill->workers[j]+=strength
// return max no of task that can be completed

// 1. find all task where worker[j]>tasks[i]-> inc count
// 2. check now the remaining
// 3. apply the spcl power accordingly
// 4. return max count
/* 1. **Binary search** on the number of tasks (`k`) to see if it's possible to
assign `k` tasks.

2. For each candidate `k`, try to assign the `k` **hardest tasks** to the `k`
**strongest workers**, using pills wisely.

3. Use a greedy + multiset (or `deque`) to manage available workers and match
tasks.


    */
#include <algorithm>
#include <vector>
using std::vector;
class Solution {
public:
  bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills,
                 int strength) {
    multiset<int> available(workers.end() - k,
                            workers.end()); // strongest k workers
    int i = k - 1;                          // start from the hardest task
    int pillsLeft = pills;

    for (int j = i; j >= 0; --j) {
      int task = tasks[j];

      auto it = prev(available.end()); // strongest worker
      if (*it >= task) {
        available.erase(it);
      } else {
        if (pillsLeft == 0)
          return false;
        auto weak = available.lower_bound(task - strength);
        if (weak == available.end())
          return false;
        available.erase(weak);
        pillsLeft--;
      }
    }

    return true;
  }

  int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills,
                    int strength) {
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());

    int left = 0, right = min(tasks.size(), workers.size()), ans = 0;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (canAssign(mid, tasks, workers, pills, strength)) {
        ans = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return ans;
  }
};
// sub:
// https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/submissions/1622413442/?envType=daily-question&envId=2025-05-01
/*Time:
    - Sorting: O(n log n + m log m)
    - Binary search: O(log min(n, m))
    - For each check: O(k log k) due to multiset operations

Space: O(1)
*/
