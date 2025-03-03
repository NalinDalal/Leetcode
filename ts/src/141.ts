//2161. Partition Array According to Given Pivot
function pivotArray(nums: number[], pivot: number): number[] {
  let less: number[] = [];
  let equal: number[] = [];
  let greater: number[] = [];

  for (let num of nums) {
    if (num < pivot) less.push(num);
    else if (num === pivot) equal.push(num);
    else greater.push(num);
  }

  return [...less, ...equal, ...greater];
}
//sub: https://leetcode.com/problems/partition-array-according-to-given-pivot/submissions/1561013549/?envType=daily-question&envId=2025-03-03
//sol: https://leetcode.com/problems/partition-array-according-to-given-pivot/solutions/6488526/2161-partition-array-according-to-given-em6zr/
