/*2348. Number of Zero-Filled Subarrays
Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.



Example 1:
Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation:
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0.
Therefore, we return 6.

Example 2:
Input: nums = [0,0,0,2,0,0]
Output: 9
Explanation:
There are 5 occurrences of [0] as a subarray.
There are 3 occurrences of [0,0] as a subarray.
There is 1 occurrence of [0,0,0] as a subarray.
There is no occurrence of a subarray with a size more than 3 filled with 0.
Therefore, we return 9.

Example 3:
Input: nums = [2,10,2019]
Output: 0
Explanation: There is no subarray filled with 0. Therefore, we return 0.


Constraints:
1 <= nums.length <= 105
-109 <= nums[i] <= 109

Hint 1
For each zero, you can calculate the number of zero-filled subarrays that end on
that index, which is the number of consecutive zeros behind the current element
+ 1. Hint 2 Maintain the number of consecutive zeros behind the current element,
count the number of zero-filled subarrays that end on each index, sum it up to
get the answer.
*/

/*Intuition:
//find all sub arrays
        //count subarray having only 0 as element
        //what if we sort the array
        //find the mid check if it's 0 or not
        //do it for binary search with recursion
        //as u find it, check for left, if found see again and create the
subaraay
        //else for right same process
        //increase count for each subarray
        //return count
*/

/* For every streak of length k zeros, the number of zero-only subarrays inside
it is:

k⋅(k+1)/2

(because: 1 zero → 1 subarray, 2 zeros → 3 subarrays, 3 zeros → 6 subarrays,
etc.)
*/

class Solution {
public:
  long long zeroFilledSubarray(vector<int>& nums) {
    long long count = 0;  // total subarrays
    long long streak = 0; // current consecutive zero streak length

    for (int n : nums) {
      if (n == 0) {
        streak++;        // extend streak
        count += streak; // add all subarrays ending at this position
      } else {
        streak = 0; // reset streak if non-zero
      }
    }
    return count;
  }
};
// sub:
// https://leetcode.com/problems/number-of-zero-filled-subarrays/submissions/1740250668/?envType=daily-question&envId=2025-08-19
// sol:
// https://leetcode.com/problems/number-of-zero-filled-subarrays/solutions/7097173/2348-number-of-zero-filled-subarrays-by-mk9bb/
