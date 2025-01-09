/* https://leetcode.com/problems/word-ladder/description/

127. Word Ladder

A transformation sequence from word beginWord to word endWord using a dictionary
wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be
in wordList. sk == endWord Given two words, beginWord and endWord, and a
dictionary wordList, return the number of words in the shortest transformation
sequence from beginWord to endWord, or 0 if no such sequence exists.



Example 1:
Input: beginWord = "hit", endWord = "cog", wordList =
["hot","dot","dog","lot","log","cog"] Output: 5 Explanation: One shortest
transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5
words long.

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList =
["hot","dot","dog","lot","log"] Output: 0 Explanation: The endWord "cog" is not
in wordList, therefore there is no valid transformation sequence.


Constraints:
1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique*/

#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

/*1. Use a Breadth-First Search (BFS): This is the typical approach for solving
shortest-path problems in an unweighted graph. Treat each word as a node and
connect nodes if their words differ by exactly one letter.

2.Check Transformation Validity: Replace the check wordList[i][0] ==
wordList[j][0] with a function that verifies if two words differ by only one
character.*/
class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (wordSet.find(endWord) == wordSet.end())
      return 0;

    queue<pair<string, int>> q; // {current word, transformation count}
    q.push({beginWord, 1});

    while (!q.empty()) {
      auto [currentWord, level] = q.front();
      q.pop();

      if (currentWord == endWord)
        return level;

      // Try all possible one-character transformations
      for (int i = 0; i < currentWord.size(); i++) {
        string tempWord = currentWord;

        for (char c = 'a'; c <= 'z'; c++) {
          tempWord[i] = c;
          if (wordSet.find(tempWord) != wordSet.end()) {
            q.push({tempWord, level + 1});
            wordSet.erase(tempWord); // Avoid revisiting
          }
        }
      }
    }
    return 0; // If no transformation sequence is found
  }
};

/*Explanation
1. Initialization:
- Insert all words in wordList into an unordered_set (wordSet) for O(1) lookup.
- If the endWord is not in the wordSet, return 0 immediately.
2. BFS:
- Start from the beginWord with an initial transformation count of 1.
- For each word in the queue, attempt all possible one-character transformations
and check if they exist in the wordSet.
- If a valid transformation is found, add it to the queue with an incremented
transformation count and remove it from the wordSet.
3. Termination:
- If the endWord is reached, return the transformation count.
- If the queue is empty and the endWord is not reached, return 0.*/

// Time: O(n^2)
// Space: O(n)
