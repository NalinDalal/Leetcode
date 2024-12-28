/*
https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/?envType=daily-question&envId=2024-12-28

689. Maximum Sum of 3 Non-Overlapping Subarrays
Given an integer array nums and an integer k, find three non-overlapping
subarrays of length k with maximum sum and return them.

Return the result as a list of indices representing the starting position of
each interval (0-indexed). If there are multiple answers, return the
lexicographically smallest one.



Example 1:
Input: nums = [1,2,1,2,6,7,5,1], k = 2
Output: [0,3,5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices
[0, 3, 5]. We could have also taken [2, 1], but an answer of [1, 3, 5] would be
lexicographically larger.

Example 2:
Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
Output: [0,2,4]


Constraints:
1 <= nums.length <= 2 * 104
1 <= nums[i] < 216
1 <= k <= floor(nums.length / 3)
*/

#include <iostream>
#include <vector>
using namespace std;

// what to do:
// 1. well create a array to store the indicies of subarray starting position
// 2. Precompute the sums of all subarrays of length k.
// 3. Use dynamic programming to find the maximum subarray sums for intervals
// ending at specific indices.
// 4. Backtrack to find the indices of the three subarrays that yield the
// maximum sum.
// 5. return the array

class Solution {
public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int n = nums.size();

    // Step 1: Precompute the sums of all subarrays of length k
    vector<int> subarraySums(n - k + 1, 0);
    int currentSum = 0;
    for (int i = 0; i < n; ++i) {
      currentSum += nums[i];
      if (i >= k - 1) {
        subarraySums[i - k + 1] = currentSum;
        currentSum -= nums[i - k + 1];
      }
    }

    // Step 2: Use DP to find max subarray sums for intervals ending at specific
    // indices
    vector<int> left(n - k + 1, 0), right(n - k + 1, n - k);

    // Calculate left: max subarray ending at or before each index
    int maxIdx = 0;
    for (int i = 0; i < subarraySums.size(); ++i) {
      if (subarraySums[i] > subarraySums[maxIdx]) {
        maxIdx = i;
      }
      left[i] = maxIdx;
    }

    // Calculate right: max subarray starting at or after each index
    maxIdx = n - k;
    for (int i = subarraySums.size() - 1; i >= 0; --i) {
      if (subarraySums[i] >= subarraySums[maxIdx]) {
        maxIdx = i;
      }
      right[i] = maxIdx;
    }

    // Step 3: Backtrack to find the indices of three subarrays
    vector<int> result(3, -1);
    int maxSum = 0;
    for (int mid = k; mid <= n - 2 * k; ++mid) {
      int l = left[mid - k];
      int r = right[mid + k];
      int currentSum = subarraySums[l] + subarraySums[mid] + subarraySums[r];
      if (currentSum > maxSum) {
        maxSum = currentSum;
        result = {l, mid, r};
      }
    }

    return result;
  }
};

// Example usage
int main() {
  Solution sol;
  vector<int> nums = {7, 13, 20, 19, 19, 2, 10, 1, 1, 19};
  int k = 3;
  vector<int> result = sol.maxSumOfThreeSubarrays(nums, k);
  for (int idx : result) {
    cout << idx << " ";
  }
  return 0;
}

// Time: O(n)
// Space: O(n)
