/*2749. Minimum Operations to Make the Integer Zero
You are given two integers num1 and num2.

In one operation, you can choose integer i in the range [0, 60] and subtract 2i
+ num2 from num1.

Return the integer denoting the minimum number of operations needed to make num1
equal to 0.

If it is impossible to make num1 equal to 0, return -1.



Example 1:

Input: num1 = 3, num2 = -2
Output: 3
Explanation: We can make 3 equal to 0 with the following operations:
- We choose i = 2 and subtract 22 + (-2) from 3, 3 - (4 + (-2)) = 1.
- We choose i = 2 and subtract 22 + (-2) from 1, 1 - (4 + (-2)) = -1.
- We choose i = 0 and subtract 20 + (-2) from -1, (-1) - (1 + (-2)) = 0.
It can be proven, that 3 is the minimum number of operations that we need to
perform. Example 2:

Input: num1 = 5, num2 = 7
Output: -1
Explanation: It can be proven, that it is impossible to make 5 equal to 0 with
the given operation.


Constraints:

1 <= num1 <= 109
-109 <= num2 <= 109


Hint 1
If we want to make integer n equal to 0 by only subtracting powers of 2 from n,
in how many operations can we achieve it? Hint 2 We need at least - the number
of bits in the binary representation of n, and at most - n. Hint 3 Notice that,
if it is possible to make num1 equal to 0, then we need at most 60 operations.
Hint 4
Iterate on the number of operations.
*/

// choose i b/w [0,60], num1-(num2+pow(2,i))
// return min opr to make num1=0
// else return -1
// let k be ans
// S be the sum of powers of 2 chosen
// s=(2^{i1} + 2^{i2} + ... + 2^{ik})
// after k opr: num1 = k*num2 + S
// S>=k and S<=sum of k largest pow<= 2^61 -1
// finding minimum k such that num1 - k*num2 can be represented as the sum of k
// distinct powers of 2.

/*for k=1 to 60:
1. Compute x = num1 - k*num2.

2. If x < k, impossible (sum of k distinct positive integers ≥ k).

3. If x has number of 1s in binary ≤ k → possible, return k.
    */

class Solution {
public:
  int makeTheIntegerZero(int num1, int num2) {
    for (int k = 1; k <= 60; ++k) {
      long long x = (long long)num1 - (long long)k * num2;
      if (x < k)
        continue; // can't represent as sum of k distinct powers of 2
      int ones = __builtin_popcountll(x);
      if (ones <= k)
        return k;
    }
    return -1;
  }
};
// sub:
// https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/submissions/1760029646/?envType=daily-question&envId=2025-09-05
// sol:
// https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/solutions/7157044/2749-minimum-operations-to-make-the-inte-t23n/
