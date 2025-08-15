/*342. Power of Four
Given an integer n, return true if it is a power of four. Otherwise, return
false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

Example 1:
Input: n = 16
Output: true

Example 2:
Input: n = 5
Output: false


Example 3:
Input: n = 1
Output: true


Constraints:
-231 <= n <= 231 - 1


Follow up: Could you solve it without loops/recursion?
*/

class Solution {
public:
  bool isPowerOfFour(int n) {
    if (n <= 0)
      return false;

    double x = log(n) / log(4);
    // Check if x is close enough to an integer (to avoid floating point
    // precision issues)
    double diff = fabs(x - round(x));

    return diff < 1e-10; // true if x is essentially an integer
  }
};
// sub:
// https://leetcode.com/problems/power-of-four/submissions/1735522180/?envType=daily-question&envId=2025-08-15
// sol:
// https://leetcode.com/problems/power-of-four/solutions/7081991/342-power-of-four-by-nalindalal2004-1gfn/
