/*
962. Maximum Width Ramp

A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <=
nums[j]. The width of such a ramp is j - i. Given an integer array nums, return
the maximum width of a ramp in nums. If there is no ramp in nums, return 0.



Example 1:
Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0
and nums[5] = 5.

Example 2:
Input: nums = [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1
and nums[9] = 1.


Constraints:
2 <= nums.length <= 5 * 10^4
0 <= nums[i] <= 5 * 10^4
*/

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  int maxWidthRamp(vector<int>& nums) {
    int maxWidth = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 1; j < nums.size() + 1; j++) {
        if (nums[i] <= nums[j]) {
          int width = j - i;
          maxWidth = max(maxWidth, width);
        }
      }
    }
    return maxWidth;
  }
};

// Note it is correct approach, but gives run time error
// 1. The inner loop (for(int j = 1; j < nums.size() + 1; j++)) goes out of
// bounds since nums[j] will access an invalid index when j == nums.size()
// 2. O(n^2) time complexity

// Optimisation:
// 1. Create a Monotonic Stack: Traverse the array and keep a stack of indices
// where the elements in nums are in decreasing order. These indices are
// potential starting points for ramps.

// 2. Traverse Backwards: Starting from the end of the array, attempt to find
// the largest width by popping indices from the stack where
// nums[stack.top()]≤nums[j].

class Solution2 {
public:
  int maxWidthRamp2(vector<int>& nums) {
    stack<int> decreasingIndices;
    int n = nums.size();

    // Build a stack of indices with decreasing elements
    for (int i = 0; i < n; i++) {
      if (decreasingIndices.empty() ||
          nums[decreasingIndices.top()] > nums[i]) {
        decreasingIndices.push(i);
      }
    }

    int maxWidth = 0;

    // Traverse the array from the end to find the maximum width
    for (int j = n - 1; j >= 0; j--) {
      while (!decreasingIndices.empty() &&
             nums[decreasingIndices.top()] <= nums[j]) {
        maxWidth = max(maxWidth, j - decreasingIndices.top());
        decreasingIndices.pop();
      }
    }

    return maxWidth;
  }
};

// time complexity: O(n)
// space complexity: O(n)

// Utility function to print a vector
void printVector(const vector<int>& nums) {
  cout << "[";
  for (size_t i = 0; i < nums.size(); i++) {
    cout << nums[i];
    if (i < nums.size() - 1)
      cout << ", ";
  }
  cout << "]";
}

int main() {
  Solution2 sol;
  vector<int> nums1 = {6, 0, 8, 2, 1, 5};
  int result = sol.maxWidthRamp2(nums1);
  cout << "Nums1: ";
  printVector(nums1);
  cout << "result: " << result << endl;
  // Output: 4 (Ramp between indices 1 and 5)

  vector<int> nums2 = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
  int result2 = sol.maxWidthRamp2(nums2);
  cout << "Nums2: ";
  printVector(nums2);
  cout << "result: " << result2 << endl;
  // Output: 7(Tamp b/w indices 2 and 9)
  return 0;
}
