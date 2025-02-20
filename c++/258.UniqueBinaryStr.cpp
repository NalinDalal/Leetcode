/* 1980. Find Unique Binary String

Given an array of strings nums containing n unique binary strings each of length
n, return a binary string of length n that does not appear in nums. If there are
multiple answers, you may return any of them.

Example 1:
Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.

Example 2:
Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.

Example 3:
Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would
also be correct.
*/

class Solution {
public:
  string findDifferentBinaryString(vector<string>& nums) {
    // given a array of strings, contain n unique binary string of length n
    // return binary string of length n not appearing in nums
    // if there are multiple answers, retur any one of them
    int n = nums.size();
    string ans = "";
    for (int i = 0; i < pow(2, n); i++) {
      string s = "";
      for (int j = 0; j < n; j++) {
        if (i & (i << j))
          s += "1";
        else
          s += "0";
      }
      if (find(nums.begin(), nums.end(), s) == nums.end())
        ans = s;
    }
    return ans;
  }
};
// sub:
// https://leetcode.com/problems/find-unique-binary-string/submissions/1549151964/?envType=daily-question&envId=2025-02-20
// alt:
class Solution {
public:
  string findDifferentBinaryString(vector<string>& nums) {
    int n = nums.size();
    string ans = "";
    for (int i = 0; i < n; i++) {
      ans += (nums[i][i] == '0') ? '1' : '0'; // Flip the diagonal character
    }
    return ans;
  }
};
// sub:
// https://leetcode.com/problems/find-unique-binary-string/submissions/1549152677/?envType=daily-question&envId=2025-02-20
// sol:
// https://leetcode.com/problems/find-unique-binary-string/solutions/6444503/1980-find-unique-binary-string-by-nalind-5pwk/
