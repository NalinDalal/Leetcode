/* 416. Partition Equal Subset Sum

Given an integer array nums, return true if you can partition the array into two
subsets such that the sum of the elements in both subsets is equal or false
otherwise.



Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.


Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100*/

#include <vector>
using std::vector;
class Solution {
public:
  bool canPartition(vector<int>& nums) {
    // if nums can be partitioned into 2 subset such that
    // subset is subarray motherfucker
    // sum(subset1)==sum(subset2) return true
    // else return false

    // what is subset: it is subarray
    // must be contiguous

    // steps:
    // 1. find 2 subsets
    // 2. recursively check their sum and compare them
    // 3. if atleast 1 time true then return true
    // 4. else return false

    // now since sum must be equal, then whole array sum must be even
    int totalSum = 0;
    for (int num : nums) {
      totalSum += num;
    }

    // If total sum is odd, can't partition into two equal subsets
    if (totalSum % 2 != 0) {
      return false;
    }

    int target = totalSum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] =
        true; // Base case: subset sum of 0 is always possible (empty subset)

    for (int num : nums) {
      // Traverse backwards to avoid overwriting dp values in current iteration
      for (int j = target; j >= num; --j) {
        dp[j] = dp[j] || dp[j - num];
      }
    }

    return dp[target];
  }
};

// Time: O(n^2)
// Space: O(n)

// sub:
// https://leetcode.com/problems/partition-equal-subset-sum/submissions/1550405723/
// sol:
// https://leetcode.com/problems/partition-equal-subset-sum/solutions/6449661/416-partition-equal-subset-sum-by-nalind-p2tv/
