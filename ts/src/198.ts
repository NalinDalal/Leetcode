//392. Is Subsequence
function isSubsequence(s: string, t: string): boolean {
  let i = 0,
    j = 0;

  while (i < s.length && j < t.length) {
    if (s[i] == t[j]) i++;
    j++;
  }

  return i == s.length;
}
//sub: https://leetcode.com/problems/is-subsequence/submissions/1594058045/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/is-subsequence/solutions/6606224/392-is-subsequence-by-nalindalal2004-egtt/
