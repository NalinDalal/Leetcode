/*2438. Range Product Queries of Powers
Given a positive integer n, there exists a 0-indexed array called powers,
composed of the minimum number of powers of 2 that sum to n. The array is sorted
in non-decreasing order, and there is only one way to form the array.

You are also given a 0-indexed 2D integer array queries, where queries[i] =
[lefti, righti]. Each queries[i] represents a query where you have to find the
product of all powers[j] with lefti <= j <= righti.

Return an array answers, equal in length to queries, where answers[i] is the
answer to the ith query. Since the answer to the ith query may be too large,
each answers[i] should be returned modulo 109 + 7.



Example 1:
Input: n = 15, queries = [[0,1],[2,2],[0,3]]
Output: [2,4,64]
Explanation:
For n = 15, powers = [1,2,4,8]. It can be shown that powers cannot be a smaller
size. Answer to 1st query: powers[0] * powers[1] = 1 * 2 = 2. Answer to 2nd
query: powers[2] = 4. Answer to 3rd query: powers[0] * powers[1] * powers[2] *
powers[3] = 1 * 2 * 4 * 8 = 64. Each answer modulo 109 + 7 yields the same
answer, so [2,4,64] is returned.

Example 2:
Input: n = 2, queries = [[0,0]]
Output: [2]
Explanation:
For n = 2, powers = [2].
The answer to the only query is powers[0] = 2. The answer modulo 109 + 7 is the
same, so [2] is returned.


Constraints:
1 <= n <= 109
1 <= queries.length <= 105
0 <= starti <= endi < powers.length

Hint 1
The powers array can be created using the binary representation of n.
Hint 2
Once powers is formed, the products can be taken using brute force.
*/

/*Approach:
   //power array; array[i]=pow(2,i), till sum(array)=n

        //queries array; queries[i]=[left[i],right[i]]
        //find prod of all powers[j];left[i]<=j<=right[i]
        //answer array;answer[i]=answer to ith query
        //answer[i]=answer[i] modulo 10E9+7

*/

class Solution {
public:
  const int MOD = 1e9 + 7;

  long long modPow(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
      if (exp & 1)
        res = (res * base) % MOD;
      base = (base * base) % MOD;
      exp >>= 1;
    }
    return res;
  }

  vector<int> productQueries(int n, vector<vector<int>>& queries) {
    vector<int> powers;
    for (int i = 0; n > 0; i++) {
      if (n & 1)
        powers.push_back(1 << i);
      n >>= 1;
    }

    vector<long long> prefix(powers.size() + 1, 1);
    for (int i = 0; i < powers.size(); i++) {
      prefix[i + 1] = (prefix[i] * powers[i]) % MOD;
    }

    vector<int> ans;
    for (auto& q : queries) {
      int L = q[0], R = q[1];
      long long prod = (prefix[R + 1] * modPow(prefix[L], MOD - 2)) % MOD;
      ans.push_back((int)prod);
    }
    return ans;
  }
};
// sub:
// https://leetcode.com/problems/range-product-queries-of-powers/submissions/1730700394/?envType=daily-question&envId=2025-08-11
// sol:
// https://leetcode.com/problems/range-product-queries-of-powers/solutions/7066250/2438-range-product-queries-of-powers-by-lr4bn/
