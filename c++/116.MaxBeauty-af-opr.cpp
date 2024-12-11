/* 2779. Maximum Beauty of an Array After Applying Operation

You are given a 0-indexed array nums and a non-negative integer k.

In one operation, you can do the following:
- Choose an index i that hasn't been chosen before from the range [0,
nums.length - 1].
- Replace nums[i] with any integer from the range [nums[i] - k, nums[i] + k].

The beauty of the array is the length of the longest subsequence consisting of
equal elements.

Return the maximum possible beauty of the array nums after applying the
operation any number of times.

Note that you can apply the operation to each index only once.

A subsequence of an array is a new array generated from the original array by
deleting some elements (possibly none) without changing the order of the
remaining elements.



Example 1:
Input: nums = [4,6,1,2], k = 2
Output: 3
Explanation: In this example, we apply the following operations:
- Choose index 1, replace it with 4 (from range [4,8]), nums = [4,4,1,2].
- Choose index 3, replace it with 4 (from range [0,4]), nums = [4,4,1,4].
After the applied operations, the beauty of the array nums is 3 (subsequence
consisting of indices 0, 1, and 3). It can be proven that 3 is the maximum
possible length we can achieve.

Example 2:
Input: nums = [1,1,1,1], k = 10
Output: 4
Explanation: In this example we don't have to apply any operations.
The beauty of the array nums is 4 (whole array).


Constraints:
1 <= nums.length <= 10E5
0 <= nums[i], k <= 10E5 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Intuition:
/*The goal is to maximize the number of identical elements in a subsequence of
an array after modifying the elements within a specified range. To achieve this:

1. Key Observation: Each element nums[i] can be transformed into any value
within [nums[i] - k, nums[i] + k]. Thus, every number in this range becomes a
potential candidate for forming a longer subsequence.
2. Efficient Strategy: Use sorting and a sliding window to determine the maximum
number of elements that can fall within any contiguous range of length 2 * k
+ 1. */

// Approach
/*1. Sort the Array: Sorting helps us efficiently find contiguous ranges of
numbers that can be unified into one value after applying the operation.
2. Sliding Window Technique:
- For each number, maintain a window of numbers that can be transformed into the
same value.
- The window condition is: The difference between the smallest and largest
elements in the window should not exceed 2 * k.
- Update the maximum size of the window as you iterate through the array.*/

class Solution {
public:
  int maximumBeauty(vector<int>& nums, int k) {
    // Sort the array
    sort(nums.begin(), nums.end());

    int maxBeauty = 0;
    int left = 0; // Left pointer for the sliding window

    // Sliding window to count valid subsequence
    for (int right = 0; right < nums.size(); ++right) {
      // While the current range exceeds the allowed difference, move the left
      // pointer
      while (nums[right] - nums[left] > 2 * k) {
        ++left;
      }
      // Update maximum beauty
      maxBeauty = max(maxBeauty, right - left + 1);
    }

    return maxBeauty;
  }
};
/* Time Complexity:
Sorting the array takes
𝑂
(
𝑛
log
⁡
𝑛
)
O(nlogn).
The sliding window runs in
𝑂
(
𝑛
)
O(n) since each pointer moves at most
𝑛
n steps.
Total:
𝑂
(
𝑛
log
⁡
𝑛
)
O(nlogn).
Space Complexity:
Sorting uses
𝑂
(
𝑛
)
O(n) additional space (depending on the implementation).
Sliding window uses
𝑂
(
1
)
O(1) extra space.
Total:
𝑂
(
𝑛
)
O(n).*/

// more optimisation
/*further optimize the solution, we can leverage a more compact sliding window
approach with a direct comparison instead of recalculating the maximum
repeatedly. However, since the sliding window logic is already O(n) after
sorting, the focus will remain on minimizing operations during the traversal.

The following code maintains the same logic but avoids unnecessary comparisons
or redundant updates: */
class Solution2 {
public:
  int maximumBeauty(vector<int>& nums, int k) {
    // Sort the array to simplify finding contiguous ranges
    sort(nums.begin(), nums.end());

    int maxBeauty = 0;
    int left = 0; // Left pointer for the sliding window

    for (int right = 0; right < nums.size(); ++right) {
      // Adjust the window to ensure the difference is within 2 * k
      while (nums[right] - nums[left] > 2 * k) {
        ++left;
      }
      // The size of the current valid window is (right - left + 1)
      maxBeauty = max(maxBeauty, right - left + 1);
    }

    return maxBeauty;
  }
};

/*
- Time Complexity:
1. Sorting: $$O(nlogn)$$.
2. Sliding Window: $$O(n)$$, as each pointer traverses the array once.
- Total: $$O(nlogn)$$.
<br>
- Space Complexity:
1. Sorting uses $$O(n)$$ space for storage.
2. Sliding window uses $$O(1)$$ space.
- Total: $$O(n)$$.*/

int main() {
  Solution2 sol;

  // Test Case 1
  vector<int> nums1 = {4, 6, 1, 2};
  int k1 = 2;
  cout << "Test Case 1 Output: " << sol.maximumBeauty(nums1, k1) << endl;

  // Test Case 2
  vector<int> nums2 = {1, 1, 1, 1};
  int k2 = 10;
  cout << "Test Case 2 Output: " << sol.maximumBeauty(nums2, k2) << endl;

  return 0;
}
