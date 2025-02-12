/* 14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of
strings.

If there is no common prefix, return an empty string "".



Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
    return longest common prefix of all string in strs
    else return empty string
    well what if check every element of strs char by char
    return till 1st occurence where prefix is not same

*/
/*i think this checks only first and second element of string
but we need to check all elements of string all at once
so like sliding pointer for each element at same time, appending to prefix if
element checks out when they are not equal we return the prefix check like 0 to
min.length of prefix element*/
class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    string prefix = "";
    if (strs.empty()) {
      return prefix;
    }

    // Iterate through each character position
    for (int j = 0; j < strs[0].size(); j++) {
      // Compare character at position j among all strings
      char current_char = strs[0][j];
      for (int i = 1; i < strs.size(); i++) {
        // If the current string doesn't have this character or it's different,
        // return the prefix found so far
        if (j >= strs[i].size() || strs[i][j] != current_char) {
          return prefix;
        }
      }
      // If all strings have the same character at position j, append it to the
      // prefix
      prefix.push_back(current_char);
    }

    return prefix;
  }
};
// sub:
// https://leetcode.com/problems/longest-common-prefix/submissions/1540240374/
int main() {
  vector<string> strs1 = {"flower", "flow", "flight"};
  Solution sol;
  cout << sol.longestCommonPrefix(strs1) << endl;
  return 0;
}

// Time: O(m*n)
// Space: O(m*n)
// sol:
// https://leetcode.com/problems/longest-common-prefix/solutions/6411939/14-longest-common-prefix-by-nalindalal20-u9eu/
