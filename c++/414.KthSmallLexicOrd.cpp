/* 440. K-th Smallest in Lexicographical Order
Given two integers n and k, return the kth lexicographically smallest integer in
the range [1, n].


Example 1:
Input: n = 13, k = 2
Output: 10
Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7,
8, 9], so the second smallest number is 10.

Example 2:
Input: n = 1, k = 1
Output: 1


Constraints:
1 <= k <= n <= 109
*/

// put all no in vector in string
// sort vector as per lexicographical order
// return kth element in int form

class Solution {
public:
  int findKthNumber(int n, int k) {
    vector<string> v;
    for (int i = 1; i <= n; i++) {
      v.push_back(to_string(i));
    }
    sort(v.begin(), v.end());
    return stoi(v[k - 1]);
  }
};
// problem: tle
// do prefix-traversal
// Instead of generating all numbers, we count how many numbers exist under a
// given prefix. Count how many numbers start with a prefix curr and are ≤ n.
/*long long countSteps(long long n, long long curr, long long next) {
    long long steps = 0;
    while (curr <= n) {
        steps += min(n + 1, next) - curr;
        curr *= 10;
        next *= 10;
    }
    return steps;
}

*/

class Solution1 {
public:
  int findKthNumber(int n, int k) {
    int curr = 1;
    k--; // we start from 1, so subtract 1

    while (k > 0) {
      long long steps = countSteps(n, curr, curr + 1);
      if (steps <= k) {
        // skip this whole subtree
        curr++;
        k -= steps;
      } else {
        // go deeper into subtree
        curr *= 10;
        k--;
      }
    }
    return curr;
  }

  long long countSteps(long long n, long long curr, long long next) {
    long long steps = 0;
    while (curr <= n) {
      steps += min(n + 1, next) - curr;
      curr *= 10;
      next *= 10;
    }
    return steps;
  }
};
// sub:
// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/submissions/1658225411/?envType=daily-question&envId=2025-06-09
