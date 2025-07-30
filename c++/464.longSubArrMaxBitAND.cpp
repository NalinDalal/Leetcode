/*2419. Longest Subarray With Maximum Bitwise AND
You are given an integer array nums of size n.

Consider a non-empty subarray from nums that has the maximum possible bitwise
AND.

In other words, let k be the maximum value of the bitwise AND of any subarray of
nums. Then, only subarrays with a bitwise AND equal to k should be considered.
Return the length of the longest such subarray.

The bitwise AND of an array is the bitwise AND of all the numbers in it.

A subarray is a contiguous sequence of elements within an array.



Example 1:

Input: nums = [1,2,3,3,2,2]
Output: 2
Explanation:
The maximum possible bitwise AND of a subarray is 3.
The longest subarray with that value is [3,3], so we return 2.
Example 2:

Input: nums = [1,2,3,4]
Output: 1
Explanation:
The maximum possible bitwise AND of a subarray is 4.
The longest subarray with that value is [4], so we return 1.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106

Hint 1
Notice that the bitwise AND of two different numbers will always be strictly
less than the maximum of those two numbers. Hint 2 What does that tell us about
the nature of the subarray that we should choose?
*/
// find max bitwise and
// then find longest subarray with the value
// return length of that subarray
class Solution {
public:
  int longestSubarray(vector<int>& nums) {
    int maxVal = *max_element(nums.begin(), nums.end());
    int longest = 0, current = 0;

    for (int num : nums) {
      if (num == maxVal) {
        current++;
        longest = max(longest, current);
      } else {
        current = 0;
      }
    }

    return longest;
  }
};
// sub:
// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/submissions/1716477853/?envType=daily-question&envId=2025-07-30
// sol:
// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/solutions/7022002/2419-longest-subarray-with-maximum-bitwi-6z4b/
