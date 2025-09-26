//611. Valid Triangle Number
function triangleNumber(nums: number[]): number {
  nums.sort((a, b) => a - b);
  const n = nums.length;
  let count = 0;

  for (let k = n - 1; k >= 2; k--) {
    let i = 0,
      j = k - 1;

    while (i < j) {
      if (nums[i] + nums[j] > nums[k]) {
        count += j - i;
        j--;
      } else {
        i++;
      }
    }
  }

  return count;
}
//sub: https://leetcode.com/problems/valid-triangle-number/submissions/1782940823/?envType=daily-question&envId=2025-09-26
//sol: https://leetcode.com/problems/valid-triangle-number/solutions/7224634/611-valid-triangle-number-by-nalindalal2-1wfq/
