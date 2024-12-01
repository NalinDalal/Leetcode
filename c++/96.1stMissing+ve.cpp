/* 41. First Missing Positive

Given an unsorted integer array nums. Return the smallest positive integer that
is not present in nums. You must implement an algorithm that runs in O(n) time
and uses O(1) auxiliary space.


Example 1:
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.


Constraints:
1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1*/

/*
    1.Key Idea:
- Use the array itself as a hash map by placing each positive integer x (where 1
<= x <= n, and n is the size of the array) in its "correct" index: at position
x-1.

2. Why Does This Work?
- If all positive integers up to n are in their correct positions, the first
index where the value is incorrect or missing identifies the smallest missing
positive number.

3. Algorithm Steps:

- Rearrange the array to ensure every positive number x is in its correct
position x - 1 (if possible).
- Iterate through the rearranged array to find the first index where the value
is not index + 1.*/

// Time Complexity: O(n) — Each element is moved at most once.
// Space Complexity: O(1) — In-place rearrangement.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();

    // Step 1: Place each number in its correct position
    for (int i = 0; i < n; i++) {
      while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
        swap(nums[i], nums[nums[i] - 1]);
      }
    }

    // Step 2: Find the first missing positive
    for (int i = 0; i < n; i++) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }

    // If all are in place, the missing number is n + 1
    return n + 1;
  }
};

int main() {
  Solution s;
  vector<int> nums1 = {1, 2, 0};
  cout << "Test Case 1: " << nums1 << " -> " << s.firstMissingPositive(nums1)
       << endl;
  vector<int> nums2 = {13, 4, -1, 13};
  cout << "Test Case 2: " << nums2 << " ->" << s.firstMissingPositive(nums2)
       << endl;
  vector<int> nums3 = {17, 8, 9, 11, 125};
  cout << "Test Case 3: " << nums3 << " ->" << s.firstMissingPositive(nums3)
       << endl;
  return 0;
}
