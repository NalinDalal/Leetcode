/*1323. Maximum 69 Number

You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes
9, and 9 becomes 6).



Example 1:

Input: num = 9669
Output: 9969
Explanation:
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.
Example 2:

Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.
Example 3:

Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.


Constraints:

1 <= num <= 104
num consists of only 6 and 9 digits.

Hint 1
Convert the number in an array of its digits.
Hint 2
Brute force on every digit to get the maximum number.
*/

// traverse the number digit by digit
// change the 6 to 9 and 9 to 6,
// store the new num and compare with previous one, find max b/w both
// move to next digit index
// return max atlast
class Solution {
public:
  int maximum69Number(int num) {
    string s = to_string(num);
    int ans = num;

    for (int i = 0; i < (int)s.size(); i++) {
      char original = s[i];

      if (s[i] == '6')
        s[i] = '9';
      else if (s[i] == '9')
        s[i] = '6';

      int val = stoi(s);
      ans = max(ans, val);

      s[i] = original; // restore for next iteration
    }

    return ans;
  }
};
// sub:
// https://leetcode.com/problems/maximum-69-number/submissions/1736779673/?envType=daily-question&envId=2025-08-16
// sol:
// https://leetcode.com/problems/maximum-69-number/solutions/7086394/1323-maximum-69-number-by-nalindalal2004-6nqr/
