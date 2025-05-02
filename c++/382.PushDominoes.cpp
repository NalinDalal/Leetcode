/* 838. Push Dominoes

There are n dominoes in a line, and we place each domino vertically upright. In
the beginning, we simultaneously push some of the dominoes either to the left or
to the right.

After each second, each domino that is falling to the left pushes the adjacent
domino on the left. Similarly, the dominoes falling to the right push their
adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays
still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino
expends no additional force to a falling or already fallen domino.

You are given a string dominoes representing the initial state where:

dominoes[i] = 'L', if the ith domino has been pushed to the left,
dominoes[i] = 'R', if the ith domino has been pushed to the right, and
dominoes[i] = '.', if the ith domino has not been pushed.
Return a string representing the final state.


Example 1:
Input: dominoes = "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.

Example 2:
Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."


Constraints:
n == dominoes.length
1 <= n <= 105
dominoes[i] is either 'L', 'R', or '.'.
*/

/* maintain the state, from 2 pointer approach
and update the ith domino on it's falling direction like `l` for left, `R` for
right and `.` for still */

/* Approach:
We simulate the force from left to right and then from right to left:
    1. Left to right pass: add positive force from 'R'.
    2. Right to left pass: add negative force from 'L'.

Then we determine the final state:
- Net force > 0 → 'R'
- Net force < 0 → 'L'
- Net force = 0 → '.'
*/

class Solution {
public:
  string pushDominoes(std::string dominoes) {
    int n = dominoes.size();
    std::vector<int> forces(n, 0);
    int force = 0;

    // Left to right
    for (int i = 0; i < n; ++i) {
      if (dominoes[i] == 'R') {
        force = n;
      } else if (dominoes[i] == 'L') {
        force = 0;
      } else {
        force = std::max(force - 1, 0);
      }
      forces[i] += force;
    }

    // Right to left
    force = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (dominoes[i] == 'L') {
        force = n;
      } else if (dominoes[i] == 'R') {
        force = 0;
      } else {
        force = std::max(force - 1, 0);
      }
      forces[i] -= force;
    }

    // Final result
    std::string result;
    for (int f : forces) {
      if (f > 0)
        result += 'R';
      else if (f < 0)
        result += 'L';
      else
        result += '.';
    }

    return result;
  }
};
// sub:
// https://leetcode.com/problems/push-dominoes/submissions/1623259386/?envType=daily-question&envId=2025-05-02
// Time: O(n)
// Space: O(n)
