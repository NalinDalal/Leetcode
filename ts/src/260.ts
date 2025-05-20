//3355. Zero Array Transformation I

function isZeroArray(nums: number[], queries: number[][]): boolean {
  const deltaArray: number[] = new Array(nums.length + 1).fill(0);
  for (const [left, right] of queries) {
    deltaArray[left] += 1;
    deltaArray[right + 1] -= 1;
  }
  const operationCounts: number[] = [];
  let currentOperations = 0;
  for (const delta of deltaArray) {
    currentOperations += delta;
    operationCounts.push(currentOperations);
  }
  for (let i = 0; i < nums.length; i++) {
    if (operationCounts[i] < nums[i]) {
      return false;
    }
  }
  return true;
}
//sub: https://leetcode.com/problems/zero-array-transformation-i/submissions/1638975276/?envType=daily-question&envId=2025-05-20
