/* 2342. Max Sum of a Pair With Equal Sum of Digits
You are given a 0-indexed array nums consisting of positive integers. You can
choose two indices i and j, such that i != j, and the sum of digits of the
number nums[i] is equal to that of nums[j].

Return the maximum value of nums[i] + nums[j] that you can obtain over all
possible indices i and j that satisfy the conditions.



Example 1:
Input: nums = [18,43,36,13,7]
Output: 54
Explanation: The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36
= 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7
= 50. So the maximum sum that we can obtain is 54.

Example 2:
Input: nums = [10,12,19,14]
Output: -1
Explanation: There are no two numbers that satisfy the conditions, so we return
-1.


Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 109*/

// i!=j
// let sum of digits be a function
// func(nums[i])==func(nums[j])
// return max(nums[i]+nums[j])
// func(nums[i]){
// sum of digits of nums[i]
//}
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
      sum += num % 10;
      num /= 10;
    }
    return sum;
  }

  int maximumSum(vector<int>& nums) {
    unordered_map<int, int>
        digitSumMap; // {sumOfDigits -> max num with that sum}
    int max_sum = -1;

    for (int num : nums) {
      int digitSum = sumOfDigits(num);

      if (digitSumMap.count(digitSum)) {
        max_sum = max(max_sum, digitSumMap[digitSum] + num);
      }

      digitSumMap[digitSum] =
          max(digitSumMap[digitSum], num); // Store max num for each sum
    }

    return max_sum;
  }
};
// Time complexity: $$O(n^2)$$

// Space complexity: $$O(n)$$
// sub:
// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/submissions/1540276874/?envType=daily-question&envId=2025-02-12
// sol:
// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/solutions/6412029/2342-max-sum-of-a-pair-with-equal-sum-of-maw0/
