/*7. Reverse Integer
Given a signed 32-bit integer x, return x with its digits reversed. If reversing
x causes the value to go outside the signed 32-bit integer range [-231, 231 -
1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or
unsigned).


Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21


Constraints: -231 <= x <= 231 - 1
*/

// convert to string and reverse, make sure to account for -ve no.
// for -ve no use abs(), convert to positive, reverse, then convert back to
// negative
class Solution {
public:
  int reverse(int x) {
    long long num = x; // Use long long to prevent overflow
    bool isNegative = (num < 0);

    if (isNegative) {
      num = -num; // Convert to positive safely
    }

    std::string str = std::to_string(num);
    std::reverse(str.begin(), str.end());

    long long reversed = std::stoll(str); // Use long long to check overflow

    if (reversed > std::numeric_limits<int>::max()) {
      return 0; // Return 0 if overflow occurs
    }

    return isNegative ? -reversed : reversed;
  }
};
// Time: O(n)
// Space: O(1)
// sub: https://leetcode.com/problems/reverse-integer/submissions/1578667933/
// sol:
// https://leetcode.com/problems/reverse-integer/solutions/6553948/7-reverse-integer-by-nalindalal2004-aaij/
