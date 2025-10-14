/*3349. Adjacent Increasing Subarrays Detection I
Given an array nums of n integers and an integer k, determine whether there
exist two adjacent subarrays of length k such that both subarrays are strictly
increasing. Specifically, check if there are two subarrays starting at indices a
and b (a < b), where:

Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly
increasing. The subarrays must be adjacent, meaning b = a + k. Return true if it
is possible to find two such subarrays, and false otherwise.



Example 1:
Input: nums = [2,5,7,8,9,2,3,4,3,1], k = 3
Output: true
Explanation:
The subarray starting at index 2 is [7, 8, 9], which is strictly increasing.
The subarray starting at index 5 is [2, 3, 4], which is also strictly
increasing. These two subarrays are adjacent, so the result is true.


Example 2:
Input: nums = [1,2,3,4,4,4,4,5,6,7], k = 5
Output: false



Constraints:
2 <= nums.length <= 100
1 < 2 * k <= nums.length
-1000 <= nums[i] <= 1000

Hint 1
Store the longest decreasing subarray starting and ending at an index.
*/

/*Approach:
1. Compute `inc[i]`:
`inc[i]` = length of strictly increasing subarray ending at index i.
(so if `nums[i] > nums[i-1]`, then `inc[i] = inc[i-1] + 1`, else `inc[i] = 1`)

2. Compute `dec[i]`:
(actually the hint says "store longest decreasing subarray starting/ending", but
we can do increasing, it’s symmetric logic) Or we can instead store
`inc_start[i]` = length of strictly increasing subarray starting at `i` if
needed.

3. For each valid `a`:
- Check if subarray `[a..a+k-1]` is strictly increasing → means `inc[a+k-1] >=
k`
- Check if subarray `[a+k..a+2k-1]` is strictly increasing → means `inc[a+2k-1]
>= k`
- Additionally, to ensure both subarrays are distinct & adjacent, we must ensure
both fit in the array (`a + 2k <= n`)

If both conditions hold, return `true`.
*/

class Solution {
public:
  bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < 2 * k)
      return false;

    // inc[i] = length of increasing subarray ending at i
    vector<int> inc(n, 1);
    for (int i = 1; i < n; i++) {
      if (nums[i] > nums[i - 1])
        inc[i] = inc[i - 1] + 1;
    }

    // Now check adjacent subarrays
    for (int a = 0; a + 2 * k - 1 < n; a++) {
      int firstEnd = a + k - 1;
      int secondEnd = a + 2 * k - 1;

      if (inc[firstEnd] >= k && inc[secondEnd] >= k)
        return true;
    }
    return false;
  }
};
// sub:
// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/submissions/1801136534/?envType=daily-question&envId=2025-10-14
// sol:
// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/solutions/7274080/3349-adjacent-increasing-subarrays-detec-4f8y/
