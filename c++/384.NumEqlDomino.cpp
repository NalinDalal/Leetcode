/* 1128. Number of Equivalent Domino Pairs
Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] =
[c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that
is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and
dominoes[i] is equivalent to dominoes[j].


Example 1:
Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1

Example 2:
Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
Output: 3


Constraints:
1 <= dominoes.length <= 4 * 104
dominoes[i].length == 2
1 <= dominoes[i][j] <= 9

Hint 1
For each domino j, find the number of dominoes you've already seen (dominoes i
with i < j) that are equivalent. Hint 2 You can keep track of what you've seen
using a hashmap.
*/

// normalise by sorting each pair
// count how many times each normalized pair occurs
// if count=n; no of pair=n(n-1)/2

#include <unordered_map>
/*class Solution {
public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int n = dominoes.size();
    vector<vector<int>> norm(n);
    for (int i = 0; i < n; i++) {
      norm[i][0] = dominoes[i][0];
      norm[i][1] = dominoes[i][1];
    }
    sort(norm.begin(), norm.end());
    std::unordered_map<vector<int>, int> mp;
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (norm[i] == norm[j]) {
          count++;
          break;
        }
      }
      mp[norm[i]] = count;
    }
    return count * (count - 1) / 2;
  }
};*/

class Solution {
public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    unordered_map<int, int> count;
    int res = 0;
    for (auto& d : dominoes) {
      int a = d[0], b = d[1];
      int key = a < b ? a * 10 + b : b * 10 + a; // normalize
      res += count[key];
      count[key]++;
    }
    return res;
  }
};
// sub:
// https://leetcode.com/problems/number-of-equivalent-domino-pairs/submissions/1624873801/?envType=daily-question&envId=2025-05-04
