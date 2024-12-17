/* 2182. Construct String With Repeat Limit

You are given a string s and an integer repeatLimit. Construct a new string
repeatLimitedString using the characters of s such that no letter appears more
than repeatLimit times in a row. You do not have to use all characters from s.

Return the lexicographically largest repeatLimitedString possible.

A string a is lexicographically larger than a string b if in the first position
where a and b differ, string a has a letter that appears later in the alphabet
than the corresponding letter in b. If the first min(a.length, b.length)
characters do not differ, then the longer string is the lexicographically larger
one.



Example 1:
Input: s = "cczazcc", repeatLimit = 3
Output: "zzcccac"
Explanation: We use all of the characters from s to construct the
repeatLimitedString "zzcccac". The letter 'a' appears at most 1 time in a row.
The letter 'c' appears at most 3 times in a row.
The letter 'z' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is
a valid repeatLimitedString. The string is the lexicographically largest
repeatLimitedString possible so we return "zzcccac". Note that the string
"zzcccca" is lexicographically larger but the letter 'c' appears more than 3
times in a row, so it is not a valid repeatLimitedString.

Example 2:
Input: s = "aababab", repeatLimit = 2
Output: "bbabaa"
Explanation: We use only some of the characters from s to construct the
repeatLimitedString "bbabaa". The letter 'a' appears at most 2 times in a row.
The letter 'b' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is
a valid repeatLimitedString. The string is the lexicographically largest
repeatLimitedString possible so we return "bbabaa". Note that the string
"bbabaaa" is lexicographically larger but the letter 'a' appears more than 2
times in a row, so it is not a valid repeatLimitedString.


Constraints:
1 <= repeatLimit <= s.length <= 105
s consists of lowercase English letters.*/

/* class Solution {
public:
  string repeatLimitedString(string s, int repeatLimit) {
    string ans = "";
    int n = s.size();
    for (int i = 0; i < n; i++) {
      int count = 0;
      for (int j = i; j < n; j++) {
        if (s[i] == s[j]) {
          count++;
        } else {
          break;
        }
      }
    }
    if (count <= repeatLimit) {
      ans += s[i];
    }
  }
};*/

// Intuition:
// Sort the string to be lexicographically largest
// Swap characters that are repeated too many times
class Solution {
public:
  string repeatLimitedString(string s, int repeatLimit) {
    vector<int> cnt(26, 0);
    for (auto& x : s)
      cnt[x - 'a'] += 1;
    string res = "";
    int rep = 0;
    while (true) {
      bool found = false;
      for (char c = 'z'; c >= 'a'; c--) {
        if (cnt[c - 'a'] == 0)
          continue;
        if (res.size() > 0 && (res.back() == c) && rep == repeatLimit)
          continue;
        if (res.size() > 0) {
          rep = res.back() == c ? rep + 1 : 1;
        } else {
          rep = 1;
        }
        res.push_back(c);
        found = true;
        cnt[c - 'a'] -= 1;
        break;
      }
      if (!found)
        break;
    }
    return res;
  }
};

/*# Approach
1. The repeatLimitedString function takes two parameters: s (the input string)
and repeatLimit (the maximum number of times a character can be repeated).
2. It initializes an array hash of size 26 to store the frequency of each
character in the input string s. It also initializes a variable size to keep
track of the length of the input string.
3. The first loop iterates over the characters in s and updates the hash array
and the size variable accordingly.
4. The second loop iterates over the hash array and builds the sorted string s
by appending the characters in decreasing order of their ASCII values.
5. The third loop iterates over the string s starting from the second character.
For each character, it checks if the current character is the same as the
previous character. If so, it increments the repeated variable. If repeated is
equal to repeatLimit, it finds the next character that is lexicographically
smaller than the current character and swaps the two.
6. Finally, the function returns the modified string s.
*/

// Time complexity: O(n)
// Space complexity: O(1)

// 81%
