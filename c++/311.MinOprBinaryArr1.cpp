/*3191. Minimum Operations to Make Binary Array Elements Equal to One I

You are given a binary array nums.

You can do the following operation on the array any number of times (possibly
zero):

Choose any 3 consecutive elements from the array and flip all of them.
Flipping an element means changing its value from 0 to 1, and from 1 to 0.

Return the minimum number of operations required to make all elements in nums
equal to 1. If it is impossible, return -1.



Example 1:
Input: nums = [0,1,1,1,0,0]
Output: 3
Explanation:
We can do the following operations:
Choose the elements at indices 0, 1 and 2. The resulting array is nums =
[1,0,0,1,0,0]. Choose the elements at indices 1, 2 and 3. The resulting array is
nums = [1,1,1,0,0,0]. Choose the elements at indices 3, 4 and 5. The resulting
array is nums = [1,1,1,1,1,1].

Example 2:
Input: nums = [0,1,1,1]
Output: -1
Explanation:It is impossible to make all elements equal to 1.


Constraints:
3 <= nums.length <= 105
0 <= nums[i] <= 1
*/

// use sliding window
// u encounter 0, flip it and next 2 also
// keep track no of flips
// If there's a 0 left in the last two elements (where flipping is no longer
// possible), return -1.

class Solution {
public:
  int minOperations(vector<int>& nums) {
    int flips = 0;
    int n = nums.size();

    for (int i = 0; i <= n - 3; i++) {
      if (nums[i] == 0) {
        // Flip current element and next two
        nums[i] ^= 1;
        nums[i + 1] ^= 1;
        nums[i + 2] ^= 1;
        flips++;
      }
    }

    // Check if last two elements contain a 0, making it impossible
    for (int i = n - 2; i < n; i++) {
      if (i >= 0 && nums[i] == 0)
        return -1;
    }

    return flips;
  }
};
// sub:
// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/submissions/1578699373/?envType=daily-question&envId=2025-03-19
// sol:
// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/solutions/6554078/3191-minimum-operations-to-make-binary-a-ql6r/
