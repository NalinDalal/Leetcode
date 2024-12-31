// 212. Word Search II
/* class TrieNode {
public:
    TrieNode* child[26] = {NULL};
    bool isWord = false;
};

class Solution {
public:
    //direction array
    int dir[5] = {-1, 0, 1, 0, -1};

    //function to add word in Trie
    void addWord(TrieNode* cur, string word) {
        for (auto ch : word) {
            if (!cur->child[ch - 'a'])
                cur->child[ch - 'a'] = new TrieNode();
            cur = cur->child[ch - 'a'];
        }
        cur->isWord = true;
    }

    void dfs(vector<string>& ans, string ds, TrieNode* cur, int i, int j,vector<vector<char>>& board,vector<vector<bool>> &vis) {
        if (!cur)   return;

        //if a word is found add it and mark it as false, to avoid redundancy 
        if (cur->isWord){
            ans.push_back(ds);
            cur->isWord = false;
        }

        vis[i][j] = true; //marking path as visited

        for (int del = 0; del < 4; del++) {
            int next_i = i + dir[del], next_j = j + dir[del + 1];
            //checking for out of bound condition, moving to next letter
            if (next_i < board.size() and next_j < board[0].size() and !vis[next_i][next_j] and cur->child[board[next_i][next_j] - 'a'])
                dfs(ans, ds + board[next_i][next_j],cur->child[board[next_i][next_j] - 'a'], next_i, next_j,board,vis);
        }
        vis[i][j]= false; //resetting the path to unvisited
    }

    vector<string> findWords(vector<vector<char>>& board,vector<string>& words) {
        //initializations
        TrieNode* trie = new TrieNode();
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        //adding all the words to Trie
        for (auto word : words)
            addWord(trie, word);

        vector<string> ans; //decalring answer array
        for (int i = 0; i < n; i++) {
            for (auto j = 0; j < m; j++) {
                char ch = board[i][j];
                if(trie->child[ch-'a']) //if word exists call dfs
                    dfs(ans,string(1, ch), trie->child[ch-'a'], i, j, board,vis);
            }
        }
        return ans; //returning the answer array
    }
};*/

function findWords(board: string[][], words: string[]): string[] {
  const result: string[] = [];
  const trie = buildTrie(words);
  const rows = board.length;
  const cols = board[0].length;

  // Helper function for DFS
  const dfs = (
    row: number,
    col: number,
    node: Record<string, any>,
    path: string,
  ): void => {
    if (node.end) {
      result.push(path);
      delete node.end; // Avoid duplicates
    }

    if (
      row < 0 ||
      row >= rows ||
      col < 0 ||
      col >= cols ||
      board[row][col] === "#" ||
      !node[board[row][col]]
    ) {
      return;
    }

    const char = board[row][col];
    board[row][col] = "#"; // Mark as visited
    for (const [dr, dc] of [
      [-1, 0],
      [1, 0],
      [0, -1],
      [0, 1],
    ]) {
      dfs(row + dr, col + dc, node[char], path + char);
    }
    board[row][col] = char; // Restore the cell
  };

  // Start DFS from each cell
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (trie[board[r][c]]) {
        dfs(r, c, trie, "");
      }
    }
  }

  return result;

  // Helper function to build Trie
  function buildTrie(words: string[]): Record<string, any> {
    const root: Record<string, any> = {};
    for (const word of words) {
      let node = root;
      for (const char of word) {
        if (!node[char]) node[char] = {};
        node = node[char];
      }
      node.end = true; // Mark the end of a word
    }
    return root;
  }
}

// submission: https://leetcode.com/problems/word-search-ii/submissions/1493010331/
