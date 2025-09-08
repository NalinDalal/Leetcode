/*1317. Convert Integer to the Sum of Two No-Zero Integers
No-Zero integer is a positive integer that does not contain any 0 in its decimal
representation.

Given an integer n, return a list of two integers [a, b] where:

a and b are No-Zero integers.
a + b = n
The test cases are generated so that there is at least one valid solution. If
there are many valid solutions, you can return any of them.



Example 1:
Input: n = 2
Output: [1,1]
Explanation: Let a = 1 and b = 1.
Both a and b are no-zero integers, and a + b = 2 = n.

Example 2:
Input: n = 11
Output: [2,9]
Explanation: Let a = 2 and b = 9.
Both a and b are no-zero integers, and a + b = 11 = n.
Note that there are other valid answers as [8, 3] that can be accepted.


Constraints:
2 <= n <= 104

Hint 1
Loop through all elements from 1 to n.
Hint 2
Choose A = i and B = n - i then check if A and B are both No-Zero integers.
*/

// intuition: though of halving and pushing into a vector, but wrong
// approach: Loop through all elements from 1 to n; Choose A = i and B = n - i
// then check if A and B are both No-Zero integers.
/*1. Loop i from 1 to n-1.
    - Let A = i, B = n - i.

2. Write a helper function bool isNoZero(int x) that checks if x has any digit
0.
    - Use modulo and division to check each digit.

3. If both A and B pass the check, return {A, B}.
    */
class Solution {
public:
  vector<int> getNoZeroIntegers(int n) {
    for (int i = 1; i < n; i++) {
      int a = i, b = n - i;
      if (isNoZero(a) && isNoZero(b)) {
        return {a, b};
      }
    }
    return {}; // should never hit
  }

private:
  bool isNoZero(int x) {
    while (x > 0) {
      if (x % 10 == 0)
        return false;
      x /= 10;
    }
    return true;
  }
};
// sub:
// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/submissions/1763230348/?envType=daily-question&envId=2025-09-08
// sol:
// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/solutions/7167137/1317-convert-integer-to-the-sum-of-two-n-7mop/
