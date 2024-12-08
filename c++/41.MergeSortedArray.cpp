/*
88. Merge Sorted Array

You are given two integer arrays nums1 and nums2, sorted in non-decreasing
order, and two integers m and n, representing the number of elements in nums1
and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be
stored inside the array nums1. To accommodate this, nums1 has a length of m + n,
where the first m elements denote the elements that should be merged, and the
last n elements are set to 0 and should be ignored. nums2 has a length of n.



Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming
from nums1. Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to
ensure the merge result can fit in nums1.


Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
*/

// Intuition
/*
 m - 1st array me jaha tak element h
length array1=m+n
n - length of 2nd array
array1.delete(m+1 , array1.length)
append nums2 into nums1
nums1.sort()
return nums1
*/

// Approach
/*
1. Resize nums1: Ensure that nums1 has enough space to accommodate both arrays
(m + n).
2. Merge nums2: Use std::copy to append elements from nums2 starting from index
m in nums1.
3. Sort nums1: Although both arrays are sorted, to ensure nums1 is sorted after
merging, std::sort is called. However, note that this step might be unnecessary
if you're sure nums1 is already sorted.
*/

// Time complexity:O(m+n)

// Space complexity:O(m+n)

// it motherfucking ran on first dry run itself
class Solution {
public:
  void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    // Resize nums1 to accommodate both arrays
    nums1.resize(m + n);

    // Merge nums2 into nums1
    std::copy(nums2.begin(), nums2.end(), nums1.begin() + m);

    // Sort nums1 (since both arrays are already sorted, this merge is
    // unnecessary)
    std::sort(nums1.begin(), nums1.end());
  }
};
