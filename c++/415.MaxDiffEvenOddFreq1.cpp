/* 3442. Maximum Difference Between Even and Odd Frequency I
You are given a string s consisting of lowercase English letters.

Your task is to find the maximum difference diff = a1 - a2 between the frequency
of characters a1 and a2 in the string such that:

a1 has an odd frequency in the string.
a2 has an even frequency in the string.
Return this maximum difference.



Example 1:

Input: s = "aaaaabbc"

Output: 3

Explanation:

The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2.
The maximum difference is 5 - 2 = 3.
Example 2:

Input: s = "abcabcab"

Output: 1

Explanation:

The character 'a' has an odd frequency of 3, and 'c' has an even frequency of 2.
The maximum difference is 3 - 2 = 1.


Constraints:

3 <= s.length <= 100
s consists only of lowercase English letters.
s contains at least one character with an odd frequency and one with an even
frequency.

Hint 1
Use a frequency map to identify the maximum odd and minimum even frequencies.
Then, calculate their difference.
*/

class Solution {
public:
  int maxDifference(string s) {
    // find frequency of each char
    // find all odd and even
    // calculate max diff

    unordered_map<char, int> freq;

    // Count frequency of each character
    for (char c : s) {
      freq[c]++;
    }
    vector<int> oddFreqs, evenFreqs;

    // Separate odd and even frequencies
    for (auto& entry : freq) {
      if (entry.second % 2 == 0) {
        evenFreqs.push_back(entry.second);
      } else {
        oddFreqs.push_back(entry.second);
      }
    }

    // If there's no valid odd-even pair
    if (oddFreqs.empty() || evenFreqs.empty()) {
      return -1; // Adjust based on problem requirements
    }

    // Find the maximum difference
    int maxDiff = INT_MIN;
    for (int odd : oddFreqs) {
      for (int even : evenFreqs) {
        maxDiff = max(maxDiff, odd - even);
      }
    }

    return maxDiff;
  }
};

// sub:
// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/submissions/1528123503/?envType=daily-question&envId=2025-06-10
// sol:
// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/solutions/6827928/3442-maximum-difference-between-even-and-m7j6/
