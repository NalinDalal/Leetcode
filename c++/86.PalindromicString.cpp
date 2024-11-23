/* 5. Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.


Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"


Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    vector<int> left(n, 0), right(n, 0);
    for (int i = 0; i < n; i++) {
      left[i] = i;
      right[i] = i;
    }
    for (int i = 1; i < n; i++) {
      while (left[i - 1] > 0 && right[i + 1] < n &&
             s[left[i - 1]] == s[right[i + 1]]) {
        left[i] = left[i - 1];
        right[i] = right[i + 1];
      }
      left[i] = max(left[i], left[i - 1] + 1);
      right[i] = max(right[i], right[i + 1] + 1);
    }
    return s.substr(left[n - 1], right[n - 1] - left[n - 1] + 1);
  }
};
// problem: TLE
/* Logic for Expanding Around the Center:

The logic for expanding around the center while checking for a palindrome is
flawed. Specifically, the condition right[i + 1] < n in the while loop is
incorrect, as i + 1 can go out of bounds. Usage of left and right Arrays:

The left and right arrays are intended to track the bounds of the palindrome
centered at each index. However, the way they are updated is not consistent with
palindrome expansion logic. Incorrect Substring Extraction:

The substring is extracted using s.substr(left[n - 1], right[n - 1] - left[n -
1] + 1), but the left and right values do not accurately represent the bounds of
the longest palindrome*/

class Solution2 {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    if (n == 0)
      return "";

    int start = 0, maxLength = 1;

    // Helper function to expand around the center
    auto expandAroundCenter = [&](int left, int right) {
      while (left >= 0 && right < n && s[left] == s[right]) {
        if (right - left + 1 > maxLength) {
          start = left;
          maxLength = right - left + 1;
        }
        left--;
        right++;
      }
    };

    for (int i = 0; i < n; ++i) {
      // Odd-length palindromes
      expandAroundCenter(i, i);

      // Even-length palindromes
      if (i + 1 < n) {
        expandAroundCenter(i, i + 1);
      }
    }

    return s.substr(start, maxLength);
  }
};

/*Explanation
1.Expand Around Center:
    For each index i in the string:
        Consider i as the center for odd-length palindromes.
        Consider i and i + 1 as the center for even-length palindromes.
2. Update Start and Max Length:
During the expansion, if the length of the current palindrome exceeds the
previous maximum, update start and maxLength.

3. Return the Longest Palindromic Substring:
After processing all potential centers, extract the substring from start with
length maxLength.*/

// Time Complexity: O(n^2), as for each character we potentially expand across
// the entire string. Space Complexity: O(1)

// More Optimised: Manacher's Algorithm

class Solution3 {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    if (n == 0)
      return "";

    // Preprocess the string to handle both odd and even length palindromes
    string modified = "#";
    for (char c : s) {
      modified += c;
      modified += "#";
    }
    int m = modified.size();

    vector<int> p(m, 0); // Array to store the radius of palindromes
    int center = 0, rightBoundary = 0;

    // Manacher's algorithm to calculate the radius of the palindrome at each
    // center
    for (int i = 0; i < m; ++i) {
      // Use the previously computed palindrome to minimize comparisons
      if (i < rightBoundary) {
        p[i] = min(rightBoundary - i, p[2 * center - i]);
      }

      // Expand around the center
      while (i + p[i] + 1 < m && i - p[i] - 1 >= 0 &&
             modified[i + p[i] + 1] == modified[i - p[i] - 1]) {
        p[i]++;
      }

      // Update the center and right boundary
      if (i + p[i] > rightBoundary) {
        center = i;
        rightBoundary = i + p[i];
      }
    }

    // Find the maximum length palindrome
    int maxLen = 0, centerIndex = 0;
    for (int i = 0; i < m; ++i) {
      if (p[i] > maxLen) {
        maxLen = p[i];
        centerIndex = i;
      }
    }

    // Extract the original palindrome from the modified string
    int start = (centerIndex - maxLen) / 2; // Map back to original string
    return s.substr(start, maxLen);
  }
};

/* Explanation
Preprocessing:

Insert special characters (#) between characters of the original string to
handle odd and even-length palindromes uniformly. For example, "abba" becomes
"#a#b#b#a#". Palindrome Radius Array:

Use the p array to store the radius of the palindrome centered at each index in
the modified string. Utilize Symmetry:

For each center i, use the symmetry of palindromes around the current center to
minimize expansions. If i is within the right boundary of the current known
palindrome, initialize p[i] using the value of its mirror. Expansion:

Expand the palindrome centered at i while characters match.
Update Boundaries:

Update the center and right boundary of the current largest palindrome.
Extract Result:

Find the index of the maximum radius in p, map it back to the original string,
and return the substring.*/

// Time Complexity: O(n)
// Space Complexity: O(n)

int main() {
  cout << "Approach 1: Expand Around Center" << endl;
  Solution expandCenter;

  string s1 = "babad";
  cout << "Example 1:" << endl;
  cout << "Input: " << s1 << endl;
  cout << "Expected Output: 'bab' or 'aba', Your Output: "
       << expandCenter.longestPalindrome(s1) << endl;

  string s2 = "cbbd";
  cout << "Example 2:" << endl;
  cout << "Input: " << s2 << endl;
  cout << "Expected Output: 'bb', Your Output: "
       << expandCenter.longestPalindrome(s2) << endl;

  cout << endl;

  cout << "Approach 2: Manacher's Algorithm" << endl;
  Solution2 manacher;

  cout << "Example 1:" << endl;
  cout << "Input: " << s1 << endl;
  cout << "Expected Output: 'bab' or 'aba', Your Output: "
       << manacher.longestPalindrome(s1) << endl;

  cout << "Example 2:" << endl;
  cout << "Input: " << s2 << endl;
  cout << "Expected Output: 'bb', Your Output: "
       << manacher.longestPalindrome(s2) << endl;

  cout << endl;

  cout << "Approach 3: Combined Solution" << endl;
  Solution3 combined;

  cout << "Example 1:" << endl;
  cout << "Input: " << s1 << endl;
  cout << "Expected Output: 'bab' or 'aba', Your Output: "
       << combined.longestPalindrome(s1) << endl;

  cout << "Example 2:" << endl;
  cout << "Input: " << s2 << endl;
  cout << "Expected Output: 'bb', Your Output: "
       << combined.longestPalindrome(s2) << endl;

  return 0;
}
