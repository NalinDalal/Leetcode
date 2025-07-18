/*2163. Minimum Difference in Sums After Removal of Elements
You are given a 0-indexed integer array nums consisting of 3 * n elements.

You are allowed to remove any subsequence of elements of size exactly n from
nums. The remaining 2 * n elements will be divided into two equal parts:

The first n elements belonging to the first part and their sum is sumfirst.
The next n elements belonging to the second part and their sum is sumsecond.
The difference in sums of the two parts is denoted as sumfirst - sumsecond.

For example, if sumfirst = 3 and sumsecond = 2, their difference is 1.
Similarly, if sumfirst = 2 and sumsecond = 3, their difference is -1.
Return the minimum difference possible between the sums of the two parts after
the removal of n elements.



Example 1:

Input: nums = [3,1,2]
Output: -1
Explanation: Here, nums has 3 elements, so n = 1.
Thus we have to remove 1 element from nums and divide the array into two equal
parts.
- If we remove nums[0] = 3, the array will be [1,2]. The difference in sums of
the two parts will be 1 - 2 = -1.
- If we remove nums[1] = 1, the array will be [3,2]. The difference in sums of
the two parts will be 3 - 2 = 1.
- If we remove nums[2] = 2, the array will be [3,1]. The difference in sums of
the two parts will be 3 - 1 = 2. The minimum difference between sums of the two
parts is min(-1,1,2) = -1. Example 2:

Input: nums = [7,9,5,8,1,3]
Output: 1
Explanation: Here n = 2. So we must remove 2 elements and divide the remaining
array into two parts containing two elements each. If we remove nums[2] = 5 and
nums[3] = 8, the resultant array will be [7,9,1,3]. The difference in sums will
be (7+9) - (1+3) = 12. To obtain the minimum difference, we should remove
nums[1] = 9 and nums[4] = 1. The resultant array becomes [7,5,8,3]. The
difference in sums of the two parts is (7+5) - (8+3) = 1. It can be shown that
it is not possible to obtain a difference smaller than 1.


Constraints:

nums.length == 3 * n
1 <= n <= 105
1 <= nums[i] <= 105


Hint 1
The lowest possible difference can be obtained when the sum of the first n
elements in the resultant array is minimum, and the sum of the next n elements
is maximum. Hint 2 For every index i, think about how you can find the minimum
possible sum of n elements with indices lesser or equal to i, if possible. Hint
3 Similarly, for every index i, try to find the maximum possible sum of n
elements with indices greater or equal to i, if possible. Hint 4 Now for all
indices, check if we can consider it as the partitioning index and hence find
the answer.

*/

/*intuition:
- Remove n elements from the array nums of size 3n.

- Split the remaining 2n elements into two equal parts of size n: the first part
and the second part.

- Minimize sum(first part) - sum(second part).

To minimize sum(first) - sum(second), we aim to:
    - minimize sum(first) (smallest n elements possible from the left part),
    - maximize sum(second) (largest n elements possible from the right part).
    */
/* Approach:
1. Let `n = nums.size() / 3`

2. Iterate over the array:

    - From left to right, maintain min sum of `n` largest elements in the first
`i+1` elements → `left[i]`

    - From right to left, maintain max sum of `n` smallest elements in the last
`len - i` elements → `right[i]`

3. For each partition index `i`, where `i` ranges from `n-1` to `2n-1`,
calculate:

    - `diff = left[i] - right[i + 1]`

    - Keep track of the minimum difference

4. Use max-heap (inverted to min-heap with -x) to maintain the n smallest
elements for the right part.

5. Use min-heap to maintain the n largest elements for the left part.
*/
class Solution {
public:
  long long minimumDifference(vector<int>& nums) {
    int n = nums.size() / 3;
    int total = nums.size();

    // Left: maintain max-heap for n largest elements
    priority_queue<int> maxHeap;
    vector<long long> leftSum(total, 0);
    long long leftTotal = 0;

    for (int i = 0; i < total; ++i) {
      maxHeap.push(nums[i]);
      leftTotal += nums[i];
      if (maxHeap.size() > n) {
        leftTotal -= maxHeap.top();
        maxHeap.pop();
      }
      if (i >= n - 1) {
        leftSum[i] = leftTotal;
      }
    }

    // Right: maintain min-heap for n smallest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<long long> rightSum(total, 0);
    long long rightTotal = 0;

    for (int i = total - 1; i >= 0; --i) {
      minHeap.push(nums[i]);
      rightTotal += nums[i];
      if (minHeap.size() > n) {
        rightTotal -= minHeap.top();
        minHeap.pop();
      }
      if (i <= total - n) {
        rightSum[i] = rightTotal;
      }
    }

    // Try all partition points and find the minimal difference
    long long result = LLONG_MAX;
    for (int i = n - 1; i < 2 * n; ++i) {
      result = min(result, leftSum[i] - rightSum[i + 1]);
    }

    return result;
  }
};

// sub:
// https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/submissions/1702051070/?envType=daily-question&envId=2025-07-18
// sol:
// https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/solutions/6972926/2163-minimum-difference-in-sums-after-re-l96p/
