/* 2014. Longest Subsequence Repeated k Times
You are given a string s of length n, and an integer k. You are tasked to find
the longest subsequence repeated k times in string s.

A subsequence is a string that can be derived from another string by deleting
some or no characters without changing the order of the remaining characters.

A subsequence seq is repeated k times in the string s if seq * k is a
subsequence of s, where seq * k represents a string constructed by concatenating
seq k times.

For example, "bba" is repeated 2 times in the string "bababcba", because the
string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of
the string "bababcba". Return the longest subsequence repeated k times in string
s. If multiple such subsequences are found, return the lexicographically largest
one. If there is no such subsequence, return an empty string.



Example 1:

example 1
Input: s = "letsleetcode", k = 2
Output: "let"
Explanation: There are two longest subsequences repeated 2 times: "let" and
"ete". "let" is the lexicographically largest one. Example 2:

Input: s = "bb", k = 2
Output: "b"
Explanation: The longest subsequence repeated 2 times is "b".
Example 3:

Input: s = "ab", k = 2
Output: ""
Explanation: There is no subsequence repeated 2 times. Empty string is returned.


Constraints:

n == s.length
2 <= n, k <= 2000
2 <= n < k * 8
s consists of lowercase English letters.


Hint 1
The length of the longest subsequence does not exceed n/k. Do you know why?
Hint 2
Find the characters that could be included in the potential answer. A character
occurring more than or equal to k times can be used in the answer up to (count
of the character / k) times. Hint 3 Try all possible candidates in reverse
lexicographic order, and check the string for the subsequence condition.
*/

// return longest subsequence in string s which is repeated k times
// Therefore, the characters that make up this subsequence must appear at least
// k times in s. Characters that appear fewer than k times in s can be filtered
// out directly.

// Approach:
/*1. total size be n, now we require k count, so maxlength of such
sequnce<=floor(n/k)
2. given n<8k, length can be max 7, hence candidate subsequnce are
pow(2,7)=128{brute force can be used here}
3. start by counting the frequency of each character to identify those that meet
the required threshold
4. enumerate all possible permutations formed from any combination of these
characters.
5. for each permutation we check whether it appears in s at least k times.
6. return the max length one

7. permutation:
    - use a queue to store
    Each time, we pop the current valid subsequence curr from the queue and
attempt to append a valid character c to form a new string next. If next appears
in s at least k times, we push it into the queue to continue expanding it.
    enumerate in reverse lexorder, so that maxLength is at first
*/

class Solution {
public:
  string longestSubsequenceRepeatedK(string s, int k) {
    vector<int> freq(26);
    for (char ch : s) {
      freq[ch - 'a']++;
    }
    vector<char> candidate;
    for (int i = 25; i >= 0; i--) {
      if (freq[i] >= k) {
        candidate.push_back('a' + i);
      }
    }
    queue<string> q;
    for (char ch : candidate) {
      q.push(string(1, ch));
    }

    string ans = "";
    while (!q.empty()) {
      string curr = q.front();
      q.pop();
      if (curr.size() > ans.size()) {
        ans = curr;
      }
      // generate the next candidate string
      for (char ch : candidate) {
        string next = curr + ch;
        if (isKRepeatedSubsequence(s, next, k)) {
          q.push(next);
        }
      }
    }

    return ans;
  }

  bool isKRepeatedSubsequence(const string& s, const string& t, int k) {
    int pos = 0, matched = 0;
    int n = s.size(), m = t.size();
    for (char ch : s) {
      if (ch == t[pos]) {
        pos++;
        if (pos == m) {
          pos = 0;
          matched++;
          if (matched == k) {
            return true;
          }
        }
      }
    }

    return false;
  }
};

// Time: \( O(n \cdot \lfloor \frac{n}{k} \rfloor !) \).
// Space: \( O(\lfloor \frac{n}{k} \rfloor !) \).
// sub:
// https://leetcode.com/problems/longest-subsequence-repeated-k-times/submissions/1677974161/?envType=daily-question&envId=2025-06-27
// sol:
// https://leetcode.com/problems/longest-subsequence-repeated-k-times/solutions/6890835/2014-longest-subsequence-repeated-k-time-yiis/
