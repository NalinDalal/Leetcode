/*  https://leetcode.com/problems/word-search-ii/description/
212. Word Search II

Given an m x n board of characters and a list of strings words, return all words
on the board.

Each word must be constructed from letters of sequentially adjacent cells, where
adjacent cells are horizontally or vertically neighboring. The same letter cell
may not be used more than once in a word.


Example 1:
Input: board =
[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words
= ["oath","pea","eat","rain"] Output: ["eat","oath"]

Example 2:
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []


Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// what to do/Intuition:
// 1. use a 2d array to store words
// if words[i] can be made from adjacent cells, then return words[i]

class Solution {
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> ans;
    for (const string& word : words) {
      if (canFindWord(board, word)) {
        ans.push_back(word);
      }
    }
    return ans;
  }

private:
  bool canFindWord(vector<vector<char>>& board, const string& word) {
    int rows = board.size();
    int cols = board[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (dfs(board, word, 0, i, j, visited)) {
          return true;
        }
      }
    }
    return false;
  }

  bool dfs(vector<vector<char>>& board, const string& word, int index, int x,
           int y, vector<vector<bool>>& visited) {
    if (index == word.size())
      return true; // All characters matched
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() ||
        visited[x][y] || board[x][y] != word[index]) {
      return false; // Out of bounds, already visited, or character mismatch
    }

    visited[x][y] = true; // Mark cell as visited
    // Explore all 4 possible directions
    bool found = dfs(board, word, index + 1, x + 1, y, visited) ||
                 dfs(board, word, index + 1, x - 1, y, visited) ||
                 dfs(board, word, index + 1, x, y + 1, visited) ||
                 dfs(board, word, index + 1, x, y - 1, visited);

    visited[x][y] = false; // Backtrack
    return found;
  }
};
// tle
// optimised:
//  Trie Node Structure
struct TrieNode {
  string word = "";
  TrieNode* children[26] = {nullptr};
};

class Solution2 {
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    // Build Trie
    TrieNode* root = buildTrie(words);
    vector<string> result;

    // Perform DFS on each cell
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (root->children[board[i][j] - 'a']) {
          dfs(board, i, j, root, result);
        }
      }
    }

    return result;
  }

private:
  // Build Trie from words
  TrieNode* buildTrie(const vector<string>& words) {
    TrieNode* root = new TrieNode();
    for (const string& word : words) {
      TrieNode* node = root;
      for (char c : word) {
        int index = c - 'a';
        if (!node->children[index]) {
          node->children[index] = new TrieNode();
        }
        node = node->children[index];
      }
      node->word = word; // Mark end of word
    }
    return root;
  }

  // DFS with Trie
  void dfs(vector<vector<char>>& board, int x, int y, TrieNode* node,
           vector<string>& result) {
    char c = board[x][y];
    if (c == '#' || !node->children[c - 'a'])
      return; // Already visited or no matching prefix

    node = node->children[c - 'a'];
    if (!node->word.empty()) {
      result.push_back(node->word);
      node->word.clear(); // Avoid duplicate entries
    }

    board[x][y] = '#'; // Mark as visited

    // Explore neighbors
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
        dfs(board, nx, ny, node, result);
      }
    }

    board[x][y] = c; // Restore cell after DFS

    // Optional: Remove leaf node in Trie
    if (isEmpty(node)) {
      delete node;
      node = nullptr;
    }
  }

  // Check if a Trie node has no children
  bool isEmpty(TrieNode* node) {
    for (int i = 0; i < 26; ++i) {
      if (node->children[i])
        return false;
    }
    return true;
  }
};

class Solution3 {
public:
  // direction array
  int dir[5] = {-1, 0, 1, 0, -1};

  // function to add word in Trie
  void addWord(TrieNode* cur, string word) {
    for (auto ch : word) {
      if (!cur->child[ch - 'a'])
        cur->child[ch - 'a'] = new TrieNode();
      cur = cur->child[ch - 'a'];
    }
    cur->isWord = true;
  }

  void dfs(vector<string>& ans, string ds, TrieNode* cur, int i, int j,
           vector<vector<char>>& board, vector<vector<bool>>& vis) {
    if (!cur)
      return;

    // if a word is found add it and mark it as false, to avoid redundancy
    if (cur->isWord) {
      ans.push_back(ds);
      cur->isWord = false;
    }

    vis[i][j] = true; // marking path as visited

    for (int del = 0; del < 4; del++) {
      int next_i = i + dir[del], next_j = j + dir[del + 1];
      // checking for out of bound condition, moving to next letter
      if (next_i < board.size() and next_j < board[0].size() and
          !vis[next_i][next_j] and cur->child[board[next_i][next_j] - 'a'])
        dfs(ans, ds + board[next_i][next_j],
            cur->child[board[next_i][next_j] - 'a'], next_i, next_j, board,
            vis);
    }
    vis[i][j] = false; // resetting the path to unvisited
  }

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    // initializations
    TrieNode* trie = new TrieNode();
    int n = board.size(), m = board[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    // adding all the words to Trie
    for (auto word : words)
      addWord(trie, word);

    vector<string> ans; // decalring answer array
    for (int i = 0; i < n; i++) {
      for (auto j = 0; j < m; j++) {
        char ch = board[i][j];
        if (trie->child[ch - 'a']) // if word exists call dfs
          dfs(ans, string(1, ch), trie->child[ch - 'a'], i, j, board, vis);
      }
    }
    return ans; // returning the answer array
  }
};
// Solution:
/* The Trie-based DFS approach combines the advantages of the Trie data
structure (efficient prefix searching) with DFS traversal of the board to
explore all potential word formations. This method ensures:

- Efficiency: By using the Trie, prefix matching is fast, and DFS ensures all
potential words are found.
- Avoidance of Redundant Computations: Proper use of the visited matrix and Trie
node marking avoids unnecessary searches and duplicate results.
- Complete Exploration: DFS ensures that every potential path is explored from
each starting point on the board. This approach is both space and time
efficient, making it suitable for solving complex word search problems on large
boards.
*/

int main() {
  Solution3 solution;
  vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
                                {'e', 't', 'a', 'e'},
                                {'i', 'h', 'k', 'r'},
                                {'i', 'f', 'l', 'v'}};
  vector<string> words = {"oath", "pea", "eat", "rain"};
  vector<string> result = solution.findWords(board, words);

  for (const string& word : result) {
    cout << word << " ";
  }
  return 0;
}

/* Time complexity: O(max(L∗w,M∗N∗4L))

Trie Construction: O(L∗w) L-avg word length; w-number of words
DFS: O(M∗N∗4L) M,N - board size; L- max word length
Space complexity: O(L×W)

Trie: O(L×W).
DFS Call Stack: O(L) (maximum depth of recursion).
*/
