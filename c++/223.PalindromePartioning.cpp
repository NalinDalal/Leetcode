/* https://leetcode.com/problems/palindrome-partitioning/description/
131. Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a
palindrome. Return all possible palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]


Constraints:
1 <= s.length <= 16
s contains only lowercase English letters.
*/

#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> current;
    partitionHelper(s, 0, current, ans);
    return ans;
  }

private:
  void partitionHelper(const string& s, int start, vector<string>& current,
                       vector<vector<string>>& ans) {
    if (start == s.size()) {
      ans.push_back(current);
      return;
    }

    for (int i = start; i < s.size(); ++i) {
      if (isPalindrome(s, start, i)) {
        current.push_back(s.substr(start, i - start + 1));
        partitionHelper(s, i + 1, current, ans);
        current.pop_back();
      }
    }
  }

  bool isPalindrome(const string& s, int left, int right) {
    while (left < right) {
      if (s[left++] != s[right--]) {
        return false;
      }
    }
    return true;
  }
};

// return all substring of s which are palindromes
// sub:
// https://leetcode.com/problems/palindrome-partitioning/submissions/1529996073/
// sol:
// https://leetcode.com/problems/palindrome-partitioning/solutions/6368813/131-palindrome-partitioning-by-nalindala-fv3j/
