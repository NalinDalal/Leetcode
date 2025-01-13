// https://leetcode.com/problems/minimum-length-of-string-after-operations/description/?envType=daily-question&envId=2025-01-13
//3223. Minimum Length of String After Operations

function minimumLength(s: string): number {
  // Initialize frequency array for 26 letters
  const charFrequency: number[] = new Array(26).fill(0);
  let totalLength = 0;

  // Count character frequencies
  for (const currentChar of s) {
    charFrequency[currentChar.charCodeAt(0) - "a".charCodeAt(0)]++;
  }

  // Calculate the total length
  for (const frequency of charFrequency) {
    if (frequency === 0) continue;
    if (frequency % 2 === 0) {
      totalLength += 2;
    } else {
      totalLength += 1;
    }
  }

  return totalLength;
}
//sub: https://leetcode.com/problems/minimum-length-of-string-after-operations/submissions/1507264753/?envType=daily-question&envId=2025-01-13
//sol: https://leetcode.com/problems/minimum-length-of-string-after-operations/solutions/6274015/3223-minimum-length-of-string-after-oper-z5e9/
