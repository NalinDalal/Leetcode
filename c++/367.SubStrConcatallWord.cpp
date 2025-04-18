/* 30. Substring with Concatenation of All Words
You are given a string s and an array of strings words. All the strings of words
are of the same length.

A concatenated string is a string that exactly contains all the strings of any
permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef",
"cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a
concatenated string because it is not the concatenation of any permutation of
words. Return an array of the starting indices of all the concatenated
substrings in s. You can return the answer in any order.



Example 1:
Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation:
The substring starting at 0 is "barfoo". It is the concatenation of
["bar","foo"] which is a permutation of words. The substring starting at 9 is
"foobar". It is the concatenation of ["foo","bar"] which is a permutation of
words.

Example 2:
Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []
Explanation:
There is no concatenated substring.

Example 3:
Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
Explanation:

The substring starting at 6 is "foobarthe". It is the concatenation of
["foo","bar","the"]. The substring starting at 9 is "barthefoo". It is the
concatenation of ["bar","the","foo"]. The substring starting at 12 is
"thefoobar". It is the concatenation of ["the","foo","bar"].



Constraints:
1 <= s.length <= 104
1 <= words.length <= 5000
1 <= words[i].length <= 30
s and words[i] consist of lowercase English letters. */

// Return all starting indices in s where a concatenation of all the words in
// words appears exactly once, without any intervening characters

// so do like concat all permutations, now if you encounter a complete
// permutation in the s then return the index where it starts
// return all indices where permutation combination is encountered.

/* Each word has the same length.

You need to look at all substrings of s of length total_len = words.len() *
word_len.

For each substring, break it into word_len chunks and check if it matches the
frequency of words in words.
*/

// optimisation:
/* We loop through wordLen offsets (0 to wordLen - 1) to ensure alignment.

Within each window, we maintain a frequency map of words seen and adjust the
window as needed.

Avoids rebuilding substring maps from scratch every time (huge performance
boost).
 */

class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    if (words.empty() || s.empty())
      return res;

    int wordLen = words[0].size();
    int wordCount = words.size();
    int totalLen = wordLen * wordCount;
    int n = s.size();

    unordered_map<string, int> wordFreq;
    for (const string& word : words)
      wordFreq[word]++;

    for (int i = 0; i < wordLen; i++) { // i is offset for sliding window
      int left = i, count = 0;
      unordered_map<string, int> window;

      for (int j = i; j + wordLen <= n; j += wordLen) {
        string word = s.substr(j, wordLen);

        if (wordFreq.find(word) != wordFreq.end()) {
          window[word]++;
          count++;

          while (window[word] > wordFreq[word]) {
            string leftWord = s.substr(left, wordLen);
            window[leftWord]--;
            left += wordLen;
            count--;
          }

          if (count == wordCount) {
            res.push_back(left);
          }
        } else {
          window.clear();
          count = 0;
          left = j + wordLen;
        }
      }
    }

    return res;
  }
};

// sub:
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/submissions/1610118074/?envType=study-plan-v2&envId=top-interview-150
// sol:
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/solutions/6662226/30-substring-with-concatenation-of-all-w-wzh0/
