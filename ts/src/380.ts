//3005. Count Elements With Maximum Frequency
function maxFrequencyElements(nums: number[]): number {
  const freq = new Map<number, number>();

  // Step 1: Count frequencies
  for (const num of nums) {
    freq.set(num, (freq.get(num) ?? 0) + 1);
  }

  // Step 2: Find maximum frequency
  let maxFreq = 0;
  for (const count of freq.values()) {
    if (count > maxFreq) {
      maxFreq = count;
    }
  }

  // Step 3: Sum occurrences of elements with max frequency
  let result = 0;
  for (const count of freq.values()) {
    if (count === maxFreq) {
      result += count;
    }
  }

  return result;
}
//sub: https://leetcode.com/problems/count-elements-with-maximum-frequency/submissions/1778642480/?envType=daily-question&envId=2025-09-22
//sol: https://leetcode.com/problems/count-elements-with-maximum-frequency/solutions/7212458/3005-count-elements-with-maximum-frequen-lyxo/
