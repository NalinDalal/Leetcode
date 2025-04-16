/* 137. Single Number II
Given an integer array nums where every element appears three times except for
one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only
constant extra space.



Example 1:
Input: nums = [2,2,3,2]
Output: 3

Example 2:
Input: nums = [0,1,0,1,0,1,99]
Output: 99


Constraints:
1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which
appears once.
*/

// given an array of integers, find the element appearing only once and return
// it so notice that if we sort the array, then element which appears once will
// have no neighbour to it's equal

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    // Check edge cases
    if (n == 1 || nums[0] != nums[1])
      return nums[0];
    if (nums[n - 1] != nums[n - 2])
      return nums[n - 1];

    for (int i = 1; i < n - 1; i++) {
      if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) {
        return nums[i];
      }
    }

    return -1; // Should never reach here
  }
};
// sub:
// https://leetcode.com/problems/single-number-ii/submissions/1608076920/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int ones = 0;
    int twos = 0;

    for (const int num : nums) {
      ones ^= (num & ~twos);
      twos ^= (num & ~ones);
    }

    return ones;
  }
};
//  optimal:
//  https://leetcode.com/problems/single-number-ii/submissions/1608077340/?envType=study-plan-v2&envId=top-interview-150
//  sol:
//  https://leetcode.com/problems/single-number-ii/solutions/6654971/137-single-number-ii-by-nalindalal2004-u5qy/
