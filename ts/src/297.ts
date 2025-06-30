//594. Longest Harmonious Subsequence
function findLHS(nums: number[]): number {
  const freq = new Map<number, number>();
  let maxLength = 0;

  for (const num of nums) {
    freq.set(num, (freq.get(num) || 0) + 1);
  }

  for (const [num, count] of freq.entries()) {
    if (freq.has(num + 1)) {
      maxLength = Math.max(maxLength, count + freq.get(num + 1)!);
    }
  }

  return maxLength;
}
//sub: https://leetcode.com/problems/longest-harmonious-subsequence/submissions/1681493047/
//sol: https://leetcode.com/problems/longest-harmonious-subsequence/solutions/6903011/594-longest-harmonious-subsequence/
