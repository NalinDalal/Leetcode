/*191. Number of 1 Bits

Given a positive integer n, write a function that returns the number of set bits
in its binary representation (also known as the Hamming weight).



Example 1:
Input: n = 11
Output: 3
Explanation:The input binary string 1011 has a total of three set bits.

Example 2:
Input: n = 128
Output: 1
Explanation:The input binary string 10000000 has a total of one set bit.

Example 3:
Input: n = 2147483645
Output: 30
Explanation:The input binary string 1111111111111111111111111111101 has a total
of thirty set bits.


Constraints:1 <= n <= 231 - 1
Follow up: If this function is called many times, how would you optimize it?*/

class Solution {
public:
  int hammingWeight(int n) {
    // find binary representation of n
    // convert to string
    // count no of 1 in string
    // return count
    int count = 0;
    // Convert integer to its binary representation
    string binary = bitset<32>(n).to_string();

    // Count number of '1' bits
    for (char bit : binary) {
      if (bit == '1') {
        count++;
      }
    }

    return count;
  }
};

// sub: https://leetcode.com/problems/number-of-1-bits/submissions/1566731371/
// sol:
// https://leetcode.com/problems/number-of-1-bits/solutions/6512204/191-number-of-1-bits-by-nalindalal2004-5unl/
