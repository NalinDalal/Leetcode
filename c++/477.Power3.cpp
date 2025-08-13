/*326. Power of Three
Given an integer n, return true if it is a power of three. Otherwise, return
false.

An integer n is a power of three, if there exists an integer x such that n ==
3x.



Example 1:

Input: n = 27
Output: true
Explanation: 27 = 33
Example 2:

Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.
Example 3:

Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).


Constraints:

-231 <= n <= 231 - 1


Follow up: Could you solve it without loops/recursion?
*/

// find if there exists an integer x such that n=pow(3,x)
// i.e. to find x=log3(n)
// x=log(n)/log(3)
// if it's a whole no or integer greater than 0 then yes
// else return false

class Solution {
public:
  bool isPowerOfThree(int n) {
    if (n <= 0)
      return false;

    double x = log(n) / log(3);
    // Check if x is close enough to an integer (to avoid floating point
    // precision issues)
    double diff = fabs(x - round(x));

    return diff < 1e-10; // true if x is essentially an integer
  }
};
// sub:
// https://leetcode.com/problems/power-of-three/submissions/1733184790/?envType=daily-question&envId=2025-08-13
// sol:
// https://leetcode.com/problems/power-of-three/solutions/7073579/326-power-of-three-by-nalindalal2004-4mj7/
