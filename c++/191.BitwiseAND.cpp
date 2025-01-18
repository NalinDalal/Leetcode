/* https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=study-plan-v2&envId=top-interview-150

201. Bitwise AND of Numbers Range

Given two integers left and right that represent the range [left, right], return
the bitwise AND of all numbers in this range, inclusive.


Example 1:
Input: left = 5, right = 7
Output: 4

Example 2:
Input: left = 0, right = 0
Output: 0

Example 3:
Input: left = 1, right = 2147483647
Output: 0


Constraints:
0 <= left <= right <= 231 - 1*/

class solution {
public:
  int rangebitwiseand(int left, int right) {
    int ans = 0;
    while (left <= right) {
      ans = ans & left;
      left++;
    }
    return ans;
  }
};

// gives tle

// optimised:
class Solution1 {
public:
  int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    // Find common prefix by shifting right until left equals right
    while (left < right) {
      left >>= 1;
      right >>= 1;
      shift++;
    }
    // Left and right are equal, shift back to the original position
    return left << shift;
  }
};
// 100%
//  sub:
//  https://leetcode.com/problems/bitwise-and-of-numbers-range/submissions/1512450863/
//  sol:
//  https://leetcode.com/problems/bitwise-and-of-numbers-range/solutions/6298601/201-bitwise-and-of-numbers-range100-by-n-mebi/
