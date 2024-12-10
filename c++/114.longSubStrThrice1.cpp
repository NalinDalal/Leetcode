/* 2981. Find Longest Special Substring That Occurs Thrice I

You are given a string s that consists of lowercase English letters.

A string is called special if it is made up of only a single character. For
example, the string "abc" is not special, whereas the strings "ddd", "zz", and
"f" are special.

Return the length of the longest special substring of s which occurs at least
thrice, or -1 if no special substring occurs at least thrice.

A substring is a contiguous non-empty sequence of characters within a string.



Example 1:
Input: s = "aaaa"
Output: 2
Explanation: The longest special substring which occurs thrice is "aa":
substrings "aaaa", "aaaa", and "aaaa". It can be shown that the maximum length
achievable is 2.

Example 2:
Input: s = "abcdef"
Output: -1
Explanation: There exists no special substring which occurs at least thrice.
Hence return -1.

Example 3:
Input: s = "abcaba"
Output: 1
Explanation: The longest special substring which occurs thrice is "a":
substrings "abcaba", "abcaba", and "abcaba". It can be shown that the maximum
length achievable is 1.


Constraints:

3 <= s.length <= 50
s consists of only lowercase English letters. */

#include <string>
#include <vector>

using namespace std;

// what to do:
//  1. create a vector of size 26 to store the count of each character
// 2. iterate through the string and for each character, increment the count of
// that character
//  3. iterate through the vector and find the character with the highest count
//  4. if the highest count is less than 3, return -1
//  5. else return the length of the string from the index of the character to
//  the end

/* class Solution {
public:
  int maximumLength(string s) {
    vector<int> count(26, 0);
    for (int i = 0; i < s.length(); i++) {
      count[s[i] - 'a']++;
    }
    int max = 0;
    for (int i = 0; i < 26; i++) {
      if (count[i] >= 3) {
        if (count[i] > max) {
          max = count[i];
        }
      }
    }
    // if max<3, return -1
    return max >= 3 ? s.length() - max : s.length();
  }
}; */

// Approach:
// 1. maximum length of a substring for which each character in the substring
// appears at least 3 times
// 2. first handle the edge cases, like empty string, length of str is less than
// other 2.
// 3. find char with highest count
// 4. if (count<3)   return -1;
// 5. else {return str.size()-count;}

/* 1. Initialize Top-3 Frequencies: Use a 2D array top3freq to store the top-3
longest substring lengths for each character ('a' to 'z').
2. Sliding Window Logic:
- Track the length of consecutive characters (win_len).
- If the current character is the same as the last seen character, increase the
window length.
- Otherwise, reset the window length to 1 and update the last seen character.

3. Update Top-3 Frequencies:
- For the current character, find the smallest value among its top-3
frequencies.
- Replace the smallest value if the current window length is greater.

4. Find Maximum Length:
- For each character, take the smallest of its top-3 frequencies.
- Track the largest of these minimum values.

5. Return Result:
- The final maximum value is the answer, representing the longest substring
where each character appears at least 3 times.*/

class Solution {
  int& getMin(int& a, int& b, int& c) {
    if (a <= b and a <= c)
      return a;
    if (b <= a and b <= c)
      return b;
    return c;
  }

public:
  int maximumLength(string s) {
    int n = s.size();
    vector<vector<int>> top3freq(26, vector<int>(3, -1));

    // Find top-3 substring length for each character (a to z)
    char last_seen = '*';
    int win_len = 0;
    for (char& curr : s) {
      int idx = curr - 'a';
      win_len = curr == last_seen ? win_len + 1 : 1;
      last_seen = curr;
      int& minimum =
          getMin(top3freq[idx][0], top3freq[idx][1], top3freq[idx][2]);
      if (win_len > minimum)
        minimum = win_len;
    }

    // Find the maxLen of substring
    int maxLen = -1;
    for (int i = 0; i < 26; ++i)
      maxLen =
          max(maxLen, min({top3freq[i][0], top3freq[i][1], top3freq[i][2]}));

    return maxLen;
  }
};

// Time: O(n)
// Space: O(1)
