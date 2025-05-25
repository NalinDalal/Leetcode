/* 2131. Longest Palindrome by Concatenating Two Letter Words
You are given an array of strings words. Each element of words consists of two
lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and
concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is
impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.



Example 1:
Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of
length 6. Note that "clgglc" is another longest palindrome that can be created.

Example 2:
Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt",
of length 8. Note that "lcyttycl" is another longest palindrome that can be
created.

Example 3:
Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is
"xx".


Constraints:
1 <= words.length <= 105
words[i].length == 2
words[i] consists of lowercase English letters. */

// given an array, find length of longest word which can be created from array
// so that it's palindrome
/* 1. store all the strings from words into a hashmap so that we can access
 * their frequencies easily.
 * 2. reverse the words[i]; check if present, else add it; traverse over every
 * words[i] and create its reversed copy in s while traversing.
 * 3. check if words[i] is palindrome or not; if then check freq >=2(even) add
 * it both left,right; else for odd add in middle
 * 4. str, rev prsent so pre-pend, append respectively; count the length
 * increment on picking the maximum non-palindromic string pairs (w, its
 * reverse) possible.
 * 5. return Total Count + (If inserting a palindromic string in the middle is
 * possible ? 2 : 0)
 */

class Solution {
public:
  int longestPalindrome(vector<string>& words) {
    unordered_map<string, int> mpp; // 1.
    for (string w : words)
      mpp[w]++;
    int count = 0, alreadyPalindrome = 0;
    for (auto& [w, freq] : mpp) { // 2.
      string s = w;
      reverse(s.begin(), s.end());
      if (w == s) { // 3.
        count += (freq / 2) * 4;
        if (freq % 2)
          alreadyPalindrome = 1;
      } else if (w < s && mpp.count(s)) { // 4.
        count += min(freq, mpp[s]) * 4;
      }
    }
    return count + alreadyPalindrome * 2; // 5.
  }
};
// sub:
// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/submissions/1643718140/?envType=daily-question&envId=2025-05-25
// sol:
// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/solutions/6778561/2131-longest-palindrome-by-concatenating-allf/
