//2364. Count Number of Bad Pairs
function countBadPairs(nums: number[]): number {
  let n = nums.length;
  let totalPairs = (n * (n - 1)) / 2;
  const freq = new Map<number, number>();

  let goodPairs = 0;

  for (let i = 0; i < n; i++) {
    let diff = nums[i] - i;
    if (freq.has(diff)) {
      goodPairs += freq.get(diff); // Count how many times this diff has appeared before
    }
    freq.set(diff, (freq.get(diff) || 0) + 1); // Increment count in map
  }

  return totalPairs - goodPairs;
}
//sub: https://leetcode.com/problems/count-number-of-bad-pairs/submissions/1536861165/
//sol: https://leetcode.com/problems/count-number-of-bad-pairs/solutions/6397607/2364-count-number-of-bad-pairs-by-nalind-irj9/
