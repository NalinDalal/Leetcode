/* 2537. Count the Number of Good Subarrays
Given an integer array nums and an integer k, return the number of good
subarrays of nums.

A subarray arr is good if there are at least k pairs of indices (i, j) such that
i < j and arr[i] == arr[j].

A subarray is a contiguous non-empty sequence of elements within an array.



Example 1:
Input: nums = [1,1,1,1,1], k = 10
Output: 1
Explanation: The only good subarray is the array nums itself.

Example 2:
Input: nums = [3,1,4,3,2,2,4], k = 2
Output: 4
Explanation: There are 4 different good subarrays:
- [3,1,4,3,2,2] that has 2 pairs.
- [3,1,4,3,2,2,4] that has 3 pairs.
- [1,4,3,2,2,4] that has 2 pairs.
- [4,3,2,2,4] that has 2 pairs.


Constraints:

1 <= nums.length <= 105
1 <= nums[i], k <= 109 */

// number of contiguous subarrays that contain at least k pairs (i, j) such that
// i < j and nums[i] == nums[j]
/* A pair (i, j) is valid if i < j and nums[i] == nums[j].

A subarray is a contiguous piece of the array.*/

// optimisation: use Sliding Window+Freq Map
// count the number of equal-value pairs in a window via Freq Map

class Solution {
public:
  long long countGood(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    long long res = 0;
    long long countPairs = 0;
    int left = 0;

    for (int right = 0; right < nums.size(); ++right) {
      int val = nums[right];
      countPairs += freq[val]; // each previous val is a pair
      freq[val]++;

      while (countPairs >= k) {
        res += nums.size() - right; // all windows ending at >= right are valid
        int lval = nums[left];
        freq[lval]--;
        countPairs -= freq[lval]; // remove the pairs formed with lval
        left++;
      }
    }

    return res;
  }
};

// sub:
// https://leetcode.com/problems/count-the-number-of-good-subarrays/submissions/1608087017/?envType=daily-question&envId=2025-04-16
// sol:
// https://leetcode.com/problems/count-the-number-of-good-subarrays/solutions/6655003/2537-count-the-number-of-good-subarrays-z0rgf/
