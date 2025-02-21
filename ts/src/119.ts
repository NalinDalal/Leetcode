//416. Partition Equal Subset Sum
function canPartition(nums: number[]): boolean {
  let totalSum: number = nums.reduce((sum, num) => sum + num, 0);

  // If total sum is odd, can't partition into two equal subsets
  if (totalSum % 2 !== 0) {
    return false;
  }

  let target: number = totalSum / 2;
  let dp: boolean[] = new Array(target + 1).fill(false);
  dp[0] = true; // Base case: Subset sum of 0 is always possible (empty subset)

  for (let num of nums) {
    // Traverse backwards to avoid overwriting dp values in current iteration
    for (let j = target; j >= num; j--) {
      dp[j] = dp[j] || dp[j - num];
    }
  }

  return dp[target];
}
//sub: https://leetcode.com/problems/partition-equal-subset-sum/submissions/1550410586/
//sol: https://leetcode.com/problems/partition-equal-subset-sum/solutions/6449661/416-partition-equal-subset-sum-by-nalind-p2tv/
