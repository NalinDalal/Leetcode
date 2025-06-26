//2311. Longest Binary Subsequence Less Than or Equal to K
function longestSubsequence(s: string, k: number): number {
  let sm = 0;
  let cnt = 0;
  let bits = Math.log2(k) + 1;
  for (let i = 0; i < s.length; i++) {
    const ch = s[s.length - 1 - i];
    if (ch === "1") {
      if (i < bits && sm + (1 << i) <= k) {
        sm += 1 << i;
        cnt++;
      }
    } else {
      cnt++;
    }
  }
  return cnt;
}
//sub: https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/submissions/1676941496/?envType=daily-question&envId=2025-06-26
//sol: https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/solutions/6887180/2311-longest-binary-subsequence-less-tha-ornk/
