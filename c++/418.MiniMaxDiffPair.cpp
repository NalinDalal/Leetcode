/* 2616. Minimize the Maximum Difference of Pairs
You are given a 0-indexed integer array nums and an integer p. Find p pairs of
indices of nums such that the maximum difference amongst all the pairs is
minimized. Also, ensure no index appears more than once amongst the p pairs.

Note that for a pair of elements at the index i and j, the difference of this
pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.

Return the minimum maximum difference among all p pairs. We define the maximum
of an empty set to be zero.



Example 1:

Input: nums = [10,1,2,7,1,3], p = 2
Output: 1
Explanation: The first pair is formed from the indices 1 and 4, and the second
pair is formed from the indices 2 and 5. The maximum difference is max(|nums[1]
- nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.
Example 2:

Input: nums = [4,2,1,2], p = 1
Output: 0
Explanation: Let the indices 1 and 3 form a pair. The difference of that pair is
|2 - 2| = 0, which is the minimum we can attain.


Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
0 <= p <= (nums.length)/2


Can we use dynamic programming here?
Hint 2
To minimize the answer, the array should be sorted first.
Hint 3
The recurrence relation is fn(i, x) = min(fn(i+1, x),
max(abs(nums[i]-nums[i+1]), fn(i+2, p-1)), and fn(0,p) gives the desired answer.
*/

/*sort the array beforehand. This way, we can narrow down the selection of pairs
to only adjacent numbers, and avoid wasting time on incorrect choices. start
from a threshold (a maximum difference) of 0 and incrementally try all possible
thresholds:
- try to find p pairs with a difference less than or equal to 0.
- if not possible, try to find p pairs with a difference less than or equal
to 1.
- and so on, until we find a threshold that succeeds.

if we find p pair with threshold x, then can find for x+1 also
if can't find for x so also can't find for x-1

finding p pair->
sort nums, find nums[i]-nums[i+1]; if diff<x=> valid pair
*/

// algo:
/* 1. countValidPairs(threshold) to find the number of pairs having a threshold
of threshold in nums n=nums.size(), count=0, iterate from 0 to n-2 if(nums[index
+ 1] - nums[index] <= threshold)count++ return count
2. sort nums
3. int left = 0 ,right = nums[n - 1] - nums[0];
4. while(left<right){
    mid=left + (right - left) // 2
    5. Calculate the number of valid pairs with a threshold of mid using
countValidPairs(mid)
    6. If countValidPairs(mid) >= p, continue with the left half by setting
right = mid. Otherwise, continue with the right half by setting left = mid - 1.
Repeat from step 4.
7. return left
}
    */
class Solution {
public:
  // Find the number of valid pairs by greedy approach
  int countValidPairs(vector<int>& nums, int threshold) {
    int index = 0, count = 0;
    while (index < nums.size() - 1) {
      // If a valid pair is found, skip both numbers.
      if (nums[index + 1] - nums[index] <= threshold) {
        count++;
        index++;
      }
      index++;
    }
    return count;
  }

  int minimizeMax(vector<int>& nums, int p) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int left = 0, right = nums[n - 1] - nums[0];

    while (left < right) {
      int mid = left + (right - left) / 2;

      // If there are enough pairs, look for a smaller threshold.
      // Otherwise, look for a larger threshold.
      if (countValidPairs(nums, mid) >= p) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};
// sub:
// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/submissions/1662892641/?envType=daily-question&envId=2025-06-13
// sol:
// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/solutions/6839534/2616-minimize-the-maximum-difference-of-zibpr/
// TIme: O(n⋅logV+n⋅logn)    V-> max(nums)
// Space: O(n)
