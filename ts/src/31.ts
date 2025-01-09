// 2185. Counting Words With a Given Prefix
function prefixCount(words: string[], pref: string): number {
  let count: number = 0;
  for (let i = 0; i < words.length; i++) {
    if (words[i].startsWith(pref)) {
      count++;
    }
  }
  return count;
}
// sub: https://leetcode.com/problems/counting-words-with-a-given-prefix/submissions/1502779679/?envType=daily-question&envId=2025-01-09
