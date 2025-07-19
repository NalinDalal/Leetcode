/*1233. Remove Sub-Folders from the Filesystem
Given a list of folders folder, return the folders after removing all
sub-folders in those folders. You may return the answer in any order.

If a folder[i] is located within another folder[j], it is called a sub-folder of
it. A sub-folder of folder[j] must start with folder[j], followed by a "/". For
example, "/a/b" is a sub-folder of "/a", but "/b" is not a sub-folder of
"/a/b/c".

The format of a path is one or more concatenated strings of the form: '/'
followed by one or more lowercase English letters.

For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty
string and "/" are not.


Example 1:
Input: folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
Output: ["/a","/c/d","/c/f"]
Explanation: Folders "/a/b" is a subfolder of "/a" and "/c/d/e" is inside of
folder "/c/d" in our filesystem.

Example 2:
Input: folder = ["/a","/a/b/c","/a/b/d"]
Output: ["/a"]
Explanation: Folders "/a/b/c" and "/a/b/d" will be removed because they are
subfolders of "/a".

Example 3:
Input: folder = ["/a/b/c","/a/b/ca","/a/b/d"]
Output: ["/a/b/c","/a/b/ca","/a/b/d"]

Constraints:
- 1 <= folder.length <= 4 * 104
- 2 <= folder[i].length <= 100
- folder[i] contains only lowercase letters and '/'.
- folder[i] always starts with the character '/'.
- Each folder name is unique.

Hint 1
Sort the folders lexicographically.
Hint 2
Insert the current element in an array and then loop until we get rid of all of
their subfolders, repeat this until no element is left.

*/

/*vector is to be sorted
 * then iterate over the vector, compare i with i+1
 * if anything is common, like a subStr in i,i+1
 * add to new vector, if not already present, else move forward
 * return new vector atlast
 */

class Solution {
public:
  vector<string> removeSubfolders(vector<string>& folder) {
    // Sort the folder list to ensure subfolders come after parent folders
    sort(folder.begin(), folder.end());

    vector<string> result;
    string prev = "";

    for (const string& f : folder) {
      // Only add if current path is not a subfolder of the last added folder
      if (prev.empty() || f.find(prev + "/") != 0) {
        result.push_back(f);
        prev = f;
      }
    }

    return result;
  }
};
// Time: O(n)
// Space: O(n)
//  sub:
//  https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/submissions/1703044087/?envType=daily-question&envId=2025-07-19
//  sol:
//  https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/solutions/6976395/1233-remove-sub-folders-from-the-filesys-wxlo/
