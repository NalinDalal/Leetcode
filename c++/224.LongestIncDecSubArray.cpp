/* https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/description/
3105. Longest Strictly Increasing or Strictly Decreasing Subarray
Easy
Topics
Companies
You are given an array of integers nums. Return the length of the longest
subarray
 of nums which is either
strictly increasing
 or
strictly decreasing
.



Example 1:

Input: nums = [1,4,3,3,2]

Output: 2

Explanation:

The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and
[1,4].

The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2],
and [4,3].

Hence, we return 2.

Example 2:

Input: nums = [3,3,3,3]

Output: 1

Explanation:

The strictly increasing subarrays of nums are [3], [3], [3], and [3].

The strictly decreasing subarrays of nums are [3], [3], [3], and [3].

Hence, we return 1.

Example 3:

Input: nums = [3,2,1]

Output: 3

Explanation:

The strictly increasing subarrays of nums are [3], [2], and [1].

The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1], and
[3,2,1].

Hence, we return 3.



Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 50
*/

#include <algorithm>
#include <vector>
using std::vector, std::max;
class Solution {
public:
  int longestMonotonicSubarray(vector<int>& nums) {
    // Traverse the array to find the length of the longest increasing subarray.
    // Similarly, traverse the array to find the length of the longest
    // decreasing subarray. Return the maximum of these two lengths.
    int n = nums.size();
    if (n == 0)
      return 0;

    int maxLength = 1;
    int incLength = 1;
    int decLength = 1;

    for (int i = 1; i < n; ++i) {
      if (nums[i] > nums[i - 1]) {
        incLength++;
        decLength = 1; // Reset decreasing sequence
      } else if (nums[i] < nums[i - 1]) {
        decLength++;
        incLength = 1; // Reset increasing sequence
      } else {
        // Reset both if elements are equal
        incLength = 1;
        decLength = 1;
      }
      maxLength = max(maxLength, max(incLength, decLength));
    }

    return maxLength;
  }
};

// Time: O(n)
// Space: O(1)
//  sub:
//  https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/submissions/1530023343/
//  sol:
//  https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/solutions/6368887/3105-longest-strictly-increasing-or-stri-z2r1/
