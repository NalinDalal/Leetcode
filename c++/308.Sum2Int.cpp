/*371. Sum of Two Integers
Given two integers a and b, return the sum of the two integers without using the
operators + and -.

Example 1:
Input: a = 1, b = 2
Output: 3

Example 2:
Input: a = 2, b = 3
Output: 5


Constraints:-1000 <= a, b <= 1000*/

// Approach
/* 1. Compute the sum without carry using a ^ b (XOR).
- This acts like regular addition but ignores carry.
2. Compute the carry using (a & b) << 1.
    - This detects bits where both a and b are 1, indicating a carry.
    - We shift it left by 1 to add it to the next higher bit.
3. Iterate until there is no carry (y != 0):
    - Store the new carry in car = (x & y) << 1.
    - Update the sum x = x ^ y.
    - Repeat until y (carry) becomes 0, meaning there’s nothing left to add.
4. Return x as the final sum.
    */
class Solution {
public:
  int getSum(int a, int b) {
    int x = a ^ b;
    // xor for sum
    int y = (a & b) << 1;
    // & for carry
    while (y != 0) {
      int car = (x & y) << 1;
      x = x ^ y;
      y = car;
    }
    return x;
  }
};
// Sub:
// https://leetcode.com/problems/sum-of-two-integers/submissions/1577491342/
// sol:
// https://leetcode.com/problems/sum-of-two-integers/solutions/6549813/371-sum-of-two-integers-by-nalindalal200-5brn/

// Time: O(log N)
// Space: O(1)
