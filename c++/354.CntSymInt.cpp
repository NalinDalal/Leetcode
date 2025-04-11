/* 2843. Count Symmetric Integers
You are given two positive integers low and high.

An integer x consisting of 2 * n digits is symmetric if the sum of the first n
digits of x is equal to the sum of the last n digits of x. Numbers with an odd
number of digits are never symmetric.

Return the number of symmetric integers in the range [low, high].

Example 1:
Input: low = 1, high = 100
Output: 9
Explanation: There are 9 symmetric integers between 1 and 100: 11, 22, 33, 44,
55, 66, 77, 88, and 99.

Example 2:
Input: low = 1200, high = 1230
Output: 4
Explanation: There are 4 symmetric integers between 1200 and 1230: 1203, 1212,
1221, and 1230.


Constraints:
1 <= low <= high <= 104

Hint 1: Iterate over all numbers from low to high
Hint 2: Convert each number to a string and compare the sum of the first half
with that of the second.
*/

// int x
// x.toStr();
// int 2*n=x.size();
// for(int i=0;i<n/2;) {if(x[i]==x[n-i]) i++; else brk;}
// if reach n/2 count++
// return count
class Solution {
public:
  int countSymmetricIntegers(int low, int high) {
    int count = 0;

    for (int x = low; x <= high; ++x) {
      string s = to_string(x);
      int len = s.size();

      // Only consider even-length numbers
      if (len % 2 != 0)
        continue;

      int half = len / 2;
      int sum1 = 0, sum2 = 0;

      for (int i = 0; i < half; ++i) {
        sum1 += s[i] - '0';
        sum2 += s[i + half] - '0';
      }

      if (sum1 == sum2) {
        count++;
      }
    }

    return count;
  }
};
// sub:
// https://leetcode.com/problems/count-symmetric-integers/submissions/1603228866/?envType=daily-question&envId=2025-04-11
// sol:
// https://leetcode.com/problems/count-symmetric-integers/solutions/6638140/2843-count-symmetric-integers-by-nalinda-w38p/
