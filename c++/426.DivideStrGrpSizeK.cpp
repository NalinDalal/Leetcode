/*2138. Divide a String Into Groups of Size k
A string s can be partitioned into groups of size k using the following
procedure:

The first group consists of the first k characters of the string, the second
group consists of the next k characters of the string, and so on. Each element
can be a part of exactly one group. For the last group, if the string does not
have k characters remaining, a character fill is used to complete the group.
Note that the partition is done so that after removing the fill character from
the last group (if it exists) and concatenating all the groups in order, the
resultant string should be s.

Given the string s, the size of each group k and the character fill, return a
string array denoting the composition of every group s has been divided into,
using the above procedure.



Example 1:

Input: s = "abcdefghi", k = 3, fill = "x"
Output: ["abc","def","ghi"]
Explanation:
The first 3 characters "abc" form the first group.
The next 3 characters "def" form the second group.
The last 3 characters "ghi" form the third group.
Since all groups can be completely filled by characters from the string, we do
not need to use fill. Thus, the groups formed are "abc", "def", and "ghi".
Example 2:

Input: s = "abcdefghij", k = 3, fill = "x"
Output: ["abc","def","ghi","jxx"]
Explanation:
Similar to the previous example, we are forming the first three groups "abc",
"def", and "ghi". For the last group, we can only use the character 'j' from the
string. To complete this group, we add 'x' twice. Thus, the 4 groups formed are
"abc", "def", "ghi", and "jxx".


Constraints:

1 <= s.length <= 100
s consists of lowercase English letters only.
1 <= k <= 100
fill is a lowercase English letter.

Hint 1
Using the length of the string and k, can you count the number of groups the
string can be divided into? Hint 2 Try completing each group using characters
from the string. If there aren’t enough characters for the last group, use the
fill character to complete the group.
*/

// solution:
/*do one thing, take the string, and run a window of size k, put that whole
 * window into vector if window not complete and string still not done then find
 * existing size of string, subtract it from k, add that no of chars to that
 * last window string push to vector atlast return the vector
 */
class Solution {
public:
  vector<string> divideString(string s, int k, char fill) {
    vector<string> result;
    int n = s.size();

    for (int i = 0; i < n; i += k) {
      string chunk = s.substr(i, k);
      if (chunk.size() < k) {
        chunk += string(k - chunk.size(), fill);
      }
      result.push_back(chunk);
    }

    return result;
  }
};
// sub:
// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/submissions/1672229870/?envType=daily-question&envId=2025-06-22
// sol:
// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/solutions/6870831/2138-divide-a-string-into-groups-of-size-k/
