/*2566. Maximum Difference by Remapping a Digit
You are given an integer num. You know that Bob will sneakily remap one of the
10 possible digits (0 to 9) to another digit.

Return the difference between the maximum and minimum values Bob can make by
remapping exactly one digit in num.

Notes:

When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of
d1 in num with d2. Bob can remap a digit to itself, in which case num does not
change. Bob can remap different digits for obtaining minimum and maximum values
respectively. The resulting number after remapping can contain leading zeroes.


Example 1:
Input: num = 11891
Output: 99009
Explanation:
To achieve the maximum value, Bob can remap the digit 1 to the digit 9 to yield
99899. To achieve the minimum value, Bob can remap the digit 1 to the digit 0,
yielding 890. The difference between these two numbers is 99009.

Example 2:
Input: num = 90
Output: 99
Explanation:
The maximum value that can be returned by the function is 99 (if 0 is replaced
by 9) and the minimum value that can be returned by the function is 0 (if 9 is
replaced by 0). Thus, we return 99.


Constraints:
1 <= num <= 108

Hint 1
Try to remap the first non-nine digit to 9 to obtain the maximum number.
Hint 2
Try to remap the first non-zero digit to 0 to obtain the minimum number.
*/

// take a digit, remap to another digit,
// find max and min digit possible after remapping
// return max - min
// convert to string, then greedy rules:
//- maximum value: scan from left to right to find the first digit that is not
//`'9'`, and replace all occurrences of that digit with `'9'`.
//- minimum value: scan from left to right to find the first digit that is not
//'0', and replace all occurrences of that digit with '0'.
//                   Since s[0] is guaranteed not to be '0', we can simply
//                   replace all occurrences of s[0] with '0'.
// return max-min
class Solution {
public:
  int minMaxDifference(int num) {
    string s = to_string(num);
    string t = s;
    size_t pos = s.find_first_not_of('9');
    if (pos != string::npos) {
      char a = s[pos];
      replace(s.begin(), s.end(), a, '9');
    }
    char b = t[0];
    replace(t.begin(), t.end(), b, '0');
    return stoi(s) - stoi(t);
  }
};
// sub:
// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/submissions/1663517694/?envType=daily-question&envId=2025-06-14
// Time: O(log num)
// Space: O(log num)
// sol:
// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/solutions/6841541/2566-maximum-difference-by-remapping-a-d-rcw2/
