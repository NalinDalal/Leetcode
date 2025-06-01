/* 2929. Distribute Candies Among Children II
You are given two positive integers n and limit.

Return the total number of ways to distribute n candies among 3 children such
that no child gets more than limit candies.



Example 1:

Input: n = 5, limit = 2
Output: 3
Explanation: There are 3 ways to distribute 5 candies such that no child gets
more than 2 candies: (1, 2, 2), (2, 1, 2) and (2, 2, 1). Example 2:

Input: n = 3, limit = 3
Output: 10
Explanation: There are 10 ways to distribute 3 candies such that no child gets
more than 3 candies: (0, 0, 3), (0, 1, 2), (0, 2, 1), (0, 3, 0), (1, 0, 2), (1,
1, 1), (1, 2, 0), (2, 0, 1), (2, 1, 0) and (3, 0, 0).


Constraints:

1 <= n <= 106
1 <= limit <= 106


Hint 1
We can enumerate the number of candies of one particular child, let it be i
which means 0 <= i <= min(limit, n). Hint 2 Suppose the 2nd child gets j
candies. Then 0 <= j <= limit and i + j <= n. Hint 3 The 3rd child will hence
get n - i - j candies and we should have 0 <= n - i - j <= limit. Hint 4 After
some transformations, for each i, we have max(0, n - i - limit) <= j <=
min(limit, n - i), each j corresponding to a solution. So the number of
solutions for some i is max(min(limit, n - i) - max(0, n - i - limit) + 1, 0).
Sum the expression for every i in [0, min(n, limit)].
*/

/* Find the total number of non-negative integer solutions to:
a + b + c = n

with constraints:
0 ≤ a ≤ limit
0 ≤ b ≤ limit
0 ≤ c ≤ limit*/

/* Solution
We iterate over a from 0 to min(n, limit).
For each a, we determine how many valid pairs (b, c) exist such that:
`b + c = n - a
0 ≤ b ≤ limit
0 ≤ c ≤ limit`
This becomes a bounded two-sum problem.

From Hint 4, the valid range for b (i.e., j) becomes:
`max(0, n - a - limit) ≤ b ≤ min(limit, n - a)`
For each valid a, the number of b values is:


`count = max(0, min(limit, n - a) - max(0, n - a - limit) + 1)`
We sum this over all a from 0 to min(n, limit).
*/

class Solution {
public:
  long long distributeCandies(int n, int limit) {
    long long total = 0;
    for (int a = 0; a <= std::min(n, limit); ++a) {
      int remaining = n - a;
      int min_b = std::max(0, remaining - limit);
      int max_b = std::min(limit, remaining);
      total += std::max(0, max_b - min_b + 1);
    }
    return total;
  }
};
// sub:
// https://leetcode.com/problems/distribute-candies-among-children-ii/submissions/1650447932/?envType=daily-question&envId=2025-06-01
