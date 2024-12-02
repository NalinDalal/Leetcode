/* 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence

Given a sentence that consists of some words separated by a single space, and a
searchWord, check if searchWord is a prefix of any word in sentence.

Return the index of the word in sentence (1-indexed) where searchWord is a
prefix of this word. If searchWord is a prefix of more than one word, return the
index of the first word (minimum index). If there is no such word return -1.

A prefix of a string s is any leading contiguous substring of s.

Example 1:
Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.

Example 2:
Input: sentence = "this problem is an easy problem", searchWord = "pro"
Output: 2
Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th word in
the sentence, but we return 2 as it's the minimal index.

Example 3:
Input: sentence = "i am tired", searchWord = "you"
Output: -1
Explanation: "you" is not a prefix of any word in the sentence.


Constraints:
1 <= sentence.length <= 100
1 <= searchWord.length <= 10
sentence consists of lowercase English letters and spaces.
searchWord consists of lowercase English letters.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// What are we doing here?
class Solution {
public:
  int isPrefixOfWord(string sentence, string searchWord) {
    vector<string> words;
    int i = 0;
    while (i < sentence.length()) {
      int j = i;
      while (j < sentence.length() && sentence[j] != ' ') {
        j++;
      }
      words.push_back(sentence.substr(i, j - i));
      i = j + 1;
    }
    for (int i = 0; i < words.size(); i++) {
      if (words[i].length() >= searchWord.length() &&
          words[i].substr(0, searchWord.length()) == searchWord) {
        return i + 1;
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;
  string sentence1 = "i love eating burger ", searchWord1 = " burg ";
  cout << sol.isPrefixOfWord(sentence1, searchWord1) << endl;

  string sentence2 = "this problem is an easy problem", searchWord2 = "pro";
  cout << sol.isPrefixOfWord(sentence2, searchWord2) << endl;

  string sentence3 = "i am tired", searchWord3 = "you";
  cout << sol.isPrefixOfWord(sentence3, searchWord3) << endl;

  cin.get();
}

// Time complexity:$$O(n^2)$$
// Space complexity:$$O(1)$$
