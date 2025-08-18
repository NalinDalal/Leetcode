/*679. 24 Game
You are given an integer array cards of length 4. You have four cards, each
containing a number in the range [1, 9]. You should arrange the numbers on these
cards in a mathematical expression using the operators ['+', '-', '*', '/'] and
the parentheses '(' and ')' to get the value 24.

You are restricted with the following rules:

The division operator '/' represents real division, not integer division.
For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
Every operation done is between two numbers. In particular, we cannot use '-' as
a unary operator. For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 -
1 - 1" is not allowed. You cannot concatenate numbers together For example, if
cards = [1, 2, 1, 2], the expression "12 + 12" is not valid. Return true if you
can get such expression that evaluates to 24, and false otherwise.



Example 1:
Input: cards = [4,1,8,7]
Output: true
Explanation: (8-4) * (7-1) = 24

Example 2:
Input: cards = [1,2,1,2]
Output: false


Constraints:
cards.length == 4
1 <= cards[i] <= 9

*/

// given a vector of integers
// traverse the array and check if you can create the value 24
// if you can return true
// else return false
// you can use operators: +,-,*,/,(,)
// to check for sum-> if size is 1 and the value is 24 return true
// try all pairs of the number, keep them and try the operations
// generate all possible pair and their results

/*- we are doing both `(i,j)` and `(j,i)`; but we can optimise it by eliminating
one of them

- use a buffer to avoid the new vector initialisation upon each iteration

- If at any point we reach a value very close to 24, we can stop early without
continuing all paths.
*/

#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
  bool judgePoint24(vector<int>& cards) {
    vector<double> nums(cards.begin(), cards.end());
    return solve(nums);
  }

private:
  const double EPS = 1e-6;

  bool solve(vector<double>& nums) {
    int n = nums.size();
    if (n == 1)
      return fabs(nums[0] - 24.0) < EPS;

    // pick two numbers
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) { // avoid duplicate pairs
        vector<double> next;
        for (int k = 0; k < n; k++) {
          if (k != i && k != j)
            next.push_back(nums[k]);
        }

        // apply all results of nums[i] and nums[j]
              [48;54;204;1728;2856t  for (double val : compute(nums[i], nums[j])) {
          next.push_back(val);
          if (solve(next))
            return true;
          next.pop_back();
                }
      }
    }
    return false;
  }

  vector<double> compute(double a, double b) {
    vector<double> res;
    res.push_back(a + b);
    res.push_back(a - b);
    res.push_back(b - a);
    res.push_back(a * b);
    if (fabs(b) > EPS)
      res.push_back(a / b);
    if (fabs(a) > EPS)
      res.push_back(b / a);
    return res;
  }
};
// sub:
// https://leetcode.com/problems/24-game/submissions/1739112806/?envType=daily-question&envId=2025-08-18
// sol:
// https://leetcode.com/problems/24-game/solutions/7093821/679-24-game-by-nalindalal2004-s9c7/
