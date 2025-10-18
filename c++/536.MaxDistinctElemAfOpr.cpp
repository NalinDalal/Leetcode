/*3397. Maximum Number of Distinct Elements After Operations
You are given an integer array nums and an integer k.

You are allowed to perform the following operation on each element of the array
at most once:

Add an integer in the range [-k, k] to the element.
Return the maximum possible number of distinct elements in nums after performing
the operations.



Example 1:
Input: nums = [1,2,2,3,3,4], k = 2
Output: 6
Explanation: nums changes to [-1, 0, 1, 2, 3, 4] after performing operations on
the first four elements.

Example 2:
Input: nums = [4,4,4,4], k = 1
Output: 3
Explanation: By adding -1 to nums[0] and 1 to nums[1], nums changes to [3, 5, 4,
4].



Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
0 <= k <= 109

Hint 1
Can we use sorting here?
Hint 2
Find the minimum element which is not used for each element.
*/

/*1. Sort the array
2. greedy Placement
- Keep a variable `next_free` representing the smallest integer we can assign
that hasn’t been used yet.
- For each number `num` in sorted `nums`:
    1. The range we can assign is `[num - k, num + k]`.
    2. We want to assign it the maximum of `next_free` and `num - k`:
        - If this value ≤ `num + k`, it’s valid → we can use it.
        - Update `next_free` to that value + 1 (next available integer).
    3. Otherwise, skip this number because it would duplicate an already used
number.
*/

class Solution {
public:
  int maxDistinctElements(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int next_free = INT_MIN; // smallest available integer
    int count = 0;

    for (int num : nums) {
      int assigned =
          max(next_free, num - k); // pick smallest valid unused number
      if (assigned <= num + k) {
        count++;
        next_free = assigned + 1; // update next free number
      }
      // else: can't assign without duplication
    }

    return count;
  }
};
// sub:
// https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/submissions/1804816076/?envType=daily-question&envId=2025-10-18
// sol:
// https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/solutions/7283439/3397-maximum-number-of-distinct-elements-a57n/
