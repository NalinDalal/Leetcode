/* 189. Rotate Array

Given an integer array nums, rotate the array to the right by k steps, where k
is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]


Constraints:
1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 10^5


Follow up:
Try to come up with as many solutions as you can. There are at least three
different ways to solve this problem. Could you do it in-place with O(1) extra
space?*/

// What to do->
// 1. divide the array into two parts, second part is from array.length() to
// array.length()-k, rest is first part
// 2. put the second part in front of first part
// 3.rest keep it as it is

// update i by i+2, but i+2 can get out of bound, so update i by
//(i+2)%array.length()

// 4. to update the array by k position-> (i+k)%array.length()

// alter o(1)->
// 1. first of all reverse the whole array
// then divide the array into 2 parts, 0 to k-1, k to array.length()
// and sort both the groups individually

#include <algorithm> // For std::swap
#include <iostream>
#include <vector>

using namespace std;

void printVector(const std::vector<int> &vec) {
  for (int num : vec) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

class Solution {
public:
  void rotate(std::vector<int> &nums, int k) {
    int n = nums.size();
    k = k % n; // Handle cases where k >= n

    // Step 1: Reverse the entire array
    int left = 0, right = n - 1;
    while (left < right) {
      std::swap(nums[left], nums[right]);
      left++;
      right--;
    }

    // Step 2: Reverse the first k elements
    left = 0;
    right = k - 1;
    while (left < right) {
      std::swap(nums[left], nums[right]);
      left++;
      right--;
    }

    // Step 3: Reverse the remaining n-k elements
    left = k;
    right = n - 1;
    while (left < right) {
      std::swap(nums[left], nums[right]);
      left++;
      right--;
    }
  }
};

int main() {
  vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
  int k1 = 3;
  vector<int> nums2 = {-1, -100, 3, 99};
  int k2 = 2;

  std::cout << "Array 1 b/f rotation: ";
  printVector(nums1);
  std::cout << "Position to rotate by: " << k1 << std::endl;
  Solution sol;
  sol.rotate(nums1, k1);
  std::cout << "Array 1 a/f rotation: ";
  printVector(nums1);

  std::cout << "Array 2 b/f rotation: ";
  printVector(nums2);
  std::cout << "Position to rotate by: " << k2 << std::endl;
  sol.rotate(nums2, k2);
  std::cout << "Array 2 a/f rotation: ";
  printVector(nums2);
  return 0;
}

// Time complexity:O(1)
// Space complexity:O(1)
