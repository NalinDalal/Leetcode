/* 1249. Minimum Remove to Make Valid Parentheses

Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any
positions ) so that the resulting parentheses string is valid and return any
valid string.

Formally, a parentheses string is valid if and only if:

- It is the empty string, contains only lowercase characters, or
- It can be written as AB (A concatenated with B), where A and B are valid
strings, or
- It can be written as (A), where A is a valid string.


Example 1:
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

Example 2:
Input: s = "a)b(c)d"
Output: "ab(c)d"

Example 3:
Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.


Constraints:
1 <= s.length <= 10^5
s[i] is either '(' , ')', or lowercase English letter.
*/

// What can we do?
// since s[i] is lowercase or ( / ), we may be able to use a stack to store the
// parenthese, and then pop to get results.
// make sure stack is empty b/f pushing.
// always pair up ( with ) ; not ) with (.

// Problem:
/* 1. You're using a stack<char> but it doesn't store indices or help with
determining which characters to remove from the string. A valid implementation
typically tracks indices of unmatched parentheses to process them later.
2. Returning an empty string ("") whenever encountering an unmatched ')' is
incorrect because it doesn't process the rest of the string. Instead, you should
mark such indices for removal. 3.Your function tries to return a stack<char> at
the end, but the return type of the function is string. This leads to a
compilation error. */

#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>

using namespace std;

// Approach:
/* First Pass:
Traverse the string.
Use a stack<int> to store indices of unmatched '('.
When encountering a ')', either match it with a '(' or mark it as invalid.

Second Pass:
Traverse the string again and construct the result string by skipping invalid
indices.*/

class Solution {
public:
  string minRemoveToMakeValid(string s) {
    stack<int> st;                     // To store indices of unmatched '('
    unordered_set<int> invalidIndices; // To mark indices to remove

    // First pass: Identify invalid parentheses
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(') {
        st.push(i); // Store the index of '('
      } else if (s[i] == ')') {
        if (!st.empty()) {
          st.pop(); // Match ')' with the most recent '('
        } else {
          invalidIndices.insert(i); // Mark unmatched ')'
        }
      }
    }

    // Add unmatched '(' indices to invalidIndices
    while (!st.empty()) {
      invalidIndices.insert(st.top());
      st.pop();
    }

    // Second pass: Build the result string without invalid indices
    string result = "";
    for (int i = 0; i < s.length(); i++) {
      if (invalidIndices.find(i) == invalidIndices.end()) {
        result += s[i];
      }
    }

    return result;
  }
};

int main() {
  Solution s;
  string s1 = "lee(t(c)o)de)";
  cout << s1 << endl;
  s.minRemoveToMakeValid(s1);
  cout << s1 << endl;

  cout << endl;
  string s2 = "a)b(c)d";
  cout << s2 << endl;
  s.minRemoveToMakeValid(s2);
  cout << s2 << endl;

  cout << endl;
  string s3 = "))((";
  cout << s3 << endl;
  s.minRemoveToMakeValid(s3);
  cout << s3 << endl;

  return 0;
}

// Time complexity: $$O(n)$$

// Space complexity: $$O(n)$$
