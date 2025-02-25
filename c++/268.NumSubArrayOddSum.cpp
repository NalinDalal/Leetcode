/* 1524. Number of Sub-arrays With Odd Sum

Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 109 + 7.


Example 1:
Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.

Example 2:
Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.

Example 3:
Input: arr = [1,2,3,4,5,6,7]
Output: 16


Constraints:
1 <= arr.length <= 105
1 <= arr[i] <= 100*/

class Solution {
public:
  int numOfSubarrays(vector<int>& arr) {
    // create a 2d empty vector
    // subarray-contiguous part of array
    // make a function to get subarray
    // now check the sum of subaaray is even or not
    // if even then push to dp
    int oddCount = 0, evenCount = 1; // evenCount = 1 for empty subarray
    int sum = 0, result = 0;
    int mod = 1e9 + 7;

    for (int num : arr) {
      sum += num;

      if (sum % 2 == 0) {
        result = (result + oddCount) % mod;
        evenCount++;
      } else {
        result = (result + evenCount) % mod;
        oddCount++;
      }
    }

    return result;
  }
};
// Time: O(n)
// Space: O(1)
//  sub:
//  https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/submissions/1554441702/?envType=daily-question&envId=2025-02-25
//  sol:
//  https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/solutions/6464513/1524-number-of-sub-arrays-with-odd-sum-b-m1mc/
