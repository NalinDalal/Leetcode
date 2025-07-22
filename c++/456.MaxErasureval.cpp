/*1695. Maximum Erasure Value
You are given an array of positive integers nums and want to erase a subarray
containing unique elements. The score you get by erasing the subarray is equal
to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence
of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).



Example 1:
Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].

Example 2:
Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].


Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 104

Hint 1
The main point here is for the subarray to contain unique elements for each
index. Only the first subarrays starting from that index have unique elements.
Hint 2
This can be solved using the two pointers technique
*/

/*Sliding window will move and expand until a duplicate is found.

When a duplicate is found, shrink from the left until it becomes unique again.
    */

/*1. Use a set to track elements in the current window.

2. Use two pointers: left and right.

3. While expanding right:

- If the element is not in set, add it and add to the current sum.

- If it's already in the set:

    - Shrink from the left by removing nums[left] until nums[right] can be
inserted.

4. Track the maximum sum during this process.


    */
class Solution {
public:
  int maximumUniqueSubarray(vector<int>& nums) {
    unordered_set<int> seen;
    int left = 0, curr_sum = 0, max_sum = 0;

    for (int right = 0; right < nums.size(); ++right) {
      while (seen.count(nums[right])) {
        seen.erase(nums[left]);
        curr_sum -= nums[left];
        left++;
      }
      seen.insert(nums[right]);
      curr_sum += nums[right];
      max_sum = max(max_sum, curr_sum);
    }

    return max_sum;
  }
};
// sub:
// https://leetcode.com/problems/maximum-erasure-value/submissions/1707143011/?envType=daily-question&envId=2025-07-22
// sol:
// https://leetcode.com/problems/maximum-erasure-value/solutions/6990314/1695-maximum-erasure-value-by-nalindalal-l3ep/
