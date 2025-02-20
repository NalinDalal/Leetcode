//746. Min Cost Climbing Stairs
function minCostClimbingStairs(cost: number[]): number {
  let n = cost.length;
  for (let i = 2; i < n; i++) cost[i] += Math.min(cost[i - 1], cost[i - 2]);
  return Math.min(cost[n - 1], cost[n - 2]);
}
//sub: https://leetcode.com/problems/min-cost-climbing-stairs/submissions/1549145976/
//sol: https://leetcode.com/problems/min-cost-climbing-stairs/solutions/6444457/746-min-cost-climbing-stairs-by-nalindal-swwf/
