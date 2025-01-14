//3404. Count Special Subsequences

function numberOfSubsequences(nums: number[]): number {
  const mp: Map<number, number> = new Map();
  let ans = 0;

  // Iterate over index `r`, starting from 4
  for (let r = 4; r < nums.length; r++) {
    // Iterate over the first pair (p, q)
    for (let p = 0, q = r - 2; p < q - 1; p++) {
      const ratio = nums[p] / nums[q];
      mp.set(ratio, (mp.get(ratio) || 0) + 1);
    }

    // Iterate over index `s`, starting from r + 2
    for (let s = r + 2; s < nums.length; s++) {
      const ratio = nums[s] / nums[r];
      ans += mp.get(ratio) || 0; // If ratio exists, add to answer
    }
  }

  return ans;
}

//81.82%
//sub: https://leetcode.com/problems/count-special-subsequences/submissions/1508084491/
//sol: https://leetcode.com/problems/count-special-subsequences/solutions/6277890/3404-count-special-subsequences7230-by-n-ctq7/
