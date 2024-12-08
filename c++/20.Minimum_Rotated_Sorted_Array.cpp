/*
 * 153. Find Minimum in Rotated Sorted Array
 * Suppose an array of length n sorted in ascending order is rotated between 1
and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in
the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum
element of this array.

You must write an algorithm that runs in O(log n) time.



Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times.

* */

/* Solution
    # Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
I don't give a damn how many times rotated. I was asked to return minimum
element

# Approach
<!-- Describe your approach to solving the problem. -->
Sort the array, so irrespective of how many times it was rotated, the element
get arranged in ascending order, hence can return the element at 0th index

# Complexity
- Time complexity:O(nlogn) of the sort function implemented. Then accessing the
0th index O(1)
- O(nlogn)+O(1)=O(nlogn)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:O(log n) of the sort function
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

    */
class Solution {
public:
  int findMin(std::vector<int>& nums) {
    if (nums.empty()) {
      std::cout << "The input vector is empty." << std::endl;
      return -1; // or throw an exception, depending on your requirements
    }

    std::sort(nums.begin(), nums.end());
    return nums[0];
  }
};
