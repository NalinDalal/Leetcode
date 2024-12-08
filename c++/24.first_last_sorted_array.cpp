/*
34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the
starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
*/
// logic:
/*
 base case-no Elements in array, return [-1,-1]
//binary search krwa ke position return krwa do
left=0;right=nums.size()-1;
while(left<=right){
    int mid=(left+right)/2;
    if(nums[mid]==target){return [mid,mid];}
    if(nums[left]==target){;}
    else if(nums[mid]>target){right=mid-1;}
    else{start=mid+1;}
}
else{return [-1,-1];}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    // Initialize variables to store the starting and ending indices
    int start = -1;
    int end = -1;

    // Check if the array is empty
    if (nums.size() == 0) {
      return {start, end}; // Return {-1, -1} if the array is empty
    }

    // Perform binary search to find the leftmost index of the target
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] == target) {
        start = mid;     // Found the target, update start index
        right = mid - 1; // Continue searching on the left side
      } else if (nums[mid] < target) {
        left = mid + 1; // Target is on the right side
      } else {
        right = mid - 1; // Target is on the left side
      }
    }

    // If start remains -1, target is not found in the array
    if (start == -1) {
      return {start, end}; // Return {-1, -1}
    }

    // Perform binary search to find the rightmost index of the target
    left = 0;
    right = nums.size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] == target) {
        end = mid;      // Found the target, update end index
        left = mid + 1; // Continue searching on the right side
      } else if (nums[mid] < target) {
        left = mid + 1; // Target is on the right side
      } else {
        right = mid - 1; // Target is on the left side
      }
    }

    // Return the range [start, end]
    return {start, end};
  }
};
