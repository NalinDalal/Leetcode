/* 1415. The k-th Lexicographical String of All Happy Strings of Length n

A happy string is a string that:

consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is
1-indexed). For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy
strings and strings "aa", "baa" and "ababbc" are not happy strings.

Given two integers n and k, consider a list of all happy strings of length n
sorted in lexicographical order.

Return the kth string of this list or return an empty string if there are less
than k happy strings of length n.



Example 1:
Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1.
The third string is "c". Example 2: Input: n = 1, k = 4 Output: "" Explanation:
There are only 3 happy strings of length 1.

Example 3:
Input: n = 3, k = 9
Output: "cab"
Explanation: There are 12 different happy string of length 3 ["aba", "abc",
"aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will
find the 9th string = "cab"


Constraints:

1 <= n <= 10
1 <= k <= 100

Hint 1: Generate recursively all the happy strings of length n.
Hint 2: Sort them in lexicographical order and return the kth string if it
exists.*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  void generateHappyStrings(int n, string current, vector<string>& result) {
    // to generate Happy Strings of length n,
    // contains only a,b,c
    if (current.length() == n) {
      result.push_back(current);
      return;
    }

    for (char ch : {'a', 'b', 'c'}) {
      if (current.empty() || current.back() != ch) {
        generateHappyStrings(n, current + ch, result);
      }
    }
  }

  string getHappyString(int n, int k) {
    // so n is length of individual string
    // to return kth string, of length n, must be a happy string
    // happy string-> contains only a,b,c

    vector<string> happyStrings;
    generateHappyStrings(n, "", happyStrings);

    if (k > happyStrings.size())
      return "";
    return happyStrings[k - 1]; // k-th smallest (1-based index)
  }
};
// sub:
// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/submissions/1548605367/?envType=daily-question&envId=2025-02-19
// sol:
// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/solutions/6442604/1415-the-k-th-lexicographical-string-of-t6zpu/
