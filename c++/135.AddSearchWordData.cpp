/* 211. Design Add and Search Words Data Structure
Medium
Topics
Companies
Hint
Design a data structure that supports adding new words and finding if a string
matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that
matches word or false otherwise. word may contain dots '.' where dots can be
matched with any letter.


Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True


Constraints:

1 <= word.length <= 25
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 2 dots in word for search queries.
At most 10^4 calls will be made to addWord and search. */

// what if create a map<string,bool> and addWord ans search

/*
class WordDictionary {
public:
    WordDictionary() {
        new WordDictionary();
    }

    void addWord(string word) {
        new map<word,bool>;
    }

    bool search(string word) {
        if(word.find(".")==-1)
            return new map<word,bool>[word];
        else
            return new map<word,bool>[word.replace(".","*")];
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

// Problem: The statement new WordDictionary(); within the constructor creates a
// new instance of WordDictionary unnecessarily and can lead to recursion or
// memory leakage

/* # Approach
1. Trie Data Structure:
The addWord method uses a trie (prefix tree) to store the words efficiently.
Each TrieNode has children (to store next characters) and isEndOfWord (to mark
the end of a valid word).

2. Wildcard Matching:
The search method supports '.' as a wildcard character, matching any letter.

3. Efficiency:
Searching is efficient for normal strings and manageable for wildcard strings.*/
// 32.46% solution
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class WordDictionary {
private:
  struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;
  };

  TrieNode* root;

public:
  WordDictionary() { root = new TrieNode(); }

  void addWord(string word) {
    TrieNode* node = root;
    for (char c : word) {
      if (!node->children.count(c)) {
        node->children[c] = new TrieNode();
      }
      node = node->children[c];
    }
    node->isEndOfWord = true;
  }

  bool search(string word) { return searchInNode(word, 0, root); }

private:
  bool searchInNode(const string& word, int index, TrieNode* node) {
    if (index == word.size()) {
      return node->isEndOfWord;
    }

    char c = word[index];
    if (c == '.') {
      // Wildcard: check all children
      for (auto& child : node->children) {
        if (searchInNode(word, index + 1, child.second)) {
          return true;
        }
      }
      return false;
    } else {
      // Check specific child
      if (!node->children.count(c)) {
        return false;
      }
      return searchInNode(word, index + 1, node->children[c]);
    }
  }
};

int main() {
  WordDictionary wd;
  wd.addWord("apple");
  wd.addWord("apply");
  wd.addWord("cat");

  cout << wd.search("apple") << endl; // Output: 1 (true)
  cout << wd.search("app.e") << endl; // Output: 1 (true)
  cout << wd.search("appl.") << endl; // Output: 1 (true)
  cout << wd.search("a..le") << endl; // Output: 1 (true)
  cout << wd.search("bat") << endl;   // Output: 0 (false)

  return 0;
}

/* Adding a Word:
Time Complexity:
𝑂
(
𝑛
)
O(n), where
𝑛
n is the length of the word.
Searching:
Time Complexity:
𝑂
(
𝑛
⋅
𝑚
)
O(n⋅m) in the worst case, where
𝑛
n is the word length and
𝑚
m is the branching factor of the trie (number of unique characters).*/
