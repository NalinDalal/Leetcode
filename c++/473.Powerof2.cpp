/*231. Power of Two

Given an integer n, return true if it is a power of two. Otherwise, return
false.

An integer n is a power of two, if there exists an integer x such that n == 2^x.



Example 1:
Input: n = 1
Output: true
Explanation: 2^0 = 1

Example 2:
Input: n = 16
Output: true
Explanation: 2^4 = 16

Example 3:
Input: n = 3
Output: false


Constraints:
-2^31 <= n <= 2^31 - 1


Follow up: Could you solve it without loops/recursion?

*/

class Solution {
public:
  bool isPowerOfTwo(int n) {
    // find log n to base 2
    // if it is a integer then return true

    // log2(x) -> find log of x to base 2

    // more clean approach:
    return n > 0 && (n & (n - 1)) == 0;
  }
};

// sub:
// https://leetcode.com/problems/power-of-two/submissions/1728579386/?envType=daily-question&envId=2025-08-09
// sol:
// https://leetcode.com/problems/power-of-two/solutions/7059789/231-power-of-two-by-nalindalal2004-fv57/
