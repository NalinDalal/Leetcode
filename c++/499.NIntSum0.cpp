/*1304. Find N Unique Integers Sum up to Zero
Given an integer n, return any array containing n unique integers such that they
add up to 0.



Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
Example 2:

Input: n = 3
Output: [-1,0,1]
Example 3:

Input: n = 1
Output: [0]


Constraints:

1 <= n <= 1000


Hint 1
Return an array where the values are symmetric. (+x , -x).
Hint 2
If n is odd, append value 0 in your returned array.
*/
// sum of ans must be 0
// if size is even, then a[i]=-a[n-i]
// else middle be 0, rest a[i]=-a[n-i]
class Solution {
public:
  vector<int> sumZero(int n) {
    vector<int> ans(n);
    int num = 1;
    for (int i = 0; i < n / 2; i++) {
      ans[i] = num;
      ans[n - i - 1] = -num;
      num++;
    }
    if (n % 2 == 1) {
      ans[n / 2] = 0; // middle element is zero
    }
    return ans;
  }
};
// sub:
// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/submissions/1762053687/?envType=daily-question&envId=2025-09-07
// sol:
// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/solutions/7163123/1304-find-n-unique-integers-sum-up-to-ze-tjsd/
