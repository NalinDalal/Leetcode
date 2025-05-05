/* 790. Domino and Tromino Tiling
You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may
rotate these shapes.

Given an integer n, return the number of ways to tile an 2 x n board. Since the
answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different
if and only if there are two 4-directionally adjacent cells on the board such
that exactly one of the tilings has both squares occupied by a tile.


Example 1:
Input: n = 3
Output: 5
Explanation: The five different ways are show above.

Example 2:
Input: n = 1
Output: 1


Constraints: 1 <= n <= 1000
*/

class Solution {
public:
  const int mod = 1e9 + 7;
  int numTilings(int n) {

    // n given, so 2*n chips are there
    // now how many ways they can be arranged into domino and tromino
    // domino-> 2 chips
    // tromino->3 chips in L shape

    // use recusrion
    // a[n]=2a[n−1]+a[n−3] for n>=3
    // a[0]=1 when n=0
    array<int, 3> a = {1, 1, 2};
    if (n < 3)
      return a[n];
    for (int i = 3; i <= n; i++) {
      long long x = (2LL * a[2] + a[0]) % mod;
      a = {a[1], a[2], (int)x};
    }
    return a[2];
  }
};

/*1->1
2->2
3->5
4->11
5->24*/

// sub:
// https://leetcode.com/problems/domino-and-tromino-tiling/submissions/1625823396/?envType=daily-question&envId=2025-05-05
