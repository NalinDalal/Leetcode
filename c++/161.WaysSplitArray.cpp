/* 2270. Number of Ways to Split Array

You are given a 0-indexed integer array nums of length n.

nums contains a valid split at index i if the following are true:

The sum of the first i + 1 elements is greater than or equal to the sum of the
last n - i - 1 elements. There is at least one element to the right of i. That
is, 0 <= i < n - 1. Return the number of valid splits in nums.



Example 1:
Input: nums = [10,4,-8,7]
Output: 2
Explanation:
There are three ways of splitting nums into two non-empty parts:
- Split nums at index 0. Then, the first part is [10], and its sum is 10. The
second part is [4,-8,7], and its sum is 3. Since 10 >= 3, i = 0 is a valid
split.
- Split nums at index 1. Then, the first part is [10,4], and its sum is 14. The
second part is [-8,7], and its sum is -1. Since 14 >= -1, i = 1 is a valid
split.
- Split nums at index 2. Then, the first part is [10,4,-8], and its sum is 6.
The second part is [7], and its sum is 7. Since 6 < 7, i = 2 is not a valid
split. Thus, the number of valid splits in nums is 2.

Example 2:
Input: nums = [2,3,1,0]
Output: 2
Explanation:
There are two valid splits in nums:
- Split nums at index 1. Then, the first part is [2,3], and its sum is 5. The
second part is [1,0], and its sum is 1. Since 5 >= 1, i = 1 is a valid split.
- Split nums at index 2. Then, the first part is [2,3,1], and its sum is 6. The
second part is [0], and its sum is 0. Since 6 >= 0, i = 2 is a valid split.


Constraints:
2 <= nums.length <= 105
-105 <= nums[i] <= 105 */

#include <vector>
using std::vector;
class Solution {
public:
  int waysToSplitArray(vector<int>& nums) {
    vector<int> sums(nums.size());
    // sum(a[0],a[i+1])>=sum(a[n-i-1],a[n-1])
    // 0<=i<n-1
    for (int i = 0; i < nums.size(); i++) {
      sums[i] = sums[i - 1] + nums[i];
    }
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (sums[i] >= sums[nums.size() - 1 - i]) {
        ans++;
      }
    }
    return ans;
  }
};

// problem: Index out-of-bounds in the sum calculation;Incorrect sum comparison
// in the second loop Approach:
/* 1. Cumulative sums: You can calculate the prefix sum of the array and use the
 * total sum of the array to calculate the suffix sum dynamically
 * 2. One pass: Calculate the left sum (`left_sum`) incrementally while
 * subtracting it from the `total_sum` to get the right sum. If `left_sum` is
 * greater than or equal to `right_sum`, increment the count of valid splits.*/
class Solution1 {
public:
  int waysToSplitArray(vector<int>& nums) {
    int n = nums.size();
    long long total_sum = 0; // Total sum of the array
    for (int num : nums) {
      total_sum += num;
    }

    long long left_sum = 0; // Left part of the sum
    int ans = 0;

    // Iterate through the array, excluding the last element (since we need at
    // least one element on each side)
    for (int i = 0; i < n - 1; ++i) {
      left_sum += nums[i];
      long long right_sum = total_sum - left_sum;

      // If left_sum >= right_sum, we have a valid split
      if (left_sum >= right_sum) {
        ans++;
      }
    }

    return ans;
  }
};
// t.ly/x2Wzs
