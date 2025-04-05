//1863. Sum of All Subset XOR Totals
function subsetXORSum(nums: number[]): number {
  function dfs(index: number, currentXor: number): number {
    if (index === nums.length) return currentXor;
    // include nums[index]
    const withCurrent = dfs(index + 1, currentXor ^ nums[index]);
    // exclude nums[index]
    const withoutCurrent = dfs(index + 1, currentXor);
    return withCurrent + withoutCurrent;
  }

  return dfs(0, 0);
}
//sub: https://leetcode.com/problems/sum-of-all-subset-xor-totals/submissions/1597153429/?envType=daily-question&envId=2025-04-05
//sol: https://leetcode.com/problems/sum-of-all-subset-xor-totals/solutions/6617248/1863-sum-of-all-subset-xor-totals-by-nal-jlgc/
