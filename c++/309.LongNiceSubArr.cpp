/*2401. Longest Nice Subarray

You are given an array nums consisting of positive integers.

We call a subarray of nums nice if the bitwise AND of every pair of elements
that are in different positions in the subarray is equal to 0.

Return the length of the longest nice subarray.

A subarray is a contiguous part of an array.

Note that subarrays of length 1 are always considered nice.



Example 1:

Input: nums = [1,3,8,48,10]
Output: 3
Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the
conditions:
- 3 AND 8 = 0.
- 3 AND 48 = 0.
- 8 AND 48 = 0.
It can be proven that no longer nice subarray can be obtained, so we return 3.
Example 2:

Input: nums = [3,1,5,11,13]
Output: 1
Explanation: The length of the longest nice subarray is 1. Any subarray of
length 1 can be chosen.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109*/

// Approach
/*Use Sliding Window
1. Maintain a bitmask window_mask that represents the OR of all numbers in the
current window.
2. Use a sliding window (two pointers) approach:
- Expand the window by including nums[right] in window_mask.
- If window_mask & nums[right] is non-zero, it means there is an overlap in set
bits, and we need to shrink the window from the left until it becomes valid
again.
- Update the maximum length found.
*/
class Solution {
public:
  int longestNiceSubarray(vector<int>& nums) {
    int left = 0, bitmask = 0, maxLen = 0;

    for (int right = 0; right < nums.size(); right++) {
      // Ensure the current number doesn't share a '1' bit with the existing
      // bitmask
      while ((bitmask & nums[right]) != 0) {
        bitmask ^= nums[left]; // Remove leftmost number from bitmask
        left++;                // Shrink window
      }

      bitmask |= nums[right];                 // Add current number to bitmask
      maxLen = max(maxLen, right - left + 1); // Update max length
    }

    return maxLen;
  }
};
// sub:
// https://leetcode.com/problems/longest-nice-subarray/submissions/1577513975/?envType=daily-question&envId=2025-03-18
// sol:
// https://leetcode.com/problems/longest-nice-subarray/solutions/6549906/2401-longest-nice-subarray-by-nalindalal-39mu/
