//2460. Apply Operations to an Array
function applyOperations(nums: number[]): number[] {
  for (let i = 0; i < nums.length - 1; i++) {
    if (nums[i] == nums[i + 1]) {
      nums[i] = nums[i] * 2;
      nums[i + 1] = 0;
    }
  }
  let nonZeroIndex: number = 0;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] != 0) {
      //swap(nums[i],nums[nonZeroIndex]);
      [nums[nonZeroIndex], nums[i]] = [nums[i], nums[nonZeroIndex]];
      nonZeroIndex++;
    }
  }

  return nums;
}

//sub: https://leetcode.com/problems/apply-operations-to-an-array/submissions/1558698692/?envType=daily-question&envId=2025-03-01
//sol: https://leetcode.com/problems/apply-operations-to-an-array/solutions/6479258/2460-apply-operations-to-an-array-by-nal-kctz/
