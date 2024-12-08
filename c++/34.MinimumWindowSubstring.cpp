/*
 76. Minimum Window Substring
Hard
Given two strings s and t of lengths m and n respectively, return the minimum
window substring of s such that every character in t (including duplicates) is
included in the window. If there is no such substring, return the empty string
"".

The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from
string t.


Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.


Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window. Since the largest
window of s only has one 'a', return empty string.


Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.


Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

// Algorithm
/*
 Key Concepts
Sliding Window Technique:

We maintain two pointers (left and right) to track the current window in string
s. We expand the window by moving the right pointer and add characters to a
frequency map (windowFreq). Once the window contains all characters from string
t, we try to shrink it from the left (left pointer) while maintaining the
validity of the window (i.e., it still contains all characters from t). Hashmaps
for Frequency Count:

targetFreq: This hashmap stores the frequency of each character in string t.
windowFreq: This hashmap keeps track of the frequency of characters in the
current window of string s. These maps help in checking whether the current
window satisfies the requirements (i.e., contains all characters from t with at
least the required frequencies). Valid Window Check:

The variable formed keeps track of how many unique characters from t have been
fully included in the current window. Once formed == required (i.e., all
characters from t are in the window), we try to shrink the window to find the
smallest possible window that still contains all characters from t. Result:

If a valid window is found, we keep track of the smallest window by updating
minLength and minWindowStart. At the end, if no valid window was found, return
an empty string. Otherwise, return the substring that represents the smallest
window.

*/

// Space complexity: O(n)
// Time complexity: O(n)
#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    if (s.empty() || t.empty()) {
      return "";
    }

    // Frequency map for characters in t
    unordered_map<char, int> targetFreq;
    for (char c : t) {
      targetFreq[c]++;
    }

    // Variables to track the window
    unordered_map<char, int> windowFreq;
    int left = 0, right = 0, formed = 0;
    int required = targetFreq.size(); // Number of unique characters needed
    int minLength = INT_MAX;          // Track the length of the smallest window
    int minWindowStart = 0; // Track the start index of the smallest window

    // Slide the window
    while (right < s.size()) {
      // Expand the window by including the character at 'right'
      char charRight = s[right];
      windowFreq[charRight]++;

      // If the current character in the window satisfies its count in target
      if (targetFreq.count(charRight) &&
          windowFreq[charRight] == targetFreq[charRight]) {
        formed++;
      }

      // Try to contract the window from the left while the window is valid
      while (formed == required) {
        // Update the minimum window size and starting index
        if (right - left + 1 < minLength) {
          minLength = right - left + 1;
          minWindowStart = left;
        }

        // Try to reduce the size by removing the character at 'left'
        char charLeft = s[left];
        windowFreq[charLeft]--;

        // If the character count in the window is less than required in target,
        // reduce the 'formed' count
        if (targetFreq.count(charLeft) &&
            windowFreq[charLeft] < targetFreq[charLeft]) {
          formed--;
        }

        // Move the left pointer to shrink the window
        left++;
      }

      // Move the right pointer to expand the window
      right++;
    }

    // Return the smallest window or an empty string if no such window exists
    return minLength == INT_MAX ? "" : s.substr(minWindowStart, minLength);
  }
};
