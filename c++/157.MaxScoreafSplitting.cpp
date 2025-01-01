/* 1422. Maximum Score After Splitting a String

Given a string s of zeros and ones, return the maximum score after splitting the
string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring
plus the number of ones in the right substring.



Example 1:
Input: s = "011101"
Output: 5
Explanation:
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5
left = "01" and right = "1101", score = 1 + 3 = 4
left = "011" and right = "101", score = 1 + 2 = 3
left = "0111" and right = "01", score = 1 + 1 = 2
left = "01110" and right = "1", score = 2 + 1 = 3

Example 2:
Input: s = "00111"
Output: 5
Explanation: When left = "00" and right = "111", we get the maximum score = 2 +
3 = 5

Example 3:
Input: s = "1111"
Output: 3


Constraints:
2 <= s.length <= 500
The string s consists of characters '0' and '1' only.*/

class Solution {
public:
  int maxScore(string s) {
    // split string into two substring
    // count no of zero in left and 1 in right substring
    // Calculate the score as leftZeros + rightOnes for each split.

    // return max score
    int maxScore = 0;

    // Iterate through possible split positions
    for (int i = 1; i < s.length(); ++i) {
      // Left and right substrings
      string left = s.substr(0, i);
      string right = s.substr(i);

      // Count zeros in the left substring
      int leftZeros = count(left.begin(), left.end(), '0');

      // Count ones in the right substring
      int rightOnes = count(right.begin(), right.end(), '1');

      // Calculate the score for this split
      int score = leftZeros + rightOnes;

      // Update the maximum score
      maxScore = max(maxScore, score);
    }

    return maxScore;
  }
};

// optimisation:
/*1. Precompute Total Ones:
- First, calculate the total number of ones in the string, as this won't change
regardless of the split.
2. Single Pass:
- Traverse the string from left to right.
- Keep track of the count of zeros on the left and dynamically calculate the
score by adding leftZeros and the remaining ones on the right (totalOnes -
rightOnes).
3. Skip Last Split:
- The split at the last character is invalid (the right substring would be
empty), so stop at s.length() - 1.*/
class Solution1 {
public:
  int maxScore(string s) {
    int totalOnes = 0;
    int leftZeros = 0, rightOnes = 0;
    int maxScore = 0;

    // Count total number of ones in the string
    for (char c : s) {
      if (c == '1') {
        totalOnes++;
      }
    }

    // Traverse the string and calculate the score dynamically
    for (int i = 0; i < s.length() - 1; ++i) {
      if (s[i] == '0') {
        leftZeros++; // Increment left zeros
      } else {
        rightOnes++; // Increment right ones
      }

      // Calculate score: left zeros + remaining right ones
      maxScore = max(maxScore, leftZeros + (totalOnes - rightOnes));
    }

    return maxScore;
  }
};
// Time: O(n)
// Space: O(1)
