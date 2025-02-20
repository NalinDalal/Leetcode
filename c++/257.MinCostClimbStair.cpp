/* 746. Min Cost Climbing Stairs
You are given an integer array cost where cost[i] is the cost of ith step on a
staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.



Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.


Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999
*/

#include <vector>

using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    // given an array of integers cosr, return min cost to reach top of
    // stairs
    int n = cost.size();

    // start from index 0 or 1
    // can climb 1 or 2 steps
    // check what is min cost, if it's at 1 or 2 steps
    // then add it to mincost
    // if you reach top of stairs, then return minCost
    // like 10,15,20-> use index 1, pay 15 and can climb other 2 steps and
    // reach top of stairs
    for (int i = 2; i < n; i++)
      cost[i] += min(cost[i - 1], cost[i - 2]);

    return min(cost[n - 1], cost[n - 2]);
  }
};
// Time: O(n)
// Space:O(1)
// sub:
// https://leetcode.com/problems/min-cost-climbing-stairs/submissions/1549142668/
// sol:
// https://leetcode.com/problems/min-cost-climbing-stairs/solutions/6444457/746-min-cost-climbing-stairs-by-nalindal-swwf/
