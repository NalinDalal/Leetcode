/*3495. Minimum Operations to Make Array Elements Zero
You are given a 2D array queries, where queries[i] is of the form [l, r]. Each
queries[i] defines an array of integers nums consisting of elements ranging from
l to r, both inclusive.

In one operation, you can:

Select two integers a and b from the array.
Replace them with floor(a / 4) and floor(b / 4).
Your task is to determine the minimum number of operations required to reduce
all elements of the array to zero for each query. Return the sum of the results
for all queries.



Example 1:

Input: queries = [[1,2],[2,4]]

Output: 3

Explanation:

For queries[0]:

The initial array is nums = [1, 2].
In the first operation, select nums[0] and nums[1]. The array becomes [0, 0].
The minimum number of operations required is 1.
For queries[1]:

The initial array is nums = [2, 3, 4].
In the first operation, select nums[0] and nums[2]. The array becomes [0, 3, 1].
In the second operation, select nums[1] and nums[2]. The array becomes [0, 0,
0]. The minimum number of operations required is 2. The output is 1 + 2 = 3.

Example 2:

Input: queries = [[2,6]]

Output: 4

Explanation:

For queries[0]:

The initial array is nums = [2, 3, 4, 5, 6].
In the first operation, select nums[0] and nums[3]. The array becomes [0, 3, 4,
1, 6]. In the second operation, select nums[2] and nums[4]. The array becomes
[0, 3, 1, 1, 1]. In the third operation, select nums[1] and nums[2]. The array
becomes [0, 0, 0, 1, 1]. In the fourth operation, select nums[3] and nums[4].
The array becomes [0, 0, 0, 0, 0]. The minimum number of operations required
is 4. The output is 4.



Constraints:

1 <= queries.length <= 105
queries[i].length == 2
queries[i] == [l, r]
1 <= l < r <= 109


Hint 1
For a number x, the number of "/4" operations to change it to 0 is
floor(log4(x)) + 1.

Hint 2
Always pair the 2 numbers with the maximum "/4"
operations needed.
*/

class Solution {
public:
  long long minOperations(vector<vector<int>>& queries) {
    long long TO = 0;

    for (auto& query : queries) {
      long long l = query[0], r = query[1];
      long long ops = 0;

      long long max_ops = (r > 0) ? (long long)floor(log(r) / log(4)) + 1 : 0;

      for (long long k = 0; k <= max_ops; k++) {
        long long lower = (long long)pow(4, k);
        long long upper = (long long)pow(4, k + 1) - 1;

        lower = max(lower, l);
        upper = min(upper, r);

        if (lower <= upper) {
          long long count = upper - lower + 1;
          ops += count * (k + 1);
        }
      }
      TO += (ops + 1) / 2;
    }

    return TO;
  }
};
// sub:
// https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/submissions/1582923295/?envType=daily-question&envId=2025-09-06
// sol:
// https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/solutions/7160126/3495-minimum-operations-to-make-array-el-yvh5/
