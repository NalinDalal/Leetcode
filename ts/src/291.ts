//2200. Find All K-Distant Indices in an Array
function findKDistantIndices(nums: number[], key: number, k: number): number[] {
  const result = new Set<number>();

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] === key) {
      const start = Math.max(0, i - k);
      const end = Math.min(nums.length - 1, i + k);
      for (let j = start; j <= end; j++) {
        result.add(j);
      }
    }
  }

  return Array.from(result).sort((a, b) => a - b);
}
//sub: https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/submissions/1674985987/
//sol: https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/solutions/6880814/2200-find-all-k-distant-indices-in-an-ar-7gmf/
