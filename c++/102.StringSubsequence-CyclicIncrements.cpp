/* 2825. Make String a Subsequence Using Cyclic Increments

You are given two 0-indexed strings str1 and str2.

In an operation, you select a set of indices in str1, and for each index i in
the set, increment str1[i] to the next character cyclically. That is 'a' becomes
'b', 'b' becomes 'c', and so on, and 'z' becomes 'a'.

Return true if it is possible to make str2 a subsequence of str1 by performing
the operation at most once, and false otherwise.

Note: A subsequence of a string is a new string that is formed from the original
string by deleting some (possibly none) of the characters without disturbing the
relative positions of the remaining characters.



Example 1:
Input: str1 = "abc", str2 = "ad"
Output: true
Explanation: Select index 2 in str1.
Increment str1[2] to become 'd'.
Hence, str1 becomes "abd" and str2 is now a subsequence. Therefore, true is
returned.

Example 2:
Input: str1 = "zc", str2 = "ad"
Output: true
Explanation: Select indices 0 and 1 in str1.
Increment str1[0] to become 'a'.
Increment str1[1] to become 'd'.
Hence, str1 becomes "ad" and str2 is now a subsequence. Therefore, true is
returned.

Example 3:
Input: str1 = "ab", str2 = "d"
Output: false
Explanation: In this example, it can be shown that it is impossible to make str2
a subsequence of str1 using the operation at most once. Therefore, false is
returned.


Constraints:
1 <= str1.length <= 10^5
1 <= str2.length <= 10^5
str1 and str2 consist of only lowercase English letters. */

#include <iostream>
#include <string>

using namespace std;

// Intuition:
// We can use a two-pointer technique:

// 1. Start with two indices: i for str1 and j for str2, both initialized to 0.
// 2. Increment i in every step and check if str1[i] == str2[j].
// 3. If a match is found, increment j.
// 4. If j reaches the end of str2, return true, as we have found all characters
// of str2 in str1 in order.
// 5. If i reaches the end of str1 before j reaches the end of str2, return
// false.

class Solution {
public:
  bool canMakeSubsequence(string str1, string str2) {
    int i = 0, j = 0;
    while (i < str1.length() && j < str2.length()) {
      if (str1[i] == str2[j]) {
        j++; // Match found, move to the next character in str2
      }
      i++; // Move to the next character in str1
    }
    return j == str2.length(); // Check if all characters of str2 were matched
  }
};

// Approach:
/*1. Traverse both strings using indices i for str1 and j for str2.
2. For each character:
- If str1[i] == str2[j], move both pointers forward.
- Else, check if rotating str1[i] forward by one results in a match with
str2[j]. If yes, move both pointers forward.
3. If j reaches the end of str2, return true.
4. If the traversal ends and not all characters in str2 are matched, return
false.*/

class Solution2 {
public:
  bool canMakeSubsequence(string str1, string str2) {
    int i = 0, j = 0;
    while (i < str1.length() && j < str2.length()) {
      // Check for a direct match or a rotated match
      if (str1[i] == str2[j] || (str1[i] - 'a' + 1) % 26 + 'a' == str2[j]) {
        j++; // Match found, move to the next character in str2
      }
      i++; // Move to the next character in str1
    }
    return j == str2.length(); // True if all characters of str2 were matched
  }
};

// Time Complexity: O(m+n), m,n are size of str1, str2
// Space Complexity: 𝑂(1)

// Optimisation:
class Solution3 {
public:
  bool canMakeSubsequence(string str1, string str2) {
    int j = 0, n = str1.length(), m = str2.length();
    for (int i = 0; i < n; i++) {
      if ((str1[i] == str2[j]) ||
          ((str1[i] - 'a' + 1) % 26 == (str2[j] - 'a'))) {
        j++;
      }
      if (j == m)
        return true;
    }
    return false;
  }
};

// Time complexity: O(m+n), m,n are size
// Space complexity: O(m+n)
int main() {
  Solution3 sol;
  string str1 = "abcde";
  string str2 = "ace";

  bool result = sol.canMakeSubsequence(str1, str2);
  cout << (result ? "true" : "false") << endl; // Output: true

  str1 = "abcde";
  str2 = "aec";

  result = sol.canMakeSubsequence(str1, str2);
  cout << (result ? "true" : "false") << endl; // Output: false

  return 0;
}
