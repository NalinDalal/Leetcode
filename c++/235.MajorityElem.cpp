/* 169. Majority Element
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You
may assume that the majority element always exists in the array.


Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2


Constraints:
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
*/

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    // since a elements appear more than n/2 times
    // just sort array
    // return n/2 element
    std::sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
  }
};

// optimised
class Solution {
public:
  int majorityElement(std::vector<int>& nums) {
    int candidate = 0, count = 0;
    for (int num : nums) {
      if (count == 0)
        candidate = num;
      count += (num == candidate) ? 1 : -1;
    }
    return candidate;
  }
};
// Time: O(n)
// Space: O(n)
// sub: https://leetcode.com/problems/majority-element/submissions/1536826617/
// sol:
// https://leetcode.com/problems/majority-element/solutions/6397472/169-majority-element-by-nalindalal2004-ej27/
