/* 873. Length of Longest Fibonacci Subsequence

A sequence x1, x2, ..., xn is Fibonacci-like if:

n >= 3
xi + xi+1 == xi+2 for all i + 2 <= n
Given a strictly increasing array arr of positive integers forming a sequence,
return the length of the longest Fibonacci-like subsequence of arr. If one does
not exist, return 0.

A subsequence is derived from another sequence arr by deleting any number of
elements (including none) from arr, without changing the order of the remaining
elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].



Example 1:

Input: arr = [1,2,3,4,5,6,7,8]
Output: 5
Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].
Example 2:

Input: arr = [1,3,7,11,12,14,18]
Output: 3
Explanation: The longest subsequence that is fibonacci-like: [1,11,12],
[3,11,14] or [7,11,18].


Constraints:

3 <= arr.length <= 1000
1 <= arr[i] < arr[i + 1] <= 109

*/
// logic: check for last two element sum of Fibb vector if equal to ith of
// arr if yes then append ith element to vector else move forward do till
// end of arr atlast return length of vector

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> index;
    vector<vector<int>> dp(n, vector<int>(n, 2));
    int max_len = 0;

    for (int i = 0; i < n; ++i) {
      index[arr[i]] = i;
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        int prev = arr[i] - arr[j];
        if (prev < arr[j] && index.find(prev) != index.end()) {
          int k = index[prev];
          dp[j][i] = dp[k][j] + 1;
          max_len = max(max_len, dp[j][i]);
        }
      }
    }

    return max_len >= 3 ? max_len : 0;
  }
};
// time: O(n^2)
// space: O(n)
// sub:
// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/submissions/1556671390/?envType=daily-question&envId=2025-02-27
// sol:
// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/solutions/6472536/873-length-of-longest-fibonacci-subseque-wb2o/
