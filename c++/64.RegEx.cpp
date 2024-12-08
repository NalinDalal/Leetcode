/* 10. Regular Expression Matching

Given an input string s and a pattern p, implement regular expression matching
with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).


Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by
repeating 'a' once, it becomes "aa".

Example 3:
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".


Constraints:
1 <= s.length <= 20
1 <= p.length <= 20
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a
previous valid character to match.
*/

/*
. -> single character
* -> any no of copy of preceeding elements

either check p with s char by char
or . -> a,b both
* -> n no of copy of both a,b
*/

/* Common Regex Patterns:
Literal Characters: Match exactly what you type, e.g., abc matches the string
"abc". Metacharacters: Special characters with specific functions: . : Matches
any single character except a newline.
* : Matches 0 or more occurrences of the previous element.
+ : Matches 1 or more occurrences of the previous element.
? : Matches 0 or 1 occurrence of the previous element (makes it optional).
^ : Asserts the position at the start of a line.
$ : Asserts the position at the end of a line.
\d : Matches any digit (equivalent to [0-9]).
\w : Matches any word character (equivalent to [a-zA-Z0-9_]).
\s : Matches any whitespace character (spaces, tabs, etc.).
[] : Matches any single character within the brackets.
| : Logical OR for alternatives, e.g., cat|dog matches either "cat" or "dog".
( ) : Groups expressions, and captures matched text.
Examples:
Simple Match:

Pattern: hello
Matches: "hello" in the string "Say hello to everyone."
Match Digits:

Pattern: \d+
Matches: Any sequence of digits (e.g., "123" in "Your order is 12345.")
Email Matching:

Pattern: \b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b
Matches: Email addresses (e.g., "example@mail.com").
Phone Number Match:

Pattern: \(?\d{3}\)?[-.\s]?\d{3}[-.\s]?\d{4}
Matches: Phone numbers in formats like (123) 456-7890, 123-456-7890, or
123.456.7890. URL Matching:

Pattern: https?:\/\/(www\.)?[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}
Matches: URLs like "http://example.com" or "https://www.example.org".
*/

/* dp Table Initialization: We create a DP table of size (len(s)+1) x (len(p)+1)
initialized to False. The first element (dp[0][0]) is True because an empty
string matches an empty pattern. Pattern with *: We handle cases where the
pattern has * that can match zero occurrences of the previous element. Filling
the Table: We then iterate through the string s and the pattern p, filling in
the DP table based on the rules for . and *. If the characters match (s[i-1] ==
p[j-1]) or the pattern has a .. If the pattern has a *, we check whether the
preceding element matches zero times (dp[i][j-2]) or one or more times
(dp[i-1][j]).


*/

// Time Complexity: O(m * n), where m is the length of the string s and n is the
// length of the pattern p, because we fill up a DP table of size m x n. Space
// Complexity: O(m * n) for the DP table.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isMatch(const string& s, const string& p) {
  int m = s.length(), n = p.length();

  // dp[i][j] will be true if s[0:i] matches p[0:j]
  vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

  // Base case: empty string and empty pattern match
  dp[0][0] = true;

  // Handle patterns like a*, a*b*, a*b*c* which can match an empty string
  for (int j = 2; j <= n; ++j) {
    if (p[j - 1] == '*') {
      dp[0][j] = dp[0][j - 2];
    }
  }

  // Fill the dp table
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
        // If characters match or pattern has a '.', propagate the result from
        // the previous state
        dp[i][j] = dp[i - 1][j - 1];
      } else if (p[j - 1] == '*') {
        // Consider two cases:
        // 1. Zero occurrences of the character before '*'
        dp[i][j] = dp[i][j - 2];

        // 2. One or more occurrences if the character matches
        if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
          dp[i][j] = dp[i][j] || dp[i - 1][j];
        }
      }
    }
  }

  // The final result is whether the entire string matches the entire pattern
  return dp[m][n];
}

int main() {
  // Example 1:
  string s1 = "aa";
  string p1 = "a";
  cout << (isMatch(s1, p1) ? "true" : "false") << endl; // Output: false

  // Example 2:
  string s2 = "aa";
  string p2 = "a*";
  cout << (isMatch(s2, p2) ? "true" : "false") << endl; // Output: true

  // Example 3:
  string s3 = "ab";
  string p3 = ".*";
  cout << (isMatch(s3, p3) ? "true" : "false") << endl; // Output: true

  return 0;
}
