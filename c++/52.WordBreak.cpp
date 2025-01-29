/*
139. Word Break

Given a string s and a dictionary of strings wordDict, return true if s can be
segmented into a space-separated sequence of one or more dictionary words. Note
that the same word in the dictionary may be reused multiple times in the
segmentation.

Example 1:
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen
apple". Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false


Constraints:
1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
*/

// check if s can be breaked down into wordDict

// Approach:
/*
see we can do one thing, check wordDict with s and return true upon comparing if
it matches, else return false also what if we merge wordDict and then compare
word by word with s?

but there can be problem: how to split?
*/

// Approach:
/*Start at first position
 * decision tree
 * 1 tree for leet
 * 2nd for code
 * i=0(leet)-> check(runs)
 * leet(i=0)-> i=4{neet,leet,code}-> code runs{i=8}
 * entire string runs{return true}
 * else{return false}
 */
/*
dp[i] represents whether the substring s[i:] (from index i to the end) can be
segmented into words from wordDict.

The base case is dp[len(s)] = True, which means that an empty string can always
be segmented.

For each index i in s, the code checks all words w in wordDict. If the substring
starting at i matches w and the remainder of the string s[i + len(w):] can be
segmented (i.e., dp[i + len(w)] is True), then dp[i] is set to True.

If a match is found for any word, it breaks out of the loop, as we only need one
valid segmentation for that position.
 */
/*
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -› bool:
        dp = [False] * (len(s) + 1)
        dp[len(s)] = True

        for i in range(len(s) - 1, -1, -1):
            for w in wordDict:
                if (i + len(w)) <= len(s) and s[i : i + len (w)] == w:
                    dp[i] = dp[i + len(w)]
                if dp[i]:
                        break

        return dp[0]
    */
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
    std::unordered_set<std::string> wordSet(
        wordDict.begin(),
        wordDict.end()); // unordered_set is used to store wordDict for O(1)
                         // average-time complexity lookup
    std::vector<bool> dp(s.size() + 1,
                         false); // dp[i] represents whether the substring s[i:]
                                 // can be segmented into words from wordDict
    dp[s.size()] = true;         // Base case: an empty suffix is always valid

    // Iterate from the end of the string to the start
    for (int i = s.size() - 1; i >= 0; --i) {
      for (const std::string& word : wordSet) {
        if (i + word.size() <= s.size() && s.substr(i, word.size()) == word) {
          dp[i] = dp[i + word.size()];
          if (dp[i]) {
            break; // No need to check further if we found a match
          }
        }
      }
    }

    return dp[0]; // Return whether the entire string can be segmented
  }
};

int main() {
  Solution solution;

  // Test case 1
  std::string s1 = "leetcode";
  std::vector<std::string> wordDict1 = {"leet", "code"};
  std::cout << "Test case 1: "
            << (solution.wordBreak(s1, wordDict1) ? "True" : "False")
            << std::endl;

  // Test case 2
  std::string s2 = "applepenapple";
  std::vector<std::string> wordDict2 = {"apple", "pen"};
  std::cout << "Test case 2: "
            << (solution.wordBreak(s2, wordDict2) ? "True" : "False")
            << std::endl;

  // Test case 3
  std::string s3 = "catsandog";
  std::vector<std::string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
  std::cout << "Test case 3: "
            << (solution.wordBreak(s3, wordDict3) ? "True" : "False")
            << std::endl;

  return 0;
}

// 75%
// sub: https://leetcode.com/problems/word-break/submissions/1428257524/
// sol:
// https://leetcode.com/problems/word-break/solutions/6343401/139-word-break75-by-nalindalal2004-pqtf/
