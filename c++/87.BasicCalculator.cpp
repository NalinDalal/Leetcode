/* 224. Basic Calculator

Given a string s representing a valid expression, implement a basic calculator
to evaluate it, and return the result of the evaluation. Note: You are not
allowed to use any built-in function which evaluates strings as mathematical
expressions, such as eval().


Example 1:
Input: s = "1 + 1"
Output: 2

Example 2:
Input: s = " 2-1 + 2 "
Output: 3

Example 3:
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23


Constraints:

1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.*/

// Approach/line of Thought:
// first go step by step into the string
// if it is a number, add it to a stack
// if it is a operator, pop two number from the stack and perform the required
// operation, push the result back to stack
// if it is opening parenthesis, push to stack
// if closing parenthesis, pop the stack and perform operation, push the result
// return the result
#include <iostream>
#include <stack>
#include <string>
using namespace std;
#include <cctype>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
  int calculate(string s) {
    stack<int> nums; // Stack to store intermediate results
    stack<int> ops;  // Stack to store signs (+1 or -1)

    int num = 0;    // Current number being processed
    int result = 0; // Final result
    int sign = 1;   // Current sign (+1 for positive, -1 for negative)

    for (int i = 0; i < s.length(); ++i) {
      char ch = s[i];

      if (isdigit(ch)) {
        // Build the current number (handles multi-digit numbers)
        num = num * 10 + (ch - '0');
      } else if (ch == '+' || ch == '-') {
        // Add the last number with its sign to the result
        result += sign * num;
        num = 0; // Reset current number
        // Update the sign for the next number
        sign = (ch == '+') ? 1 : -1;
      } else if (ch == '(') {
        // Push the current result and sign onto their respective stacks
        nums.push(result);
        ops.push(sign);
        // Reset result and sign for the new sub-expression
        result = 0;
        sign = 1;
      } else if (ch == ')') {
        // Add the last number with its sign to the result
        result += sign * num;
        num = 0; // Reset current number
        // Combine the result inside the parentheses with the outer result
        result = nums.top() + ops.top() * result;
        nums.pop();
        ops.pop();
      }
    }

    // Add the last number (if any) to the result
    result += sign * num;
    return result;
  }
};

int main() {
  Solution s;
  string s1 = "1+1";
  cout << s1 << "=" << s.calculate(s1) << endl;
  string s2 = "2-1 + 2 ";
  cout << s2 << "=" << s.calculate(s2) << endl;
  string s3 = "(1+(4+5+2)-3)+(6+8)";
  cout << s3 << "=" << s.calculate(s3) << endl;

  return 0;
}

/* - Time complexity:$$O(n)$$

- Space complexity:$$O(n)$$*/
