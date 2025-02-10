/* https://leetcode.com/problems/clear-digits/description/?envType=daily-question&envId=2025-02-10
3174. Clear Digits

You are given a string s.

Your task is to remove all digits by doing this operation repeatedly:

Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.

Example 1:
Input: s = "abc"
Output: "abc"
Explanation:There is no digit in the string.

Example 2:
Input: s = "cb34"
Output: ""
Explanation:First, we apply the operation on s[2], and s becomes "c4".Then we
apply the operation on s[1], and s becomes "".


Constraints:
1 <= s.length <= 100
s consists only of lowercase English letters and digits.
The input is generated such that it is possible to delete all digits.
*/

// delete first digit and closest non-digit char to its left
// delete i and its left char nearest to it

class Solution {
public:
  string clearDigits(string s) {
    while (true) {
      int n = s.size();
      bool found = false;

      for (int i = 0; i < n; i++) {
        if (isDigit(s[i])) {
          // Find the nearest non-digit character to the left
          int j = i - 1;
          while (j >= 0 && isDigit(s[j]))
            j--; // Skip digits

          // Remove both the digit and the nearest non-digit
          s.erase(i, 1); // Remove digit
          if (j >= 0)
            s.erase(j, 1); // Remove left non-digit if it exists

          found = true;
          break; // Restart loop after deletion
        }
      }
      if (!found)
        break; // Stop when no more digits are found
    }
    return s;
  }

private:
  bool isDigit(char c) { return c >= '0' && c <= '9'; }
};

// Time: O(n); Space: O(1)
// Sub:
// https://leetcode.com/problems/clear-digits/submissions/1538156444/?envType=daily-question&envId=2025-02-10
// sol:
// https://leetcode.com/problems/clear-digits/solutions/6403184/3174-clear-digits-by-nalindalal2004-74p2/
