/* 1760. Minimum Limit of Balls in a Bag

You are given an integer array nums where the ith bag contains nums[i] balls.
You are also given an integer maxOperations.

You can perform the following operation at most maxOperations times:

- Take any bag of balls and divide it into two new bags with a positive number
of balls.
- For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two
new bags of 2 and 3 balls.

Your penalty is the maximum number of balls in a bag. You want to minimize your
penalty after the operations.

Return the minimum possible penalty after performing the operations.


Example 1:
Input: nums = [9], maxOperations = 2
Output: 3
Explanation:
- Divide the bag with 9 balls into two bags of sizes 6 and 3. [9] -> [6,3].
- Divide the bag with 6 balls into two bags of sizes 3 and 3. [6,3] -> [3,3,3].
The bag with the most number of balls has 3 balls, so your penalty is 3 and you
should return 3.

Example 2:
Input: nums = [2,4,8,2], maxOperations = 4
Output: 2
Explanation:
- Divide the bag with 8 balls into two bags of sizes 4 and 4. [2,4,8,2] ->
[2,4,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,4,4,4,2] ->
[2,2,2,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,4,4,2] ->
[2,2,2,2,2,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,2,2,4,2] ->
[2,2,2,2,2,2,2,2]. The bag with the most number of balls has 2 balls, so your
penalty is 2, and you should return 2.


Constraints:

1 <= nums.length <= 10^5
1 <= maxOperations, nums[i] <= 10^9 */

#include <iostream>
#include <vector>
using namespace std;

/* Intuition:
 * use dp to store max num of balls in a bag
 * dp[i] is max num of balls in a bag of size i
 * dp[i]=max(dp[i],nums[i])
 * dp[i+1]=max(dp[i],nums[i]+dp[i])
 * */

// max of nums2 is 8
// 8 split into 4,4
// 4 split into 2,2{but divide 1 4 at a time, so if total 3 4's then take 3
// steps} do till maxoperations gets reduced to 0

class Solution {
public:
  int minLimit(vector<int>& nums, int maxoperations) {
    int n = nums.size();
    vector<int> dp(n + 1,
                   0); // dp is vector of size n+1 initialised with 0, dp[0]=0
    for (int i = 0; i < n; i++) {
      dp[i + 1] = max(dp[i], nums[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
      dp[i] = max(dp[i + 1], dp[i] + nums[i]);
    }
    return max(dp[0], dp[n]);
  }
};

// Time Complexity: O(n)
// Space complexity: O(n)

// issues:
/* 1. Purpose is Ambiguous:
The forward and backward passes seem to compute two separate transformations of
the array, but the purpose is unclear without additional context. The logic
appears inconsistent, as the second loop overwrites the dp array created in the
first loop.

2. Edge Cases:
What happens if nums is empty? The function would throw an error since
nums.size() would be 0, and accessing nums[i] is invalid.

3. Undefined Use of dp[n]:
In the first loop, dp[n] remains unmodified. The last valid index updated is
dp[n - 1]. */

// Approach:
/* 1. Lambda Function canDivide:
- Determines whether all numbers in the array can be split such that the largest
resulting value is ≤ maxBalls using at most maxOperations.
- For each number `n`, the required splits are:
`ceil(𝑛/maxBalls)−1=(𝑛+maxBalls−1)/maxBalls−1`
- Stops early if the total operations exceed maxOperations.

Binary Search:

2. Searches for the smallest feasible value of maxBalls using the canDivide
function.

3. Initialization: left = 1: The minimum possible value for the largest split.
right = max(nums): The largest number in the array.
4. Binary Search Logic:
- Compute the middle value mid.
- If canDivide(mid) returns true, update result and search in the left half.
- Otherwise, search in the right half.

5. Return Result:
- Returns left, which is the smallest feasible value after the binary search. */
class Solution1 {
public:
  int minimumSize(vector<int>& nums, int maxOperations) {
    auto canDivide = [&](int maxBalls) { // O(n*log m)
      int ops = 0;
      for (int n : nums) {
        ops += (n + maxBalls - 1) / maxBalls - 1; // ceil(n / maxBalls) - 1
        if (ops > maxOperations)
          return false;
      }
      return true;
    };

    int left = 1, right = *max_element(nums.begin(), nums.end());
    int result = right;

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (canDivide(mid)) {
        result = mid;
        right = mid; // Try smaller values
      } else {
        left = mid + 1; // Try larger values
      }
    }

    return left;
  }
};

// Time Complexity: O(n⋅log(max(nums)))
// Space Complexity: O(1)

int main() {
  Solution1 sol;
  vector<int> nums = {9, 8, 4, 2};
  int maxOperations = 3;
  cout << "Minimum possible largest value: "
       << sol.minimumSize(nums, maxOperations) << endl;
  return 0;
}
