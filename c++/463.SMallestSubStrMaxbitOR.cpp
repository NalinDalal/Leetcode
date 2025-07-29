/*2411. Smallest Subarrays With Maximum Bitwise OR
You are given a 0-indexed array nums of length n, consisting of non-negative
integers. For each index i from 0 to n - 1, you must determine the size of the
minimum sized non-empty subarray of nums starting at i (inclusive) that has the
maximum possible bitwise OR.

In other words, let Bij be the bitwise OR of the subarray nums[i...j]. You need
to find the smallest subarray starting at i, such that bitwise OR of this
subarray is equal to max(Bik) where i <= k <= n - 1. The bitwise OR of an array
is the bitwise OR of all the numbers in it.

Return an integer array answer of size n where answer[i] is the length of the
minimum sized subarray starting at i with maximum bitwise OR.

A subarray is a contiguous non-empty sequence of elements within an array.



Example 1:
Input: nums = [1,0,2,1,3]
Output: [3,3,2,2,1]
Explanation:
The maximum possible bitwise OR starting at any index is 3.
- Starting at index 0, the shortest subarray that yields it is [1,0,2].
- Starting at index 1, the shortest subarray that yields the maximum bitwise OR
is [0,2,1].
- Starting at index 2, the shortest subarray that yields the maximum bitwise OR
is [2,1].
- Starting at index 3, the shortest subarray that yields the maximum bitwise OR
is [1,3].
- Starting at index 4, the shortest subarray that yields the maximum bitwise OR
is [3]. Therefore, we return [3,3,2,2,1].

Example 2:
Input: nums = [1,2]
Output: [2,1]
Explanation:
Starting at index 0, the shortest subarray that yields the maximum bitwise OR is
of length 2. Starting at index 1, the shortest subarray that yields the maximum
bitwise OR is of length 1. Therefore, we return [2,1].


Constraints:
n == nums.length
1 <= n <= 105
0 <= nums[i] <= 109

Hint 1
Consider trying to solve the problem for each bit position separately.
Hint 2
For each bit position, find the position of the next number that has a 1 in that
position, if any. Hint 3 Take the maximum distance to such a number, including
the current number. Hint 4 Iterate backwards to achieve a linear complexity.
*/

/*computing the maximum OR we can get from subarrays starting at index i.
 * Once we know the maximum OR for a starting point i, we want the shortest
 * subarray from i that achieves it. The OR operation is monotonic: adding more
 * elements (to the right) can only set more bits to 1, never unset them. So if
 * we iterate backwards, we can accumulate the OR and for each bit, remember the
 * last index it was seen at.
 */
/*We iterate from the end (`n-1`) to the beginning (`0`):

1. Maintain a variable `curr_or` for the accumulated OR so far.

2. For each bit position `b` from `0` to `31`, track the last seen index where
bit `b` is set using an array `last_seen[32]`.

3. At index `i`, update `curr_or` by OR'ing `nums[i]`.

4. If bit `b` is set in `nums[i]`, update `last_seen[b] = i`.

5. To find the shortest subarray that gets us to the full OR, take the furthest
`last_seen[b]` among all bits set in `curr_or`.


    */
class Solution {
public:
  vector<int> smallestSubarrays(vector<int>& nums) {
    int n = nums.size();
    vector<int> answer(n);
    vector<int> last_seen(32, -1); // for bits 0 to 31

    for (int i = n - 1; i >= 0; --i) {
      // Update last_seen for bits set in nums[i]
      for (int b = 0; b < 32; ++b) {
        if (nums[i] & (1 << b)) {
          last_seen[b] = i;
        }
      }

      // Find the farthest index needed to get max OR
      int max_index = i;
      for (int b = 0; b < 32; ++b) {
        if (last_seen[b] != -1) {
          max_index = max(max_index, last_seen[b]);
        }
      }

      answer[i] = max_index - i + 1; // length of subarray
    }

    return answer;
  }
};

// Time: O(n)
// Space: O(1)
// sub:
// https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/submissions/1715646119/?envType=daily-question&envId=2025-07-29
// sol:
// https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/solutions/7019344/2411-smallest-subarrays-with-maximum-bit-p9k4/
