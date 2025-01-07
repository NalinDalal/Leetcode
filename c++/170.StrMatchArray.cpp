// https://leetcode.com/problems/string-matching-in-an-array/description/?envType=daily-question&envId=2025-01-07
/* 1408. String Matching in an Array

Given an array of string words, return all strings in words that is a substring
of another word. You can return the answer in any order.

A substring is a contiguous sequence of characters within a string


Example 1:
Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.

Example 2:
Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".

Example 3:
Input: words = ["blue","green","bu"]
Output: []
Explanation: No string of words is substring of another string.


Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 30
words[i] contains only lowercase English letters.
All the strings of words are unique.*/

class Solution {
public:
  vector<string> stringMatching(vector<string>& words) {
    // if say arr[i] is substr of arr[j], then push it to ans array
    // return ans
    vector<string> ans;
    // Iterate through all pairs of words
    for (int i = 0; i < words.size(); ++i) {
      for (int j = 0; j < words.size(); ++j) {
        if (i != j && words[j].find(words[i]) != string::npos) {
          ans.push_back(words[i]);
          break; // Avoid duplicate entries
        }
      }
    }

    return ans;
  }
};
