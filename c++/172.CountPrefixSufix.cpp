/* https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/?envType=daily-question&envId=2025-01-08

3042. Count Prefix and Suffix Pairs I
Easy
Topics
Companies
Hint
You are given a 0-indexed string array words.

Let's define a boolean function isPrefixAndSuffix that takes two strings, str1
and str2:

isPrefixAndSuffix(str1, str2) returns true if str1 is both a prefix and a suffix
of str2, and false otherwise. For example, isPrefixAndSuffix("aba", "ababa") is
true because "aba" is a prefix of "ababa" and also a suffix, but
isPrefixAndSuffix("abc", "abcd") is false.

Return an integer denoting the number of index pairs (i, j) such that i < j, and
isPrefixAndSuffix(words[i], words[j]) is true.


Example 1:
Input: words = ["a","aba","ababa","aa"]
Output: 4
Explanation: In this example, the counted index pairs are:
i = 0 and j = 1 because isPrefixAndSuffix("a", "aba") is true.
i = 0 and j = 2 because isPrefixAndSuffix("a", "ababa") is true.
i = 0 and j = 3 because isPrefixAndSuffix("a", "aa") is true.
i = 1 and j = 2 because isPrefixAndSuffix("aba", "ababa") is true.
Therefore, the answer is 4.

Example 2:
Input: words = ["pa","papa","ma","mama"]
Output: 2
Explanation: In this example, the counted index pairs are:
i = 0 and j = 1 because isPrefixAndSuffix("pa", "papa") is true.
i = 2 and j = 3 because isPrefixAndSuffix("ma", "mama") is true.
Therefore, the answer is 2.

Example 3:
Input: words = ["abab","ab"]
Output: 0
Explanation: In this example, the only valid index pair is i = 0 and j = 1, and
isPrefixAndSuffix("abab", "ab") is false. Therefore, the answer is 0.


Constraints:
1 <= words.length <= 50
1 <= words[i].length <= 10
words[i] consists only of lowercase English letters.*/

// Iterate through all index pairs (i, j), such that i < j, and check
// isPrefixAndSuffix(words[i], words[j]). The answer is the total number of
// pairs where isPrefixAndSuffix(words[i], words[j]) == true.
// isPrefixAndSuffix(str1, str2) returns true if str1 is both a prefix and
// suffix of str2, else returns false.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// fixes for previous:
// The condition should ensure that str1 is a prefix and a suffix of str2. For
// this, you need to check:

// The first str1.size() characters of str2 must match str1.
// The last str1.size() characters of str2 must also match str1.

/* 1. Helper Function: isPrefixAndSuffix
This function checks if one string (str1) is both a prefix and suffix of another
string (str2). Steps: ✅ Length Check: If str1 is longer than str2, it cannot be
a valid prefix or suffix, so return false. ✅ Prefix Comparison: Compare the
first n1 characters of str2 with str1 (where n1 = str1.length()). ✅ Suffix
Comparison: Compare the last n1 characters of str2 with str1. ✅ Return true if
both conditions are satisfied.

2. 🔁 Counting Pairs
Use a nested loop to iterate through all pairs (i, j) in the words array.
Check if words[i] is a prefix and suffix of words[j].
Increment the count for each valid pair.
*/

class Solution {
public:
  bool isPrefixAndSuffix(const string& str1, const string& str2) {
    int n1 = str1.size(), n2 = str2.size();
    if (n1 > n2)
      return false;
    return str2.substr(0, n1) == str1 && str2.substr(n2 - n1) == str1;
  }

  int countPrefixSuffixPairs(vector<string>& words) {
    int n = words.size(), count = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (isPrefixAndSuffix(words[i], words[j])) {
          ++count;
        }
      }
    }
    return count;
  }
};

// Time Complexity: O(n^2)
// Space Complexity: O(1)
// 100%
// submission:
// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/submissions/1501749806/?envType=daily-question&envId=2025-01-08
// solution:
// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/solutions/6249108/3042-count-prefix-and-suffix-pairs-i100-i6ntt/
