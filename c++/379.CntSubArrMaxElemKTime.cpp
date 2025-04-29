/* 2962. Count Subarrays Where Max Element Appears at Least K Times

You are given an integer array nums and a positive integer k.
Return the number of subarrays where the maximum element of nums appears at
least k times in that subarray. A subarray is a contiguous sequence of elements
within an array.



Example 1:
Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are:
[1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].

Example 2:
Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.


Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 106
1 <= k <= 105
*/

// count the number of subarrays in which the maximum element of nums appears at
// least k times traversing the array and tracking the frequency of the maximum
// element in a dynamic range

/* use Sliding Window
- As we traverse the array, we should maintain the frequency of the maximum
element within the window. Whenever we encounter the maximum element, we
increment the frequency.
- freq>=k
- whenever the frequency of the maximum element in the window > k, we shrink the
window.
- shrink start so that frequency of the maximum element in the window is exactly
k to identify subarrays that have the maximum element appear at least k times.
- By adding start to the answer, we ensure that we account for all valid
subarrays ending at the current index end.
*/

/*Approach

## Initialization

- Initialize variables `max_element`, `ans`, `start`, and
`max_elements_in_window`.
- `max_element` stores the maximum element in the given array `nums`.
- `ans` will be the final count of subarrays meeting the condition.
- `start` is a pointer for the start of the window.
- `max_elements_in_window` stores the frequency of the `max_element` within the
current window.

## Iterating through the array

- Iterate through each element in the array using a `for` loop with index `end`
ranging from `0` to the length of `nums`.

## Counting frequency of `max_element` in the current window

- Check if the current element `nums[end]` is equal to `max_element`.
- If true, increment `max_elements_in_window` as it represents the frequency of
`max_element` in the current window.

## Sliding window to meet the condition

- Use a `while` loop to shrink the window (`start` pointer) until
`max_elements_in_window` is equal to `k`.
- Inside the `while` loop:
  - Decrement `max_elements_in_window` if the element at the window's start
(`nums[start]`) is equal to `max_element`.
  - Increment `start` to move the window to the right.

## Counting subarrays

- Add `start` to the `ans` variable inside the `for` loop, accumulating the
count of subarrays meeting the condition.

## Returning the result

- After the loop completes, return the final count stored in the `ans` variable.

*/

class Solution {
public:
  long long countSubarrays(vector<int>& nums, int k) {
    int maxElement = *max_element(nums.begin(), nums.end());
    long long ans = 0, start = 0;
    int maxElementsInWindow = 0;

    for (int end = 0; end < nums.size(); end++) {
      if (nums[end] == maxElement) {
        maxElementsInWindow++;
      }
      while (maxElementsInWindow == k) {
        if (nums[start] == maxElement) {
          maxElementsInWindow--;
        }
        start++;
      }
      ans += start;
    }
    return ans;
  }
};
// sub:
// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/submissions/1620703104/?envType=daily-question&envId=2025-04-29
