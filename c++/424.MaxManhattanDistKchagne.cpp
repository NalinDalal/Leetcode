/* 3443. Maximum Manhattan Distance After K Changes
You are given a string s consisting of the characters 'N', 'S', 'E', and 'W',
where s[i] indicates movements in an infinite grid:

'N' : Move north by 1 unit.
'S' : Move south by 1 unit.
'E' : Move east by 1 unit.
'W' : Move west by 1 unit.
Initially, you are at the origin (0, 0). You can change at most k characters to
any of the four directions.

Find the maximum Manhattan distance from the origin that can be achieved at any
time while performing the movements in order.

The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| +
|yi - yj|.


Example 1:

Input: s = "NWSE", k = 1

Output: 3

Explanation:

Change s[2] from 'S' to 'N'. The string s becomes "NWNE".

Movement	Position (x, y)	Manhattan Distance	Maximum
s[0] == 'N'	(0, 1)	0 + 1 = 1	1
s[1] == 'W'	(-1, 1)	1 + 1 = 2	2
s[2] == 'N'	(-1, 2)	1 + 2 = 3	3
s[3] == 'E'	(0, 2)	0 + 2 = 2	3
The maximum Manhattan distance from the origin that can be achieved is 3. Hence,
3 is the output.

Example 2:

Input: s = "NSWWEW", k = 3

Output: 6

Explanation:

Change s[1] from 'S' to 'N', and s[4] from 'E' to 'W'. The string s becomes
"NNWWWW".

The maximum Manhattan distance from the origin that can be achieved is 6. Hence,
6 is the output.



Constraints:

1 <= s.length <= 105
0 <= k <= s.length
s consists of only 'N', 'S', 'E', and 'W'.



Hint 1
We can brute force all the possible directions (NE, NW, SE, SW).
Hint 2
Change up to k characters to maximize the distance in the chosen direction.
*/

// intuition:
/* dist=abs(sum[N]-sum[S])+abs(sum[E]-sum[W])
sum[N],sum[S],sum[E],sum[W] are occurences of N,S,W,E in string s
when modifying 3 cases are possible:
1. Modifying the letters that appear less frequently (but are not zero) in
either the horizontal or vertical direction increases the Manhattan distance
by 2.
2. Modifying the letters that appear more frequently in either direction
decreases the Manhattan distance by 2.
3. If no modifications are made, the Manhattan distance remains unchanged.

only 1st case increase the distance, so modification process in 2 phases:
1. Modify the letters with fewer occurrences in the vertical direction. If the
number of such letters >`k`, then modify only `k` of them, and set the remaining
modification count to `t=0`. If the number of such letters <= `k`, then modify
all of them and set the remaining modification count to `t`.
2. Modify the letters with fewer occurrences in the horizontal direction. If the
number of such letters exceeds `t`, then modify only `t` of them; otherwise,
modify all of them.

since Manhattan dist is to be calculated for all letter as the operation
happens, traverse the string, and do the process at each letter

*/

class Solution {
public:
  int maxDistance(string s, int k) {
    int ans = 0;
    int north = 0, south = 0, east = 0, west = 0;
    for (char it : s) {
      switch (it) {
      case 'N':
        north++;
        break;
      case 'S':
        south++;
        break;
      case 'E':
        east++;
        break;
      case 'W':
        west++;
        break;
      }
      int times1 = min({north, south, k}); // modification times for N and S
      int times2 =
          min({east, west, k - times1}); // modification times for E and W
      ans = max(ans, count(north, south, times1) + count(east, west, times2));
    }
    return ans;
  }

  int count(int drt1, int drt2, int times) {
    return abs(drt1 - drt2) + times * 2;
  } // Calculate modified Manhattan distance
};
// sub:
// https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/submissions/1670764346/?envType=daily-question&envId=2025-06-20
// sol:
// https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/solutions/6866400/3443-maximum-manhattan-distance-after-k-0p1xk/
//  Time: O(n)
//  Space: O(1)
