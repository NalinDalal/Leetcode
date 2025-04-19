/* 2563. Count the Number of Fair Pairs
Given a 0-indexed integer array nums of size n and two integers lower and upper,
return the number of fair pairs. A pair (i, j) is fair if: 0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper


Example 1:
Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and
(1,5).

Example 2:
Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).


Constraints:
1 <= nums.length <= 10E5
nums.length == n
-10E9 <= nums[i] <= 10E9
-10E9 <= lower <= upper <= 10E9*/

// brute force
class Solution {
public:
  long long countFairPairs(vector<int>& nums, int lower, int upper) {
    long long count = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] >= lower && nums[i] + nums[j] <= upper) {
          count++;
        }
      }
    }
    return count;
  }
};

// obviously it had to give tle
// optimise using binary search
/* - Sort the array: We sort so we can binary search the range for valid second
elements.

- For each `i`, we use:
    - `lower_bound` to find the first index `j > i` such that `nums[i] + nums[j]
>= lower`
    - `upper_bound` to find the first index `j > i` such that `nums[i] + nums[j]
> upper`

- The number of valid `pairs` for this `i` is `right - left`.*/
class Solution1 {
public:
  long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    long long count = 0;

    for (int i = 0; i < nums.size(); ++i) {
      int left =
          lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) -
          nums.begin();
      int right =
          upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) -
          nums.begin();
      count += (right - left);
    }

    return count;
  }
};
// sub:
// https://leetcode.com/problems/count-the-number-of-fair-pairs/submissions/1611122402/?envType=daily-question&envId=2025-04-19
// sol:
// https://leetcode.com/problems/count-the-number-of-fair-pairs/solutions/6665669/2563-count-the-number-of-fair-pairs-by-n-rk8n/
