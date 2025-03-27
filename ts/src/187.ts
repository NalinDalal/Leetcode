//2780. Minimum Index of a Valid Split
function minimumIndex(nums: number[]): number {
  const n = nums.length;

  // Step 1: Find the dominant element using Boyer-Moore Voting Algorithm
  let candidate = -1,
    count = 0;
  for (const num of nums) {
    if (count === 0) candidate = num;
    count += num === candidate ? 1 : -1;
  }

  // Step 2: Validate if candidate is actually dominant
  let totalCount = nums.filter((num) => num === candidate).length;
  if (totalCount * 2 <= n) return -1; // No dominant element

  // Step 3: Find the minimum index where both halves share the dominant element
  let prefixCount = 0;
  for (let i = 0; i < n - 1; i++) {
    if (nums[i] === candidate) prefixCount++;
    let suffixCount = totalCount - prefixCount;

    if (prefixCount * 2 > i + 1 && suffixCount * 2 > n - i - 1) {
      return i;
    }
  }

  return -1;
}
//sub: https://leetcode.com/problems/minimum-index-of-a-valid-split/submissions/1587726482/?envType=daily-question&envId=2025-03-27
//sol: https://leetcode.com/problems/minimum-index-of-a-valid-split/solutions/6584682/2780-minimum-index-of-a-valid-split-by-n-01rt/
