//2929. Distribute Candies Among Children II
function distributeCandies(n: number, limit: number): number {
  let total = 0;
  for (let a = 0; a <= Math.min(n, limit); a++) {
    const remaining = n - a;
    const minB = Math.max(0, remaining - limit);
    const maxB = Math.min(limit, remaining);
    total += Math.max(0, maxB - minB + 1);
  }
  return total;
}
//sub: https://leetcode.com/problems/distribute-candies-among-children-ii/submissions/1650473400/?envType=daily-question&envId=2025-06-01
