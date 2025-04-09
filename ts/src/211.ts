//3375. Minimum Operations to Make Array Values Equal to K

function minOperations(nums: number[], k: number): number {
  const st = new Set<number>();
  for (const x of nums) {
    if (x < k) {
      return -1;
    } else if (x > k) {
      st.add(x);
    }
  }
  return st.size;
}
//sub: https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/submissions/1601206115/?envType=daily-question&envId=2025-04-09
