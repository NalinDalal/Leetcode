/* https://leetcode.com/problems/implement-trie-prefix-tree/description/

208. Implement Trie (Prefix Tree)

A trie (pronounced as "try") or prefix tree is a tree data structure used to
efficiently store and retrieve keys in a dataset of strings. There are various
applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:
Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie
(i.e., was inserted before), and false otherwise. boolean startsWith(String
prefix) Returns true if there is a previously inserted string word that has the
prefix prefix, and false otherwise.


Example 1:
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True


Constraints:
1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Define the TrieNode class
class TrieNode {
public:
  TrieNode* children[26];
  bool isEnd;

  TrieNode() {
    isEnd = false;
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
  }
};

// Define the Trie class
class Trie {
private:
  TrieNode* root;

public:
  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode* node = root;
    for (char c : word) {
      int index = c - 'a';
      if (node->children[index] == nullptr) {
        node->children[index] = new TrieNode();
      }
      node = node->children[index];
    }
    node->isEnd = true;
  }

  bool search(string word) {
    TrieNode* node = root;
    for (char c : word) {
      int index = c - 'a';
      if (node->children[index] == nullptr) {
        return false;
      }
      node = node->children[index];
    }
    return node->isEnd;
  }

  bool startsWith(string prefix) {
    TrieNode* node = root;
    for (char c : prefix) {
      int index = c - 'a';
      if (node->children[index] == nullptr) {
        return false;
      }
      node = node->children[index];
    }
    return true;
  }
};

// Example usage
int main() {
  vector<string> operations = {"Trie",       "insert", "search", "search",
                               "startsWith", "insert", "search"};
  vector<vector<string>> arguments = {{},      {"apple"}, {"apple"}, {"app"},
                                      {"app"}, {"app"},   {"app"}};

  Trie* trie = nullptr;
  vector<string> output;

  for (int i = 0; i < operations.size(); ++i) {
    if (operations[i] == "Trie") {
      trie = new Trie();
      output.push_back("null");
    } else if (operations[i] == "insert") {
      trie->insert(arguments[i][0]);
      output.push_back("null");
    } else if (operations[i] == "search") {
      output.push_back(trie->search(arguments[i][0]) ? "true" : "false");
    } else if (operations[i] == "startsWith") {
      output.push_back(trie->startsWith(arguments[i][0]) ? "true" : "false");
    }
  }

  cout << "[";
  for (int i = 0; i < output.size(); ++i) {
    cout << output[i];
    if (i < output.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl;

  return 0;
}

// 89.19%
//  Time complexity:$$O(n)$$
//  Space complexity:$$O(m*n)$$
// insert $$m$$ words of $$n$$ length
