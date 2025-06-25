/* 2040. Kth Smallest Product of Two Sorted Arrays
Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer
k, return the kth (1-based) smallest product of nums1[i] * nums2[j] where 0 <= i
< nums1.length and 0 <= j < nums2.length.


Example 1:

Input: nums1 = [2,5], nums2 = [3,4], k = 2
Output: 8
Explanation: The 2 smallest products are:
- nums1[0] * nums2[0] = 2 * 3 = 6
- nums1[0] * nums2[1] = 2 * 4 = 8
The 2nd smallest product is 8.
Example 2:

Input: nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
Output: 0
Explanation: The 6 smallest products are:
- nums1[0] * nums2[1] = (-4) * 4 = -16
- nums1[0] * nums2[0] = (-4) * 2 = -8
- nums1[1] * nums2[1] = (-2) * 4 = -8
- nums1[1] * nums2[0] = (-2) * 2 = -4
- nums1[2] * nums2[0] = 0 * 2 = 0
- nums1[2] * nums2[1] = 0 * 4 = 0
The 6th smallest product is 0.
Example 3:

Input: nums1 = [-2,-1,0,1,2], nums2 = [-3,-1,2,4,5], k = 3
Output: -6
Explanation: The 3 smallest products are:
- nums1[0] * nums2[4] = (-2) * 5 = -10
- nums1[0] * nums2[3] = (-2) * 4 = -8
- nums1[4] * nums2[0] = 2 * (-3) = -6
The 3rd smallest product is -6.


Constraints:

1 <= nums1.length, nums2.length <= 5 * 104
-105 <= nums1[i], nums2[j] <= 105
1 <= k <= nums1.length * nums2.length
nums1 and nums2 are sorted.


Hint 1
Can we split this problem into four cases depending on the sign of the numbers?
Hint 2
Can we binary search the value?
*/

// so basically take arr1, and arr2, find their product of each element with
// other element sort the array, return kth element tle

// Approach:
/* value range of nums1[i]*nums2[j] is [-10E10, 10E10]
 do a binary search to find the k-th smallest product.
count no of elmeent <=v

use binary search to find this count:
for each x1 in nums1:
    if x1 == 0:
        if v >= 0:
            count += size of nums2
        else:
            count += 0

    else if x1 > 0:
        // Binary search to find rightmost index j where x1 * nums2[j] ≤ v
        l = 0, r = size of nums2
        while l < r:
            m = (l + r) / 2
            if x1 * nums2[m] <= v:
                l = m + 1
            else:
                r = m
        count += l

    else:
        // x1 < 0
        // Binary search to find leftmost index j where x1 * nums2[j] ≤ v
        l = 0, r = size of nums2
        while l < r:
            m = (l + r) / 2
            if x1 * nums2[m] <= v:
                r = m
            else:
                l = m + 1
        count += (size of nums2 - l)

count is ans;Summing these counts for all elements in nums1
  gives the total number of products less than or equal to v.
*/

class Solution {
public:
  int f(vector<int>& nums2, long long x1, long long v) {
    int n2 = nums2.size();
    int left = 0, right = n2 - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (x1 >= 0 && nums2[mid] * x1 <= v || x1 < 0 && nums2[mid] * x1 > v) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (x1 >= 0) {
      return left;
    } else {
      return n2 - left;
    }
  }

  long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                               long long k) {
    int n1 = nums1.size();
    long long left = -1e10, right = 1e10;
    while (left <= right) {
      long long mid = (left + right) / 2;
      long long count = 0;
      for (int i = 0; i < n1; i++) {
        count += f(nums2, nums1[i], mid);
      }
      if (count < k) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return left;
  }
};
// sub:
// https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/submissions/1675592382/?envType=daily-question&envId=2025-06-25
// sol:
// https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/solutions/6882766/2040-kth-smallest-product-of-two-sorted-5ydic/
