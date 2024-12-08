/* 2337. Move Pieces to Obtain a String

You are given two strings start and target, both of length n. Each string
consists only of the characters 'L', 'R', and '_' where:

The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the
left only if there is a blank space directly to its left, and a piece 'R' can
move to the right only if there is a blank space directly to its right. The
character '_' represents a blank space that can be occupied by any of the 'L' or
'R' pieces. Return true if it is possible to obtain the string target by moving
the pieces of the string start any number of times. Otherwise, return false.



Example 1:
Input: start = "_L__R__R_", target = "L______RR"
Output: true
Explanation: We can obtain the string target from start by doing the following
moves:
- Move the first piece one step to the left, start becomes equal to "L___R__R_".
- Move the last piece one step to the right, start becomes equal to "L___R___R".
- Move the second piece three steps to the right, start becomes equal to
"L______RR". Since it is possible to get the string target from start, we return
true.

Example 2:
Input: start = "R_L_", target = "__LR"
Output: false
Explanation: The 'R' piece in the string start can move one step to the right to
obtain "_RL_". After that, no pieces can move anymore, so it is impossible to
obtain the string target from start.

Example 3:
Input: start = "_R", target = "R_"
Output: false
Explanation: The piece in the string start can move only to the right, so it is
impossible to obtain the string target from start.


Constraints:
n == start.length == target.length
1 <= n <= 105
start and target consist of the characters 'L', 'R', and '_'. */

#include <iostream>
#include <string>

using namespace std;

// 1. You check that the characters at each index of start and target match
// (ignoring underscores), but this approach only works if the characters are
// strictly movable (i.e., 'L' or 'R')
// 2. 'L' can only move left, so in the start string, it must always appear
// before the corresponding 'L' in target, and vice versa for 'R'.
// 3. The underscores _ act as gaps for the pieces to move, and they can be
// anywhere
// 4. 'L' should be left of target, 'R' should be right of target
class Solution { // -> Wrong
public:
  bool canChange(string start, string target) {
    // If the start and target strings don't have the same characters and
    // frequency
    if (start.length() != target.length())
      return false;

    // check if strings can be rearranged
    for (int i = 0; i < start.length(); ++i) {
      if (start[i] != '_' && target[i] != '_' && start[i] != target[i]) {
        return false; // If there's a mismatch between non-underscore characters
      }
    }

    int n = start.size();
    // Traverse both strings simultaneously
    for (int i = 0, j = 0; i < n && j < n;) {
      // Skip over underscores
      while (i < n && start[i] == '_')
        i++;
      while (j < n && target[j] == '_')
        j++;

      if (i < n && j < n) {
        if (start[i] != target[j])
          return false; // Non-matching characters
        if (start[i] == 'L' && i < j)
          return false; // 'L' cannot move to the right
        if (start[i] == 'R' && i > j)
          return false; // 'R' cannot move to the left

        i++;
        j++;
      }
    }

    return true;
  }
};

class Solution2 { //-> Wrong
public:
  bool canChange(string start, string target) {
    // If the start and target strings don't have the same length, return false
    if (start.length() != target.length()) {
      return false;
    }

    // Check for consistency: both strings must have the same number of 'L', 'R'
    // and '_'
    for (int i = 0; i < start.size(); ++i) {
      // If there are non-underscore mismatches, it's impossible
      if (start[i] != '_' && target[i] != '_' && start[i] != target[i]) {
        return false;
      }
    }

    int n = start.size();
    // Traverse both strings simultaneously
    for (int i = 0, j = 0; i < n && j < n;) {
      // Skip over underscores in both strings
      while (i < n && start[i] == '_') {
        i++;
      }
      while (j < n && target[j] == '_') {
        j++;
      }

      if (i < n && j < n) {
        // If the characters don't match, return false
        if (start[i] != target[j]) {
          return false;
        }

        // Check if 'L' is moving to the left or 'R' is moving to the right
        if (start[i] == 'L' && i < j) {
          return false; // 'L' can't move to the right
        }
        if (start[i] == 'R' && i > j) {
          return false; // 'R' can't move to the left
        }

        // Move to the next non-underscore characters
        i++;
        j++;
      }
    }

    return true; // Return true if all checks pass
  }
};
// Time: O(n)
// Space: O(1)

// Explanation:
/* Initial Check: If the start and target strings have different lengths, return
false immediately because they can't be made equal.

2. Matching 'L' and 'R':

- As we traverse both start and target, we make sure that for any 'L' in start,
it matches a corresponding 'L' in target and that 'L' never moves rightward.
- Similarly, for any 'R', it should match a corresponding 'R' in target and 'R'
should never move leftward.

3. Skipping Underscores: Both strings may contain underscores ('_'), which we
skip over while comparing the characters.

4. Final Decision: The function returns true if we successfully compare and
validate the positions and movements of characters in both strings.
*/

class Solution3 {
  void skipSpaces(string& s, int& n, int& pos) {
    while (pos < n and s[pos] == '_')
      pos++;
  }

public:
  bool canChange(string start, string target) {
    int n = start.size();

    int first = 0, second = 0;
    int limit_idx = -1;
    while (first < n) {
      // Skip all spaces
      skipSpaces(start, n, first);
      skipSpaces(target, n, second);

      if (first == n and second == n)
        return true;
      if (start[first] != target[second])
        return false;

      if (start[first] == 'L' and (second <= limit_idx or second > first))
        return false;
      else if (start[first] == 'R' and first > second)
        return false;

      limit_idx = second;
      first++;
      second++;
    }
    // Skip leftover spaces (if any)
    skipSpaces(start, n, first);
    skipSpaces(target, n, second);

    return first == n && second == n;
  }
};
// Time: O(n)
// Space: O(1)

// Approach/Explanation:
/*1. Skipping spaces: The helper function skipSpaces is used to skip over spaces
(represented by _) in both start and target strings.

2. Two pointers (first and second):
- first tracks the position in the start string.
- second tracks the position in the target string.

3. Matching characters:
- The function iterates over the strings while skipping spaces.
- If the characters at start[first] and target[second] are different, it
immediately returns false.
- If they are the same, the next condition checks whether the movement of 'L' or
'R' is valid according to the specified rules.

4. Rules for 'L' and 'R':
- For 'L', the target position should be less than or equal to the current
position (second <= limit_idx), and the 'L' character cannot jump over to a
position further right than the current position.
- For 'R', the target position must be greater than the current position (second
> first), and 'R' cannot jump to a position earlier in the string.

5. Checking for the end condition: After processing, we check if both pointers
(first and second) have reached the end of their respective strings, confirming
that the transformation is valid.
*/
int main() {
  Solution3 s;
  string start1 = "_L__R__R_", target1 = "L______RR";
  string start2 = "R_L_", target2 = "__LR";
  string start3 = "_R", target3 = "R_";

  cout << "Test Case 1:" << endl;
  cout << "Start: " << start1 << ", Target: " << target1 << endl;
  cout << s.canChange(start1, target1) << endl; // Expected output: true

  cout << endl;

  cout << "Test Case 2:" << endl;
  cout << "Start: " << start2 << ", Target: " << target2 << endl;
  cout << s.canChange(start2, target2) << endl; // Expected output: false

  cout << endl;

  cout << "Test Case 3:" << endl;
  cout << "Start: " << start3 << ", Target: " << target3 << endl;
  cout << s.canChange(start3, target3) << endl; // Expected output: false

  return 0;
}
