/* https://leetcode.com/problems/word-subsets/description/
916. Word Subsets

You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including
multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a
subset of a.

Return an array of all the universal strings in words1. You may return the
answer in any order.



Example 1:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 =
["e","o"] Output: ["facebook","google","leetcode"] Example 2:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 =
["l","e"] Output: ["apple","google","leetcode"]


Constraints:

1 <= words1.length, words2.length <= 104
1 <= words1[i].length, words2[i].length <= 10
words1[i] and words2[i] consist only of lowercase English letters.
All the strings of words1 are unique.
*/
// every word of words2 occur in words1 then words2 is substr of words1
// words2=words1.substr(0.size()-1);
// new vector substr; if condition satisfy then push_back
// return that substr;
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<int> maxFreq(26, 0); // Maximum frequency of each character needed
                                // across all words in words2

    // Calculate maxFreq by combining character counts from words2
    for (const string& word : words2) {
      vector<int> freq(26, 0);
      for (char c : word) {
        freq[c - 'a']++;
      }
      for (int i = 0; i < 26; ++i) {
        maxFreq[i] = max(maxFreq[i], freq[i]);
      }
    }

    vector<string> result;

    // Check each word in words1
    for (const string& word : words1) {
      vector<int> freq(26, 0);
      for (char c : word) {
        freq[c - 'a']++;
      }

      bool isUniversal = true;
      for (int i = 0; i < 26; ++i) {
        if (freq[i] < maxFreq[i]) {
          isUniversal = false;
          break;
        }
      }

      if (isUniversal) {
        result.push_back(word);
      }
    }

    return result;
  }
};

// 62%
// O(n^2)
// O(1)
// https://leetcode.com/problems/word-subsets/solutions/6259821/916-word-subsets625-by-nalindalal2004-ko1x/
