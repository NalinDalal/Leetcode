/* 32. Longest Valid Parentheses

Given a string containing just the characters '(' and ')', return the length of
the longest valid (well-formed) parentheses substring.

Example 1:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:
Input: s = ""
Output: 0


Constraints:

0 <= s.length <= 3 * 10^4
s[i] is '(', or ')'.*/

// Approach:
// 1. initialise a stack, at each opening paranthesis push it to stack, at each
// closing one pop it from stack, and increase a counter if stack is empty
// If the stack becomes empty after the pop, push the current index as a new
// reference point. Otherwise, calculate the length of the valid substring using
// the current index and the index at the top of the stack.
// 2. Keep updating the maximum valid substring length as you go through the
// string.
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1); // Initial reference point
    int maxLength = 0;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        st.push(i); // Push the index of '('
      } else {
        st.pop(); // Pop for matching ')'
        if (st.empty()) {
          st.push(i); // Push current index as new reference point
        } else {
          maxLength = max(maxLength, i - st.top());
        }
      }
    }
    return maxLength;
  }
};

/*
# Complexity
- Time complexity:O(n)

- Space complexity:O(n)*/

int main() {
  string s1 = "(()";
  string s2 = ")()())";
  string s3 = "";

  Solution obj;
  cout << obj.longestValidParentheses(s1) << endl;
  cout << obj.longestValidParentheses(s2) << endl;
  cout << obj.longestValidParentheses(s3) << endl;
  return 0;
}
