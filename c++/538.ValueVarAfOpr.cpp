/*2011. Final Value of Variable After Performing Operations
There is a programming language with only four operations and one variable X:

++X and X++ increments the value of the variable X by 1.
--X and X-- decrements the value of the variable X by 1.
Initially, the value of X is 0.

Given an array of strings operations containing a list of operations, return the
final value of X after performing all the operations.



Example 1:

Input: operations = ["--X","X++","X++"]
Output: 1
Explanation: The operations are performed as follows:
Initially, X = 0.
--X: X is decremented by 1, X =  0 - 1 = -1.
X++: X is incremented by 1, X = -1 + 1 =  0.
X++: X is incremented by 1, X =  0 + 1 =  1.
Example 2:

Input: operations = ["++X","++X","X++"]
Output: 3
Explanation: The operations are performed as follows:
Initially, X = 0.
++X: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
X++: X is incremented by 1, X = 2 + 1 = 3.
Example 3:

Input: operations = ["X++","++X","--X","X--"]
Output: 0
Explanation: The operations are performed as follows:
Initially, X = 0.
X++: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
--X: X is decremented by 1, X = 2 - 1 = 1.
X--: X is decremented by 1, X = 1 - 1 = 0.


Constraints:

1 <= operations.length <= 100
operations[i] will be either "++X", "X++", "--X", or "X--".

Hint 1
There are only two operations to keep track of.
Hint 2
Use a variable to store the value after each operation.
*/
class Solution {
public:
  int finalValueAfterOperations(vector<string>& operations) {
    int X = 0;
    for (const string& op : operations) {
      if (op.find('+') != string::npos)
        X++;
      else
        X--;
    }
    return X;
  }
};
// sub:
// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/submissions/1806651483/?envType=daily-question&envId=2025-10-20
// sol:
// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/solutions/7288260/2011-final-value-of-variable-after-perfo-fbwl/
