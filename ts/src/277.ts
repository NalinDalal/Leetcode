//3442. Maximum Difference Between Even and Odd Frequency I
function maxDifference(s: string): number {
  const freq: Record<string, number> = {};

  // Count frequency of each character
  for (const c of s) {
    freq[c] = (freq[c] || 0) + 1;
  }

  const oddFreqs: number[] = [];
  const evenFreqs: number[] = [];

  // Separate odd and even frequencies
  for (const count of Object.values(freq)) {
    if (count % 2 === 0) {
      evenFreqs.push(count);
    } else {
      oddFreqs.push(count);
    }
  }

  if (oddFreqs.length === 0 || evenFreqs.length === 0) {
    return -1; // No valid odd-even pair
  }

  let maxDiff = Number.MIN_SAFE_INTEGER;
  for (const odd of oddFreqs) {
    for (const even of evenFreqs) {
      maxDiff = Math.max(maxDiff, odd - even);
    }
  }

  return maxDiff;
}
//sub:https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/submissions/1659267787/?envType=daily-question&envId=2025-06-10
//sol:https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/solutions/6827928/3442-maximum-difference-between-even-and-m7j6/
