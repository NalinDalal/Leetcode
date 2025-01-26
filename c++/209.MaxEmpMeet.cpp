/* https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/description/?envType=daily-question&envId=2025-01-26
2127. Maximum Employees to Be Invited to a Meeting
Hard
Topics
Companies
Hint
A company is organizing a meeting and has a list of n employees, waiting to be
invited. They have arranged for a large circular table, capable of seating any
number of employees.

The employees are numbered from 0 to n - 1. Each employee has a favorite person
and they will attend the meeting only if they can sit next to their favorite
person at the table. The favorite person of an employee is not themself.

Given a 0-indexed integer array favorite, where favorite[i] denotes the favorite
person of the ith employee, return the maximum number of employees that can be
invited to the meeting.



Example 1:


Input: favorite = [2,2,1,2]
Output: 3
Explanation:
The above figure shows how the company can invite employees 0, 1, and 2, and
seat them at the round table. All employees cannot be invited because employee 2
cannot sit beside employees 0, 1, and 3, simultaneously. Note that the company
can also invite employees 1, 2, and 3, and give them their desired seats. The
maximum number of employees that can be invited to the meeting is 3. Example 2:

Input: favorite = [1,2,0]
Output: 3
Explanation:
Each employee is the favorite person of at least one other employee, and the
only way the company can invite them is if they invite every employee. The
seating arrangement will be the same as that in the figure given in example 1:
- Employee 0 will sit between employees 2 and 1.
- Employee 1 will sit between employees 0 and 2.
- Employee 2 will sit between employees 1 and 0.
The maximum number of employees that can be invited to the meeting is 3.
Example 3:


Input: favorite = [3,0,1,4,1]
Output: 4
Explanation:
The above figure shows how the company will invite employees 0, 1, 3, and 4, and
seat them at the round table. Employee 2 cannot be invited because the two spots
next to their favorite employee 1 are taken. So the company leaves them out of
the meeting. The maximum number of employees that can be invited to the meeting
is 4.


Constraints:

n == favorite.length
2 <= n <= 105
0 <= favorite[i] <= n - 1
favorite[i] != i

Hint 1
From the given array favorite, create a graph where for every index i, there is
a directed edge from favorite[i] to i. The graph will be a combination of cycles
and chains of acyclic edges. Now, what are the ways in which we can choose
employees to sit at the table? Hint 2 The first way by which we can choose
employees is by selecting a cycle of the graph. It can be proven that in this
case, the employees that do not lie in the cycle can never be seated at the
table (unless the cycle has a length of 2). Hint 3 The second way is by
combining acyclic chains. At most two chains can be combined by a cycle of
length 2, where each chain ends on one of the employees in the cycle.
*/
/* Identify chains of employees, where each employee is connected by their
favorite. Detect cycles within the graph, where employees form loops of favorite
relationships. Maximize the number of employees that can be invited by combining
the largest chain(s) with the largest cycle(s).*/

/*Approach
 1. Graph Preparation:
Build an inDegree array to count how many people favor each person.
Identify nodes with inDegree == 0 and add them to a queue for processing.
2. Topological Sorting (Removing Chains):
Process nodes with zero incoming edges and propagate chain lengths to their
favorite person. This helps determine the longest chain leading to each node.
3. Cycle Detection and Counting:
Traverse remaining nodes to detect cycles.
If a cycle of length 2 is found (mutual pair), add the longest chains leading to
both nodes. Track the largest cycle found for cases where no mutual pairs exist.
4. Final Calculation:
Return the maximum between the largest cycle size and the total sum of extended
mutual pairs.

    */
class Solution {
public:
  int maximumInvitations(vector<int>& fav) {
    int n = fav.size();
    vector<int> inDeg(n, 0), depth(n, 1);
    for (int i{0}; i < n; ++i)
      inDeg[fav[i]]++;
    queue<int> q;
    for (int i{0}; i < n; ++i)
      if (inDeg[i] == 0)
        q.push(i);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      int nxt = fav[cur];
      depth[nxt] = max(depth[nxt], depth[cur] + 1);
      if (--inDeg[nxt] == 0)
        q.push(nxt);
    }
    int maxCycle{0}, twoCycleSum{0};
    for (int i{0}; i < n; ++i) {
      if (inDeg[i] == 0)
        continue;
      int len{0}, cur = i;
      while (inDeg[cur] != 0) {
        inDeg[cur] = 0;
        len++;
        cur = fav[cur];
      }
      if (len == 2) {
        twoCycleSum += depth[i] + depth[fav[i]];
      } else {
        maxCycle = max(maxCycle, len);
      }
    }
    return max(maxCycle, twoCycleSum);
  }
};
static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
// 89.75%
//  Time: O(n)
//  Space: O(n)
//  sub:
//  https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/submissions/1521329388/?envType=daily-question&envId=2025-01-26
//  sol:
//  https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/solutions/6332665/2127-maximum-employees-to-be-invited-to-p2d1h/
