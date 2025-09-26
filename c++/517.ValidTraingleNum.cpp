/*611. Valid Triangle Number
Given an integer array nums, return the number of triplets chosen from the array
that can make triangles if we take them as side lengths of a triangle.



Example 1:
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are:
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3

Example 2:
Input: nums = [4,2,3,4]
Output: 4


Constraints:
1 <= nums.length <= 1000
0 <= nums[i] <= 1000
*/

// find triplets from array which make up the sides of a triangle
// condition for (a,b,c) to be triangle:
//   - a+b>c
//   - b+c>a
//   - c+a>b
// consider every triplet and check for the inequality condition
// if satisfy, count++
// atlast return count
// tle,😑

/*approach:
If you sort the array (nums), then for any triplet i < j < k:
    - The largest side is nums[k].
    - To form a valid triangle, we only need to check: `nums[i]+nums[j]>nums[k]`

If the sum of the two smaller sides is greater than the largest side, the other
two triangle inequalities automatically hold.

So instead of checking 3 inequalities, we just check one.
*/
class Solution {
public:
  int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // sort first
    int n = nums.size();
    int count = 0;

    // Fix the largest side nums[k]
    for (int k = n - 1; k >= 2; k--) {
      int i = 0, j = k - 1;

      while (i < j) {
        // use long long to avoid overflow
        if ((long long)nums[i] + (long long)nums[j] > (long long)nums[k]) {
          // All pairs between i..j-1 with j will work
          count += j - i;
          j--; // try smaller j
        } else {
          i++; // need bigger nums[i]
        }
      }
    }

    return count;
  }
};
// TIme: O(n^3)
// Space: O(1)
// sub:
// https://leetcode.com/problems/valid-triangle-number/submissions/1782934793/?envType=daily-question&envId=2025-09-26
// sol:
// https://leetcode.com/problems/valid-triangle-number/solutions/7224634/611-valid-triangle-number-by-nalindalal2-1wfq/
