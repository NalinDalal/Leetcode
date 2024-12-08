/*
 * Question 167
Given a 1-indexed array of integers numbers that is already sorted in
non-decreasing order, find two numbers such that they add up to a specific
target number. Let these two numbers be numbers[index1] and numbers[index2]
where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an
integer array [index1, index2] of length 2.

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We
return [1, 2]. Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We
return [1, 3]. Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We
return [1, 2].

*/

// Solution 1 on the first intituion
class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    for (int i = 0; i < numbers.size() - 1; i++) {
      for (int j = i + 1; j < numbers.size(); j++) {
        if (numbers[i] + numbers[j] == target) {
          return {i + 1, j + 1}; // Return indices of the two numbers
        }
      }
    }
    return {};
  }
};

// Solution 2 after little bit research based on 2 pointer approach
// Time Complexity: O(n)
//
// Array is sorted- small sum from left subarray, large sum from right subarray
// If our current sum is too small, move closer to the right.
// If our current sum is too large, move closer to the left.
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int L = 0, R = nums.size() - 1;
    while (L < R) {
      if (nums[L] + nums[R] > target) {
        R--;
      } else if (nums[L] + nums[R] < target) {
        L++;
      } else {
        return vector<int>{L + 1, R + 1};
      }
    }
    return vector<int>();
  }
};
