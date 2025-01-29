//139. Word Break
function wordBreak(s: string, wordDict: string[]): boolean {
  const wordSet = new Set(wordDict);
  const dp: boolean[] = new Array(s.length + 1).fill(false);
  dp[s.length] = true; // Base case: an empty suffix is always valid

  for (let i = s.length - 1; i >= 0; --i) {
    for (const word of wordSet) {
      if (
        i + word.length <= s.length &&
        s.substring(i, i + word.length) === word
      ) {
        dp[i] = dp[i + word.length];
        if (dp[i]) {
          break;
        }
      }
    }
  }

  return dp[0];
}
//sub: https://leetcode.com/problems/word-break/submissions/1524138276/
//sol: https://leetcode.com/problems/word-break/solutions/6343401/139-word-break75-by-nalindalal2004-pqtf/
