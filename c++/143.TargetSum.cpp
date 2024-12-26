/*
https://leetcode.com/problems/target-sum/description/

494. Target Sum

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and
'-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and
concatenate them to build the expression "+2-1". Return the number of different
expressions that you can build, which evaluates to target.



Example 1:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be
target 3. -1 + 1 + 1 + 1 + 1 = 3 +1 - 1 + 1 + 1 + 1 = 3 +1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:
Input: nums = [1], target = 1
Output: 1


Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Intuition:
/* 1. This is the question to find how many ways of putting '+', '-' before each
x in nums to get target. It can be solved by 2D DP.
2. Set dp[j][sum] being the number of ways to get sum using the first j elements
of nums. The iterative DP with optimized space is done!In fact , the iterative
DP can be furthermore optimized only using 1D state array.
*/

// Approach:
/* 1. Let `sum=sum(nums)`, `diff=sum-target`. Suppose all signs +1.
2. If `diff<0` or `diff%2==1` it is impossible to get the target, return 0. Note
that the constraints: `0 <= sum(nums[i]) <= 1000`
3. Since change sign for x differed by 2x, perform `diff/=2`
4. Declare 2D C-array `int dp[21][1001]`. Note: ``(sum-target)/2+1<=1001``
5. Proceed a double loop
```cpp
dp[0][0]=1
for j in [1...n]
    for sum in [0...diff]
        iteration
```
6. In each iteration perform
```cpp
dp[j][sum] = dp[j-1][sum]; // not change sign

if (sum >= nums[j-1]) // change sign
    dp[j][sum]+=dp[j-1][sum-nums[j-1]];
```

7. `dp[n][diff]` is the answer
8. 2nd iterative DP is a slight space optimized by using the trick &1 which is
the same as %2. The space need is reduced to $$O(2×1001)$$
9. 3rd C++ code uses 1D state array. The subtle part is that the inner loop
should be inverse transversing to ensure the increment from the previous j.*/

int dp[21][1001];
class Solution {
public:
  int f(int j, int sum, vector<int>& nums) {
    if (j == 0)
      return sum == 0 ? 1 : 0;
    if (dp[j][sum] != -1)
      return dp[j][sum];
    int x = nums[j - 1];
    int ans = f(j - 1, sum, nums); // without change sign
    if (sum >= x)                  // sign change
      ans += f(j - 1, sum - x, nums);
    return dp[j][sum] = ans;
  }
  int findTargetSumWays(vector<int>& nums, int target) {
    const int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int diff = sum - target;

    // Check if it's possible to achieve the target
    if (diff < 0 || diff % 2 != 0)
      return 0;

    diff /= 2;
    memset(dp, -1, sizeof(dp));
    return f(n, diff, nums);
  }
};

/* Time complexity:O(n.∣diff∣) where diff=sum(nums)-target

Space complexity:O(21×1001)→O(2×1001)→O(∣diff∣)*/
