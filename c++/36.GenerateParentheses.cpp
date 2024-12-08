/*
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of
well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
*/

/*
 Key Points:
Well-formed parentheses: A valid combination of parentheses is one where every
opening parenthesis ( has a corresponding closing parenthesis ), and they are
correctly nested. For example, "((()))" is valid, but "())(" or "(()" is not.

Input:

A single integer n, which represents the number of pairs of parentheses.
Output:

A list of all possible valid combinations of n pairs of parentheses.

    */

// Approach:
/*
 This problem is a good example of backtracking. You can recursively build the
parentheses by keeping track of two counts:

open: The number of opening parentheses ( that you can still use (starts at n).
close: The number of closing parentheses ) that you can still use (starts at n).
The rules to generate valid combinations are:

You can add an opening parenthesis if there are any left (open > 0).
You can add a closing parenthesis if the number of closing parentheses is
greater than the number of opening parentheses used so far (close > open)

open = close || open>close

only add open paranthesis if open < n
only add a closing paranthesis if closed ‹ open
valid IIF open == closed == n
    */
class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string current;

    // Helper function to backtrack
    function<void(int, int)> backtrack = [&](int openN, int closedN) {
      if (openN == n && closedN == n) {
        res.push_back(current);
        return;
      }

      // Add open parenthesis if possible
      if (openN < n) {
        current.push_back('(');
        backtrack(openN + 1, closedN);
        current.pop_back();
      }

      // Add close parenthesis if possible
      if (closedN < openN) {
        current.push_back(')');
        backtrack(openN, closedN + 1);
        current.pop_back();
      }
    };

    // Initial call with openN and closedN set to 0
    backtrack(0, 0);
    return res;
  }
};
