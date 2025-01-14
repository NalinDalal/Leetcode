/* https://leetcode.com/problems/count-special-subsequences/
3404. Count Special Subsequences

You are given an array nums consisting of positive integers.

A special subsequence is defined as a subsequence of length 4, represented by
indices (p, q, r, s), where p < q < r < s. This subsequence must satisfy the
following conditions:

- nums[p] * nums[r] == nums[q] * nums[s]
- There must be at least one element between each pair of indices. In other
words, q - p > 1, r - q > 1 and s - r > 1.

Return the number of different special subsequences in nums.

Example 1:
Input: nums = [1,2,3,4,3,6,1]
Output: 1

Explanation:
There is one special subsequence in nums.
(p, q, r, s) = (0, 2, 4, 6):
This corresponds to elements (1, 3, 3, 1).
nums[p] * nums[r] = nums[0] * nums[4] = 1 * 3 = 3
nums[q] * nums[s] = nums[2] * nums[6] = 3 * 1 = 3

Example 2:
Input: nums = [3,4,3,4,3,4,3,4]
Output: 3

Explanation:
There are three special subsequences in nums.
(p, q, r, s) = (0, 2, 4, 6):
This corresponds to elements (3, 3, 3, 3).
nums[p] * nums[r] = nums[0] * nums[4] = 3 * 3 = 9
nums[q] * nums[s] = nums[2] * nums[6] = 3 * 3 = 9
(p, q, r, s) = (1, 3, 5, 7):
This corresponds to elements (4, 4, 4, 4).
nums[p] * nums[r] = nums[1] * nums[5] = 4 * 4 = 16
nums[q] * nums[s] = nums[3] * nums[7] = 4 * 4 = 16
(p, q, r, s) = (0, 2, 5, 7):
This corresponds to elements (3, 3, 4, 4).
nums[p] * nums[r] = nums[0] * nums[5] = 3 * 4 = 12
nums[q] * nums[s] = nums[2] * nums[7] = 3 * 4 = 12


Constraints:
7 <= nums.length <= 1000
1 <= nums[i] <= 1000*/

// condition:
// p < q < r < s
// nums[p]*nums[r]==nums[q] * nums[s]
// q - p > 1,r - q > 1,s - r > 1
// Instead of iterating over all combinations of four indices, use hashmaps
// or other data structures to store intermediate computations for faster
// lookups. For a fixed 𝑝, 𝑟, 𝑞, compute 𝑛𝑢𝑚𝑠[𝑝]×𝑛𝑢𝑚𝑠[𝑟]nums[p]×nums[r] and
// store it in a hash table. Then, check for matching values for subsequent
// pairs 𝑞, 𝑠 that satisfy the equality and the gap conditions int n =
// nums.size();;

/* Approach
- Iterate through the array starting from index 4 with r representing the
right-most element.
- For each r, calculate and store ratiosnums[p] / nums[q] in the map for p and q
(q = r - 2).
- For elements s after r, check if the ratio nums[s] / nums[r] exists in the map
and add its count to ans.*/

#include <unordered_map>
typedef long long ll;

class Solution {
public:
  long long numberOfSubsequences(vector<int>& nums) {
    unordered_map<double, ll> mp;
    ll ans = 0;

    for (int r = 4; r < nums.size(); r++) {
      for (int p = 0, q = r - 2; p < q - 1; p++) {
        double ratio = static_cast<double>(nums[p]) / nums[q];
        mp[ratio]++;
      }
      for (int s = r + 2; s < nums.size(); s++) {
        double ratio = static_cast<double>(nums[s]) / nums[r];
        ans += mp[ratio];
      }
    }

    return ans;
  }
};

// Time: O(n^2)
// Space: O(n)
// 72.30%
// sub:
// https://leetcode.com/problems/count-special-subsequences/submissions/1508080476/
// sol:
// https://leetcode.com/problems/count-special-subsequences/solutions/6277890/3404-count-special-subsequences7230-by-n-ctq7/
