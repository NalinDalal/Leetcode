/* 2874. Maximum Value of an Ordered Triplet II

You are given a 0-indexed integer array nums.

Return the maximum value over all triplets of indices (i, j, k) such that i < j
< k. If all such triplets have a negative value, return 0.

The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) *
nums[k].



Example 1:

Input: nums = [12,6,1,2,7]
Output: 77
Explanation: The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4]
= 77. It can be shown that there are no ordered triplets of indices with a value
greater than 77. Example 2:

Input: nums = [1,10,3,4,19]
Output: 133
Explanation: The value of the triplet (1, 2, 4) is (nums[1] - nums[2]) * nums[4]
= 133. It can be shown that there are no ordered triplets of indices with a
value greater than 133. Example 3:

Input: nums = [1,2,3]
Output: 0
Explanation: The only ordered triplet of indices (0, 1, 2) has a negative value
of (nums[0] - nums[1]) * nums[2] = -3. Hence, the answer would be 0.


Constraints:

3 <= nums.length <= 105
1 <= nums[i] <= 106
*/

/* nums[i] should be as large as possible before j to maximize (nums[i] -
nums[j]).

nums[j] should be as small as possible to maximize the difference.

nums[k] should be as large as possible after j to maximize the product.

*/

/* Optimized Approach (O(n) time complexity)
1. Precompute min_before[j]
- This stores the largest value of nums[i] before j.

2. Precompute max_after[j]
- This stores the largest value of nums[k] after j.

3. Iterate over j
- Compute value = (min_before[j] - nums[j]) * max_after[j].
- Track the maximum value.
*/
class Solution {
public:
  long long maximumTripletValue(vector<int>& nums) {
    int n = nums.size();
    if (n < 3)
      return 0;

    vector<int> max_before(n, 0);
    vector<int> max_after(n, 0);

    // Compute max_before[j]: max value before index j
    max_before[0] = nums[0];
    for (int j = 1; j < n; j++) {
      max_before[j] = max(max_before[j - 1], nums[j - 1]);
    }

    // Compute max_after[j]: max value after index j
    max_after[n - 1] = nums[n - 1];
    for (int j = n - 2; j >= 0; j--) {
      max_after[j] = max(max_after[j + 1], nums[j + 1]);
    }

    long long max_value = 0;

    // Iterate over j
    for (int j = 1; j < n - 1; j++) {
      long long left = max_before[j];
      long long mid = nums[j];
      long long right = max_after[j];

      long long value = (left - mid) * right;
      max_value = max(max_value, value);
    }

    return max_value;
  }
};
// Time: O(n)
// Space: O(n)
//  sub:
//  https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/submissions/1595490759/?envType=daily-question&envId=2025-04-03
//  Solution :
//  https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/solutions/6610983/2874-maximum-value-of-an-ordered-triplet-xkqh/
