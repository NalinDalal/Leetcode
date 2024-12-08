/*
 20. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid. An input string is valid if: Open
brackets must be closed by the same type of brackets. Open brackets must be
closed in the correct order. Every close bracket has a corresponding open
bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true

Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.


Hint 1: Use a stack of characters.
Hint 2: When you encounter an opening bracket, push it to the top of the stack.
Hint 3: When you encounter a closing bracket, check if the top of the stack was
the opening for it. If yes, pop it from the stack. Otherwise, return false.
*/

// my approach:
/*
 initialise a stack
 stack must take input as we traverse the string
 as the top of stack gets updated evry time; make sure to check brackets with
 their corresponding paranthesis and return true else return false
    */
//- Time complexity:O(n)

//- Space complexity:O(1)

#include <string>

class Solution {
public:
  bool isValid(string s) {
    stack<char> st; // Initialize a stack to store characters

    // Iterate over the string characters
    for (char c : s) {
      // If it's an opening bracket, push it onto the stack
      if (c == '(' || c == '{' || c == '[') {
        st.push(c);
      }
      // If it's a closing bracket, check for a matching opening bracket
      else {
        // If the stack is empty or the top of the stack doesn't match the
        // current closing bracket
        if (st.empty() || (c == ')' && st.top() != '(') ||
            (c == '}' && st.top() != '{') || (c == ']' && st.top() != '[')) {
          return false; // Invalid string
        }
        st.pop(); // Pop the matching opening bracket from the stack
      }
    }

    // If the stack is empty, it means all brackets are matched, so return true
    return st.empty();
  }
};
