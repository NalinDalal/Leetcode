/* 2116. Check if a Parentheses String Can Be Valid
Medium
Topics
Companies
Hint
A parentheses string is a non-empty string consisting only of '(' and ')'. It is
valid if any of the following conditions is true:

It is ().
It can be written as AB (A concatenated with B), where A and B are valid
parentheses strings. It can be written as (A), where A is a valid parentheses
string. You are given a parentheses string s and a string locked, both of length
n. locked is a binary string consisting only of '0's and '1's. For each index i
of locked,

If locked[i] is '1', you cannot change s[i].
But if locked[i] is '0', you can change s[i] to either '(' or ')'.
Return true if you can make s a valid parentheses string. Otherwise, return
false.



Example 1:


Input: s = "))()))", locked = "010100"
Output: true
Explanation: locked[1] == '1' and locked[3] == '1', so we cannot change s[1] or
s[3]. We change s[0] and s[4] to '(' while leaving s[2] and s[5] unchanged to
make s valid. Example 2:

Input: s = "()()", locked = "0000"
Output: true
Explanation: We do not need to make any changes because s is already valid.
Example 3:

Input: s = ")", locked = "0"
Output: false
Explanation: locked permits us to change s[0].
Changing s[0] to either '(' or ')' will not make s valid.


Constraints:

n == s.length == locked.length
1 <= n <= 105
s[i] is either '(' or ')'.
locked[i] is either '0' or '1'.*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
// use same as ValidParenthesisString
//
class Solution {
public:
  bool canBeValid(string s, string locked) {
    int n = s.size();
    if (n == 0)
      return true;
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
      if (locked[i] == '1')
        continue;
      if (s[i] == '(') {
        dp[i] = dp[i - 1];
      } else {
        dp[i] = dp[i - 1] + dp[i - 2];
      }
    }
    return dp[n - 1] == 1;
  }
};

// gives run time error; cause accessing out of bound

class Solution1 {
public:
  static bool canBeValid(string& s, string& locked) {
    const int n = s.size();
    if (n & 1)
      return 0;
    int bMin = 0, bMax = 0;
    for (int i = 0; i < n; i++) {
      bool op = s[i] == '(', wild = locked[i] == '0';
      bMin += (!op | wild) ? -1 : 1;
      bMax += (op | wild) ? 1 : -1;
      if (bMax < 0)
        return 0;
      bMin = max(bMin, 0);
    }
    return bMin == 0;
  }
};
// 100%
auto init = []() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  return 'c';
}();

// Time: O(n)
// Space: O(n)
// sub:
// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/submissions/1505801781/?envType=daily-question&envId=2025-01-12
// sol:
// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/solutions/6267601/2116-check-if-a-parentheses-string-can-b-3rmy/
