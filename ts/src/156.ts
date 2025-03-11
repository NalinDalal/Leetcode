//1358. Number of Substrings Containing All Three Characters
function numberOfSubstrings(s: string): number {
  let count: number[] = [0, 0, 0]; // Track frequency of 'a', 'b', 'c'
  let l: number = 0,
    ans: number = 0;

  for (let r = 0; r < s.length; r++) {
    count[s.charCodeAt(r) - "a".charCodeAt(0)]++; // Increment count of current character

    // Shrink left pointer while all 'a', 'b', 'c' are present
    while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
      ans += s.length - r; // All substrings from l to end are valid
      count[s.charCodeAt(l) - "a".charCodeAt(0)]--; // Remove leftmost character
      l++; // Move left pointer
    }
  }
  return ans;
}
//sub: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/submissions/1569768379/?envType=daily-question&envId=2025-03-11
//sol: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/solutions/6522323/1358-number-of-substrings-containing-all-3j72/
