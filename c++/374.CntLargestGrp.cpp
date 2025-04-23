/* 1399. Count Largest Group
You are given an integer n.

Each number from 1 to n is grouped according to the sum of its digits.

Return the number of groups that have the largest size.

Example 1:
Input: n = 13
Output: 4
Explanation: There are 9 groups in total, they are grouped according sum of its
digits of numbers from 1 to 13: [1,10], [2,11], [3,12], [4,13], [5], [6], [7],
[8], [9]. There are 4 groups with largest size.

Example 2:
Input: n = 2
Output: 2
Explanation: There are 2 groups [1], [2] of size 1.


Constraints:
1 <= n <= 104

Hint 1: Count the digit sum for each integer in the range and find out the
largest groups.
*/
// Intuition:
// move from 1 to n, check sum of digits, if sum is new create new grp, else add
// to existing grps
// return the count of grpswith largest size

/* Approach:
For each integer i in the interval [1,n], we can calculate its digit sum s[i] .
We establish a hash mapping from the digit sum to the original number. For each
number i, we increment the value corresponding to the key  s[i] by one. We then
find the maximum value m in the set of values and traverse the hash table to
count the number of occurrences of m.
*/

class Solution {
public:
  int countLargestGroup(int n) {
    unordered_map<int, int> hashMap;
    int maxValue = 0;
    for (int i = 1; i <= n; ++i) {
      int key = 0, i0 = i;
      while (i0) {
        key += i0 % 10;
        i0 /= 10;
      }
      ++hashMap[key];
      maxValue = max(maxValue, hashMap[key]);
    }
    int count = 0;
    for (auto& [_, value] : hashMap) {
      if (value == maxValue) {
        ++count;
      }
    }
    return count;
  }
};
// Sub:
// https://leetcode.com/problems/count-largest-group/submissions/1615151704/?envType=daily-question&envId=2025-04-23
//  Time: O(n)
//  Space: O(n
