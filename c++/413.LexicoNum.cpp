/* 386. Lexicographical Numbers
Given an integer n, return all the numbers in the range [1, n] sorted in
lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space.

Example 1:
Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]

Example 2:
Input: n = 2
Output: [1,2]


Constraints:
1 <= n <= 5 * 104
*/

// create the vector of num 1 to n
// then sort in lex order
// return the vector

class Solution {
public:
  void dfs(int current, int n, vector<int>& result) {
    if (current > n)
      return;
    result.push_back(current);
    for (int i = 0; i <= 9; i++) {
      if (current * 10 + i > n)
        return;
      dfs(current * 10 + i, n, result);
    }
  }

  vector<int> lexicalOrder(int n) {
    vector<int> result;
    for (int i = 1; i <= 9; i++) {
      dfs(i, n, result);
    }
    return result;
  }
};
// sub:
// https://leetcode.com/problems/lexicographical-numbers/submissions/1657344959/?envType=daily-question&envId=2025-06-08
// sol:
// https://leetcode.com/problems/lexicographical-numbers/solutions/6822214/386-lexicographical-numbers-by-nalindala-vcoy/
