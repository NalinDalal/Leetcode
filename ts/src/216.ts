//209. Minimum Size Subarray Sum
function minSubArrayLen(target: number, nums: number[]): number {
  let n: number = nums.length;
  let minLen: number = Math.min();
  let left: number = 0,
    sum: number = 0;

  for (let right = 0; right < n; ++right) {
    sum += nums[right];

    while (sum >= target) {
      minLen = Math.min(minLen, right - left + 1);
      sum -= nums[left++];
    }
  }

  return minLen === Infinity ? 0 : minLen;
}

//sub: https://leetcode.com/problems/minimum-size-subarray-sum/submissions/1604127838/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/minimum-size-subarray-sum/solutions/6641473/209-minimum-size-subarray-sum-by-nalinda-nf30/
