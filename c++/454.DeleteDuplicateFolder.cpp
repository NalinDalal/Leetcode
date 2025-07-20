/*1948. Delete Duplicate Folders in System

Due to a bug, there are many duplicate folders in a file system. You are given a
2D array paths, where paths[i] is an array representing an absolute path to the
ith folder in the file system.

For example, ["one", "two", "three"] represents the path "/one/two/three".
Two folders (not necessarily on the same level) are identical if they contain
the same non-empty set of identical subfolders and underlying subfolder
structure. The folders do not need to be at the root level to be identical. If
two or more folders are identical, then mark the folders as well as all their
subfolders.

For example, folders "/a" and "/b" in the file structure below are identical.
They (as well as their subfolders) should all be marked: /a /a/x /a/x/y /a/z /b
/b/x
/b/x/y
/b/z
However, if the file structure also included the path "/b/w", then the folders
"/a" and "/b" would not be identical. Note that "/a/x" and "/b/x" would still be
considered identical even with the added folder. Once all the identical folders
and their subfolders have been marked, the file system will delete all of them.
The file system only runs the deletion once, so any folders that become
identical after the initial deletion are not deleted.

Return the 2D array ans containing the paths of the remaining folders after
deleting all the marked folders. The paths may be returned in any order.



Example 1:


Input: paths = [["a"],["c"],["d"],["a","b"],["c","b"],["d","a"]]
Output: [["d"],["d","a"]]
Explanation: The file structure is as shown.
Folders "/a" and "/c" (and their subfolders) are marked for deletion because
they both contain an empty folder named "b". Example 2:


Input: paths =
[["a"],["c"],["a","b"],["c","b"],["a","b","x"],["a","b","x","y"],["w"],["w","y"]]
Output: [["c"],["c","b"],["a"],["a","b"]]
Explanation: The file structure is as shown.
Folders "/a/b/x" and "/w" (and their subfolders) are marked for deletion because
they both contain an empty folder named "y". Note that folders "/a" and "/c" are
identical after the deletion, but they are not deleted because they were not
marked beforehand. Example 3:


Input: paths = [["a","b"],["c","d"],["c"],["a"]]
Output: [["c"],["c","d"],["a"],["a","b"]]
Explanation: All folders are unique in the file system.
Note that the returned array can be in a different order as the order does not
matter.


Constraints:

1 <= paths.length <= 2 * 104
1 <= paths[i].length <= 500
1 <= paths[i][j].length <= 10
1 <= sum(paths[i][j].length) <= 2 * 105
path[i][j] consists of lowercase English letters.
No two paths lead to the same folder.
For any folder not at the root level, its parent folder will also be in the
input.

int 1
Can we use a trie to build the folder structure?
Hint 2
Can we utilize hashing to hash the folder structures?
*/

// Intuition
/*Trie+Serialization+Hashing to be used
Build a Trie (prefix tree) representing the directory structure.

Serialize each subtree to get a hashable signature of the structure.

Use a dictionary to count the serialized subtree structures.

Mark all nodes whose serialized structure appears more than once.

Do a DFS traversal to collect paths that are not part of the marked duplicate
subtrees.
*/

// Approach
/*1. Build the Trie: Each node represents a folder, and children are stored in a
dictionary.

2. Serialize each node’s subtree using post-order traversal, and generate a
signature for it like:

```scss
folder_name(subfolder1_serial)(subfolder2_serial)...
````
This way, identical subtrees will have identical serials.

3. Store the serialization in a hash map and keep a count of how many times each
serialization occurs.

4. In a second traversal, mark all nodes whose serialization occurs more than
once (i.e., duplicates).

5. Finally, do a DFS from root to collect all valid paths that don't include any
marked node or its subfolders.
*/

class TrieNode {
public:
  string name;
  unordered_map<string, TrieNode*> children;
  bool marked = false;

  TrieNode(string name = "") : name(name) {}
};

class Solution {
  unordered_map<string, vector<TrieNode*>> serialMap;

  // Post-order serialize each subtree
  string serialize(TrieNode* node) {
    if (node->children.empty())
      return "()";

    vector<pair<string, string>> serials;
    for (auto& [name, child] : node->children) {
      serials.push_back({name, serialize(child)});
    }

    // Sort to ensure uniqueness of structure
    sort(serials.begin(), serials.end());

    string serial;
    for (auto& [name, sub] : serials) {
      serial += name + sub;
    }

    serial = "(" + serial + ")";

    serialMap[serial].push_back(node);
    return serial;
  }

  void collectPaths(TrieNode* node, vector<string>& path,
                    vector<vector<string>>& res) {
    if (node->marked)
      return;

    if (!node->name.empty())
      path.push_back(node->name);
    if (!node->name.empty())
      res.push_back(path);

    for (auto& [_, child] : node->children) {
      collectPaths(child, path, res);
    }

    if (!node->name.empty())
      path.pop_back();
  }

public:
  vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
    TrieNode* root = new TrieNode();

    // Step 1: Build Trie
    for (auto& path : paths) {
      TrieNode* node = root;
      for (const string& folder : path) {
        if (!node->children.count(folder)) {
          node->children[folder] = new TrieNode(folder);
        }
        node = node->children[folder];
      }
    }

    // Step 2: Serialize subtrees and detect duplicates
    serialize(root);

    // Step 3: Mark duplicate nodes
    for (auto& [_, nodes] : serialMap) {
      if (nodes.size() > 1) {
        for (auto* node : nodes) {
          node->marked = true;
        }
      }
    }

    // Step 4: Collect non-duplicate paths
    vector<vector<string>> res;
    vector<string> currentPath;
    for (auto& [_, child] : root->children) {
      collectPaths(child, currentPath, res);
    }

    return res;
  }
};

// sub:
// https://leetcode.com/problems/delete-duplicate-folders-in-system/submissions/1704557271/?envType=daily-question&envId=2025-07-20
// sol:
// https://leetcode.com/problems/delete-duplicate-folders-in-system/solutions/6981349/1948-delete-duplicate-folders-in-system-kw5ea/
