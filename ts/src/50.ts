// 3427. Sum of Variable Length Subarrays

function subarraySum(nums: number[]): number {
  let n: number = nums.length;
  let total_sum: number = 0;

  for (let i = 0; i < n; ++i) {
    let start: number = Math.max(0, i - nums[i]);
    for (let j = start; j <= i; ++j) {
      total_sum += nums[j];
    }
  }

  return total_sum;
}

//sub: https://leetcode.com/problems/sum-of-variable-length-subarrays/submissions/1513194447/
//sol: https://leetcode.com/problems/sum-of-variable-length-subarrays/solutions/6300918/3427-sum-of-variable-length-subarrays-10-kijs/
