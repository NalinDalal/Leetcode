/* 2762. Continuous Subarrays

You are given a 0-indexed integer array nums. A subarray of nums is called
continuous if:

Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of
indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2. Return the total
number of continuous subarrays.

A subarray is a contiguous non-empty sequence of elements within an array.



Example 1:
Input: nums = [5,4,2,4]
Output: 8
Explanation:
Continuous subarray of size 1: [5], [4], [2], [4].
Continuous subarray of size 2: [5,4], [4,2], [2,4].
Continuous subarray of size 3: [4,2,4].
Thereare no subarrys of size 4.
Total continuous subarrays = 4 + 3 + 1 = 8.
It can be shown that there are no more continuous subarrays.


Example 2:
Input: nums = [1,2,3]
Output: 6
Explanation:
Continuous subarray of size 1: [1], [2], [3].
Continuous subarray of size 2: [1,2], [2,3].
Continuous subarray of size 3: [1,2,3].
Total continuous subarrays = 3 + 2 + 1 = 6.


Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
*/

// Approach:
/*1.Sliding Window: We will maintain a sliding window defined by two pointers
(left and right) to represent the current subarray.
2.Frequency Map: Use a frequency map to store the count of each element in the
current window.

3.Validity Condition: The subarray is valid as long as the difference between
the maximum and minimum elements in the window is less than or equal to 2. If
the difference exceeds 2, we will contract the window from the left.

4.Counting Subarrays: For each valid window, the number of valid subarrays
ending at right is given by (right - left + 1) since any subarray between left
and right (inclusive) is valid.*/

#include <algorithm>
#include <deque>
#include <unordered_map>
#include <vector>

class Solution {
public:
  long long continuousSubarrays(std::vector<int>& nums) {
    int left = 0;
    long long result = 0;
    std::unordered_map<int, int> freq;

    for (int right = 0; right < nums.size(); ++right) {
      // Add the current element to the frequency map
      freq[nums[right]]++;

      // While the window is invalid (max - min > 2), contract it from the left
      while (
          std::max_element(
              freq.begin(), freq.end(),
              [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                return a.first < b.first;
              })->first -
              std::min_element(freq.begin(), freq.end(),
                               [](const std::pair<int, int>& a,
                                  const std::pair<int, int>& b) {
                                 return a.first < b.first;
                               })
                  ->first >
          2) {
        freq[nums[left]]--;
        if (freq[nums[left]] == 0) {
          freq.erase(nums[left]);
        }
        left++;
      }

      // Add the number of valid subarrays ending at `right`
      result += (right - left + 1);
    }

    return result;
  }
};

// Time Complexity: O(n log n)
// Space Complexity: O(k), where k is the number of unique elements in the
// window at any given time

// Optimised
/* 1.Sliding Window with Two Pointers (left and right):
We use two pointers, left and right, to represent the current sliding window.
For each element added to the window (via the right pointer), we check if the
difference between the maximum and minimum values in the window exceeds 2. If it
does, we move the left pointer to shrink the window until the difference is no
more than 2.

2. Track Min and Max Explicitly:
We can use two deques to efficiently track the minimum and maximum values in the
current window in O(1) time: One deque will store elements in increasing order
to give us the current minimum. Another deque will store elements in decreasing
order to give us the current maximum.

3. Count Valid Subarrays:
For every valid window (from left to right), the number of valid subarrays
ending at right is right - left + 1.*/
class Solution {
public:
  long long continuousSubarrays(std::vector<int>& nums) {
    int left = 0;
    long long result = 0;
    std::deque<int> minDeque, maxDeque;

    for (int right = 0; right < nums.size(); ++right) {
      // Maintain the min deque: increasing order
      while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
        minDeque.pop_back();
      }
      minDeque.push_back(right);

      // Maintain the max deque: decreasing order
      while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
        maxDeque.pop_back();
      }
      maxDeque.push_back(right);

      // Shrink the window from the left if the condition is violated
      while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
        // Move `left` to the right
        left++;
        // Pop elements from the front of the deques if they are out of the
        // window
        if (minDeque.front() < left)
          minDeque.pop_front();
        if (maxDeque.front() < left)
          maxDeque.pop_front();
      }

      // Count the number of valid subarrays ending at `right`
      result += (right - left + 1);
    }

    return result;
  }
};

// Time complexity:$$O(n)$$
// Space complexity:$$O(n)$$
