/*166. Fraction to Recurring Decimal
Given two integers representing the numerator and denominator of a fraction,
return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 104 for all
the given inputs.



Example 1:
Input: numerator = 1, denominator = 2
Output: "0.5"

Example 2:
Input: numerator = 2, denominator = 1
Output: "2"

Example 3:
Input: numerator = 4, denominator = 333
Output: "0.(012)"


Constraints:
-231 <= numerator, denominator <= 231 - 1
denominator != 0


Hint 1
No scary math, just apply elementary math knowledge. Still remember how to
perform a long division? Hint 2 Try a long division on 4/9, the repeating part
is obvious. Now try 4/333. Do you see a pattern? Hint 3 Notice that once the
remainder starts repeating, so does the divided result. Hint 4 Be wary of edge
cases! List out as many test cases as you can think of and test your code
thoroughly.
*/

// divide numerator with denominator
// if it divides perfectly then return result in string format
// else if not, find the recurring part and enclose in parentheses as
// required
// return the result
// for decimal part-> Multiply the remainder by 10 each step.
// Divide by denominator to get the next digit.
// Update the remainder. keep track via map
class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0)
      return "0";

    string result;

    // Handle sign
    if ((numerator < 0) ^ (denominator < 0))
      result += "-";

    // Use long long to avoid overflow
    long long n = llabs((long long)numerator);
    long long d = llabs((long long)denominator);

    // Integral part
    result += to_string(n / d);
    long long remainder = n % d;
    if (remainder == 0)
      return result; // no fractional part

    result += ".";

    // Map remainder -> position in result string
    unordered_map<long long, int> seen;

    while (remainder) {
      if (seen.count(remainder)) {
        // repeating remainder found
        result.insert(seen[remainder], "(");
        result += ")";
        break;
      }
      seen[remainder] = result.size();

      remainder *= 10;
      result += to_string(remainder / d);
      remainder %= d;
    }

    return result;
  }
};

// sub:
// https://leetcode.com/problems/fraction-to-recurring-decimal/submissions/1780864250/?envType=daily-question&envId=2025-09-24
// sol:
// https://leetcode.com/problems/fraction-to-recurring-decimal/solutions/7219038/166-fraction-to-recurring-decimal-by-nal-svxf/
