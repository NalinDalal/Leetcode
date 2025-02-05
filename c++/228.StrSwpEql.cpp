/* https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/?envType=daily-question&envId=2025-02-05
1790. Check if One String Swap Can Make Strings Equal

You are given two strings s1 and s2 of equal length. A string swap is an
operation where you choose two indices in a string (not necessarily different)
and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most
one string swap on exactly one of the strings. Otherwise, return false.



Example 1:
Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2
to make "bank".

Example 2:
Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.

Example 3:
Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is
required.


Constraints:
1 <= s1.length, s2.length <= 100
s1.length == s2.length
s1 and s2 consist of only lowercase English letters.
*/

#include <string>
#include <vector>
using std::vector, std::string;
class Solution {
public:
  bool areAlmostEqual(string s1, string s2) {
    if (s1.length() != s2.length())
      return false;

    if (s1 == s2)
      return true;

    // sort(s1.begin(), s1.end());
    // sort(s2.begin(),s2.end());

    // problem, need to apply only 1 swap, but sort fucks it up, as it may
    // swap more no of times
    // Track the indices where the characters differ.
    // If there are exactly two differences and swapping makes the strings equal
    // → return true. Otherwise, return false.
    std::vector<int> diffIndices;

    // Find indices where characters differ
    for (int i = 0; i < s1.length(); i++) {
      if (s1[i] != s2[i]) {
        diffIndices.push_back(i);
      }
    }

    // If there are exactly 2 differences, check if swapping fixes it
    if (diffIndices.size() == 2) {
      int i = diffIndices[0], j = diffIndices[1];
      return (s1[i] == s2[j] && s1[j] == s2[i]);
    }

    // If differences are not exactly 2, it's not almost equal
    return false;
  }
};
// sub:
// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/submissions/1532150239/?envType=daily-question&envId=2025-02-05

// check where chars differ
// and if after 2 swaps if they are equal then okay
// else not okay
class Solution2 {
public:
  bool areAlmostEqual(const std::string& s1, const std::string& s2) {
    if (s1.length() != s2.length())
      return false;

    if (s1 == s2)
      return true;

    int first = -1, second = -1;

    // Find indices where characters differ
    for (int i = 0; i < s1.length(); ++i) {
      if (s1[i] != s2[i]) {
        if (first == -1) {
          first = i;
        } else if (second == -1) {
          second = i;
        } else {
          // More than two differences, early exit
          return false;
        }
      }
    }

    // Check if exactly two differences and swapping makes strings equal
    return (second != -1 && s1[first] == s2[second] && s1[second] == s2[first]);
  }
};
// sub:
// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/submissions/1532151860/?envType=daily-question&envId=2025-02-05
int main() {
  Solution solution;
  std::cout << std::boolalpha << solution.areAlmostEqual("bank", "kanb")
            << std::endl; // true
  std::cout << std::boolalpha << solution.areAlmostEqual("attack", "defend")
            << std::endl; // false
  std::cout << std::boolalpha << solution.areAlmostEqual("abcd", "abdc")
            << std::endl; // true
  std::cout << std::boolalpha << solution.areAlmostEqual("aaaa", "aaaa")
            << std::endl; // true
  std::cout << std::boolalpha << solution.areAlmostEqual("abcd", "abcdx")
            << std::endl; // false
  return 0;
}

// sol:
// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/solutions/6378918/1790-check-if-one-string-swap-can-make-s-i5sz/
