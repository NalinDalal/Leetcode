//647. Palindromic Substrings
function countSubstrings(s: string): number {
  let count: number = 0;
  if (s.length === 1) return 1;
  for (let center = 0; center < 2 * s.length - 1; ++center) {
    let left = Math.floor(center / 2);
    let right = left + (center % 2);

    // Expand while palindrome condition holds
    while (left >= 0 && right < s.length && s[left] == s[right]) {
      count++; // Found a palindrome
      left--; // Expand left
      right++; // Expand right
    }
  }

  return count;
}
//sub: https://leetcode.com/problems/palindromic-substrings/submissions/1543414581/
//sol: https://leetcode.com/problems/palindromic-substrings/solutions/6423624/647-palindromic-substrings-by-nalindalal-pzy6/
