/*3202. Find the Maximum Length of Valid Subsequence II
You are given an integer array nums and a positive integer k.
A subsequence sub of nums with length x is called valid if it satisfies:

(sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x -
1]) % k. Return the length of the longest valid subsequence of nums.


Example 1:
Input: nums = [1,2,3,4,5], k = 2
Output: 5
Explanation:
The longest valid subsequence is [1, 2, 3, 4, 5].

Example 2:
Input: nums = [1,4,2,3,1,4], k = 3
Output: 4
Explanation:The longest valid subsequence is [1, 4, 1, 4].



Constraints:

2 <= nums.length <= 103
1 <= nums[i] <= 107
1 <= k <= 103

Hint 1
Fix the value of (subs[0] + subs[1]) % k from the k possible values. Let it be
val. Hint 2 Let dp[i] store the maximum length of a subsequence with its last
element x such that x % k == i. Hint 3 Answer for a subsequence ending at index
y is dp[(k + val - (y % k)) % k] + 1.
*/

// okay so do what is asked
// loop over array, if i,i+1 are of same parity, then check for i+1,i+2, now as
// you move forward increase count as the parity breaks, return count
/*Loop over all possible starting points i.

For each i, attempt to build the longest subsequence such that:
```cpp
(sub[j-1] + sub[j]) % k == fixedVal  for all j in subsequence
```

Try all possible values of val = (nums[i] + nums[j]) % k, from 0 to k-1.

to make it more efficient and fast:
use Dynamic Programming- O(nk)
```cpp
(nums[i] + nums[i+1]) % k == val
```
We try all possible `val` from `0` to `k-1`.

We’ll use a DP map:
    - `dp[mod]` = longest subsequence ending with a number `x` such that `(prev
+ x) % k == val` i.e., for each `num`, if there is a `prev` such that `(prev +
num) % k == val`, extend it.

## Steps:
1. For each possible value `val` from `0` to `k - 1`:
    - Initialize `dp[mod] = 0` for all mod values.
    - For each number `num` in `nums`:
        - Compute `mod = num % k`
        - Required previous mod: `(val - mod + k) % k`
        - Update `dp[mod] = dp[required_prev_mod] + 1`

2. Keep track of max `dp[mod]` over all mods and vals.


    */
class Solution {
public:
  int maximumLength(vector<int>& nums, int k) {
    int ans = 0;
    int n = nums.size();

    for (int val = 0; val < k; ++val) {
      vector<int> dp(k, 0); // dp[i] = max length ending with mod i
      for (int x : nums) {
        int mod = x % k;
        int required_prev_mod = (val - mod + k) % k;
        dp[mod] = max(dp[mod], dp[required_prev_mod] + 1);
        ans = max(ans, dp[mod]);
      }
    }

    return ans;
  }
};
// sub:
// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/submissions/1700904668/?envType=daily-question&envId=2025-07-17
// sol:
// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/solutions/6969313/3202-find-the-maximum-length-of-valid-su-kfj0/
