//532.AdjacentIncSubArrDet1.cpp
function maxIncreasingSubarrays(nums: number[]): number {
  const n = nums.length;
  let cnt = 1,
    precnt = 0,
    ans = 0;
  for (let i = 1; i < n; ++i) {
    if (nums[i] > nums[i - 1]) {
      ++cnt;
    } else {
      precnt = cnt;
      cnt = 1;
    }
    ans = Math.max(ans, Math.min(precnt, cnt));
    ans = Math.max(ans, Math.floor(cnt / 2));
  }
  return ans;
}
//sub: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/submissions/1802531163/?envType=daily-question&envId=2025-10-15
//sol: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/solutions/7277592/3350-adjacent-increasing-subarrays-detec-7y6u/
