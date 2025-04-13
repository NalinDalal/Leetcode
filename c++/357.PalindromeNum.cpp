/*9. Palindrome Number
Given an integer x, return true if x is a palindrome, and false otherwise.



Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes
121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.


Constraints:
-231 <= x <= 231 - 1*/

// check if a num is palindrome or not
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false; // negative numbers can't be palindromes

    int n = x;
    long long sum = 0;
    while (n > 0) {
      sum = sum * 10 + n % 10;
      n = n / 10;
    }

    return sum == x;
  }
};

// sub:
// https://leetcode.com/problems/palindrome-number/submissions/1605351140/?envType=study-plan-v2&envId=top-interview-150
// sol:
// https://leetcode.com/problems/palindrome-number/solutions/6645490/9-palindrome-number-by-nalindalal2004-fmgc/
