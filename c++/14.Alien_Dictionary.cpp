/*
*953. Verifying an Alien Dictionary
Easy
Topics
Companies
In an alien language, surprisingly, they also use English lowercase letters, but
possibly in a different order. The order of the alphabet is some permutation of
lowercase letters.

Given a sequence of words written in the alien language, and the order of the
alphabet, return true if and only if the given words are sorted
lexicographically in this alien language.



Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is
sorted. Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1],
hence the sequence is unsorted. Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is
shorter (in size.) According to lexicographical rules "apple" > "app", because
'l' > '∅', where '∅' is defined as the blank character which is less than any
other character (More info).
*/

class Solution {
public:
  bool isAlienSorted(std::vector<std::string>& words, std::string order) {
    // Create a mapping of characters to their positions in the alien alphabet
    std::unordered_map<char, int> alienOrder;
    for (int i = 0; i < order.size(); ++i) {
      alienOrder[order[i]] = i;
    }

    // Check if each adjacent pair of words is in sorted order
    for (int i = 1; i < words.size(); ++i) {
      const std::string& prev = words[i - 1];
      const std::string& current = words[i];

      // Compare each character of the two words
      int minLength = std::min(prev.size(), current.size());
      int j = 0;
      while (j < minLength && prev[j] == current[j]) {
        ++j;
      }
      // If j reaches the end of one word, and the other word still has
      // characters, then it's not sorted
      if (j == minLength && prev.size() > current.size()) {
        return false;
      }
      // If the characters at position j are not in the correct order, return
      // false
      if (j < prev.size() && j < current.size() &&
          alienOrder[prev[j]] > alienOrder[current[j]]) {
        return false;
      }
    }

    return true;
  }
};
