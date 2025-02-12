//14. Longest Common Prefix
function longestCommonPrefix(strs: string[]): string {
  let prefix: string = "";
  if (strs.length == 0) return prefix;

  for (let j = 0; j < strs[0].length; j++) {
    let current_char: string = strs[0][j];
    for (let i = 0; i < strs.length; i++) {
      if (j >= strs[i].length || strs[i][j] != current_char) {
        return prefix;
      }
    }
    prefix += current_char;
  }
  return prefix;
}
//sub: https://leetcode.com/problems/longest-common-prefix/submissions/1540258860/
//sol: https://leetcode.com/problems/longest-common-prefix/solutions/6411939/14-longest-common-prefix-by-nalindalal20-u9eu/
