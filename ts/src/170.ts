//2401. Longest Nice Subarray
function longestNiceSubarray(nums: number[]): number {
  let left = 0,
    bitmask = 0,
    maxLen = 0;

  for (let right = 0; right < nums.length; right++) {
    // Ensure the current number doesn't share a '1' bit with the existing bitmask
    while ((bitmask & nums[right]) !== 0) {
      bitmask ^= nums[left]; // Remove leftmost number from bitmask
      left++; // Shrink window
    }

    bitmask |= nums[right]; // Add current number to bitmask
    maxLen = Math.max(maxLen, right - left + 1); // Update max length
  }

  return maxLen;
}

//sub: https://leetcode.com/problems/longest-nice-subarray/submissions/1577518612/?envType=daily-question&envId=2025-03-18
//sol: https://leetcode.com/problems/longest-nice-subarray/solutions/6549906/2401-longest-nice-subarray-by-nalindalal-39mu/
