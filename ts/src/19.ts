//2270. Number of Ways to Split Array
function waysToSplitArray(nums: number[]): number {
  let n: number = nums.length;
  let totalSum: number = 0;

  for (let num of nums) {
    totalSum += num;
  }

  let leftSum: number = 0;
  let ans: number = 0;

  for (let i = 0; i < n - 1; i++) {
    leftSum += nums[i];
    let rightSum: number = totalSum - leftSum;
    if (leftSum >= rightSum) ans++;
  }
  return ans;
}
// t.ly/x2Wzs
