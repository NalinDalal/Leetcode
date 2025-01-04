// 1930. Unique Length-3 Palindromic Subsequences
function countPalindromicSubsequence(s: string): number {
  let n: number = s.size();
  let count: number = 0;
  for (let mid = "a".charCodeAt(0); mid <= "z".charCodeAt(0); mid++) {
    let left = -1,
      right = -1;
    const charMid = String.fromCharCode(mid);

    // Find the first and last occurrence of the character
    for (let i = 0; i < s.length; i++) {
      if (s[i] === charMid) {
        if (left === -1) {
          left = i;
        }
        right = i;
      }
    }

    // If there are at least two occurrences (left and right), count unique characters in between
    if (left !== -1 && right !== -1 && left < right) {
      const uniqueChars = new Set<string>();
      for (let i = left + 1; i < right; i++) {
        uniqueChars.add(s[i]);
      }
      count += uniqueChars.size;
    }
  }
  return count;
}
