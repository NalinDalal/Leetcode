/* 71. Simplify Path

You are given an absolute path for a Unix-style file system, which always begins
with a slash '/'. Your task is to transform this absolute path into its
simplified canonical path.

The rules of a Unix-style file system are as follows:

A single period '.' represents the current directory. A double period '..'
represents the previous/parent directory. Multiple consecutive slashes such as
'//' and '///' are treated as a single slash '/'. Any sequence of periods that
does not match the rules above should be treated as a valid directory or file
name. For example, '...' and '....' are valid directory or file names. The
simplified canonical path should follow these rules:

The path must start with a single slash '/'. Directories within the path must be
separated by exactly one slash '/'. The path must not end with a slash '/',
unless it is the root directory. The path must not have any single or double
periods ('.' and '..') used to denote current or parent directories. Return the
simplified canonical path.


Example 1:
Input: path = "/home/"
Output: "/home"
Explanation:The trailing slash should be removed.

Example 2:
Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: Multiple consecutive slashes are replaced by a single one.

Example 3:
Input: path = "/home/user/Documents/../Pictures"
Output: "/home/user/Pictures"
Explanation:A double period ".." refers to the directory up a level (the parent
directory).

Example 4:
Input: path = "/../"
Output: "/"
Explanation:Going one level up from the root directory is not possible.

Example 5:
Input: path = "/.../a/../b/c/../d/./"
Output: "/.../b/d"
Explanation:"..." is a valid name for a directory in this problem.


Constraints:

1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path. */

#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

/*class Solution {
public:
  string simplifyPath(string path) {
    stack<string> st;
    for (int i = 0; i < path.length(); i++) {
      if (path[i] == '/') {
        st.push(path.substr(i + 1));
        string res = "";
        while (!st.empty()) {
          string s = st.top();
          st.pop();
          if (s == "..") {
            if (res.length() > 0) {
              res = res.substr(0, res.length() - 1);
            } else if (s == ".") {
              // do nothing
            } else {
              res = res + s;
            }
          }
          // return res;
          if (s == "..") {
            res = res - s;
          }
        }
      }
    }
    return res;
  }
};*/

class Solution {
public:
  string simplifyPath(string path) {
    stack<string> st;
    stringstream ss(path);
    string token;

    // Tokenize the path based on '/' as a delimiter
    while (getline(ss, token, '/')) {
      if (token == "" || token == ".") {
        // Skip empty tokens or current directory references
        continue;
      } else if (token == "..") {
        // Go up one directory (if possible)
        if (!st.empty()) {
          st.pop();
        }
      } else {
        // Push valid directory names
        st.push(token);
      }
    }

    // Build the simplified path
    string result = "";
    while (!st.empty()) {
      result = "/" + st.top() + result;
      st.pop();
    }

    // Return root "/" if result is empty
    return result.empty() ? "/" : result;
  }
};

// see what we can do:
// 1. remove the multiple slashes to single slash
// 2. remove trailing slash
// 3. remove the periods, double periods
// 4. if double periods, remove the ones that are just behind that slash,
// 5. keep more than double periods as it is

int main() {
  Solution s;
  cout << "/home/" << s.simplifyPath("/home/") << endl;
  cout << "/home//foo/" << s.simplifyPath("/home//foo/") << endl;
  cout << "/home/user/Documents/../Pictures"
       << s.simplifyPath("/home/user/Documents/../Pictures") << endl;

  return 0;
}

/* Explanation:
Input Parsing:

Use std::getline with / as the delimiter to break the path into components.
Rules:

Skip empty strings ("") and current directory markers (".").
For "..", pop the stack to go up one level (if the stack is not empty).
Push valid directory names into the stack.
Rebuild Path:

Rebuild the path by concatenating elements from the stack.
Edge Case:

If the stack is empty after processing, the path is simplified to /.
*/

/* Example:
Input:
"/a/./b/../../c/"

Output:
"/c"

Explanation of Output:
Break path: ["", "a", ".", "b", "..", "..", "c", ""]
Stack operations:
Push "a"
Skip "."
Push "b"
Pop "b" for ".."
Pop "a" for ".."
Push "c"
Final stack: ["c"].*/

// Time complexity:O(n)

// Space complexity:O(n)
