//3068. Find the Maximum Sum of Node Values
function maximumValueSum(nums: number[], k: number, edges: number[][]): number {
  const n = nums.length;
  const memo: number[][] = Array.from({ length: n }, () => Array(2).fill(-1));
  const INF = 1e9;

  function maxSumOfNodes(index: number, isEven: number): number {
    if (index === n) return isEven ? 0 : -INF;
    if (memo[index][isEven] !== -1) return memo[index][isEven];

    const noXor = nums[index] + maxSumOfNodes(index + 1, isEven);
    const xorDone = (nums[index] ^ k) + maxSumOfNodes(index + 1, 1 - isEven);

    memo[index][isEven] = Math.max(noXor, xorDone);
    return memo[index][isEven];
  }

  return maxSumOfNodes(0, 1);
}

//sub: https://leetcode.com/problems/find-the-maximum-sum-of-node-values/submissions/1641977459/?envType=daily-question&envId=2025-05-23
//sol: https://leetcode.com/problems/find-the-maximum-sum-of-node-values/solutions/6772344/3068-find-the-maximum-sum-of-node-values-34kr/
