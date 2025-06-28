//2099. Find Subsequence of Length K With the Largest Sum
function maxSubsequence(nums: number[], k: number): number[] {
  // Step 1: Pair each number with its index
  const withIndex: [number, number][] = nums.map((num, i) => [num, i]);

  // Step 2: Sort by value descending
  withIndex.sort((a, b) => b[0] - a[0]);

  // Step 3: Pick top k and sort by original index
  const topK = withIndex.slice(0, k).sort((a, b) => a[1] - b[1]);

  // Step 4: Extract values
  return topK.map(([value]) => value);
}
//sub: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/submissions/1679315642/?envType=daily-question&envId=2025-06-28
//sol: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/solutions/6895734/2099-find-subsequence-of-length-k-with-t-83bh/
