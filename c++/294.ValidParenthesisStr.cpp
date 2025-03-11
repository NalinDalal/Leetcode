/* 678. Valid Parenthesis String
Given a string s containing only three types of characters: '(', ')' and '*',
return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left
parenthesis '(' or an empty string "".


Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "(*)"
Output: true

Example 3:
Input: s = "(*))"
Output: true


Constraints:
1 <= s.length <= 100
s[i] is '(', ')' or '*'.

Hint 1
Use backtracking to explore all possible combinations of treating '*' as either
'(', ')', or an empty string. If any combination leads to a valid string, return
true. Hint 2 DP[i][j] represents whether the substring s[i:j] is valid. Hint 3
Keep track of the count of open parentheses encountered so far. If you encounter
a close parenthesis, it should balance with an open parenthesis. Utilize a stack
to handle this effectively.
*/
#include <stack>
#include <string>
using namespace std;

/*class Solution {
public:
  bool checkValidString(string s) {
    bool result = false;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(')
        st.push(s[i]);
    }
    if (st.empty())
      result = true;
    while (!st.empty()) {
      if (st.top() == '(')
        st.pop();
      else
        result = false;
    }
    return result;
  }
};
*/

// this handles for '*' also as a wildcard character
/* Introduce 2 counter: `minLeft`,`maxLeft`
now iterate through the string
upon iteration check for specific characters: `(`,`)`,`*`
```cpp
if (char=`(`){
    minLeft++;maxLeft++;
}else if(char=`)`){
    if (minLeft > 0) minLeft--;
    maxLeft--;
}else if (c == '*') {
    if (minLeft > 0) minLeft--;  // Treat '*' as ')'
    maxLeft++;                   // Treat '*' as '('
}
if (maxLeft < 0) return false;
```

al last return result for comparing `minLeft==0`
*/
class Solution {
public:
  bool checkValidString(std::string s) {
    int minLeft = 0; // Minimum possible '('
    int maxLeft = 0; // Maximum possible '('

    for (char c : s) {
      if (c == '(') {
        minLeft++;
        maxLeft++;
      } else if (c == ')') {
        if (minLeft > 0)
          minLeft--;
        maxLeft--;
      } else if (c == '*') {
        if (minLeft > 0)
          minLeft--; // Treat '*' as ')'
        maxLeft++;   // Treat '*' as '('
      }

      if (maxLeft < 0)
        return false; // Too many ')' without matching '('
    }

    return minLeft == 0; // All '(' have a matching ')'
  }
};
// sub:
// https://leetcode.com/problems/valid-parenthesis-string/submissions/1569748451/
// sol:
// https://leetcode.com/problems/valid-parenthesis-string/solutions/6522267/678-valid-parenthesis-string-by-nalindal-30s8/
