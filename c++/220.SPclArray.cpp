/* https://leetcode.com/problems/special-array-i/description/?envType=daily-question&envId=2025-02-01
3151. Special Array I

An array is considered special if every pair of its adjacent elements contains
two numbers with different parity.

You are given an array of integers nums. Return true if nums is a special array,
otherwise, return false.


Example 1:
Input: nums = [1]
Output: true
Explanation: There is only one element. So the answer is true.

Example 2:
Input: nums = [2,1,4]
Output: true
Explanation:There is only two pairs: (2,1) and (1,4), and both of them contain
numbers with different parity. So the answer is true.

Example 3:
Input: nums = [4,3,1,6]
Output: false
Explanation:nums[1] and nums[2] are both odd. So the answer is false.


Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100
*/
class Solution {
public:
  bool isArraySpecial(vector<int>& nums) {
    // if adjacent element are diff parity then array is special
    // else not
    if (nums.size() == 1) {
      return true;
    }
    for (int i = 0; i < nums.size() - 1; i++) {
      if ((nums[i] % 2) == (nums[i + 1] % 2))
        return false;
    }
    return true;
  }
};

// Time: O(n)
// Space: O(1)
// sub:
// https://leetcode.com/problems/special-array-i/submissions/1527265960/?envType=daily-question&envId=2025-02-01
// sol:
// https://leetcode.com/problems/special-array-i/solutions/6356244/3151-special-array-i100-by-nalindalal200-p2s4/
