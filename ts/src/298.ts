//3330. Find the Original Typed String I
function possibleStringCount(word: string): number {
  let n = word.length,
    ans = 1;
  for (let i = 1; i < n; ++i) {
    if (word[i - 1] === word[i]) {
      ++ans;
    }
  }
  return ans;
}
//sub: https://leetcode.com/problems/find-the-original-typed-string-i/submissions/1682793994/
//sol: https://leetcode.com/problems/find-the-original-typed-string-i/solutions/6907639/3330-find-the-original-typed-string-i-by-lyxp/
