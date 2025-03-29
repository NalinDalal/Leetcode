//162. Find Peak Element
function findPeakElement(nums: number[]): number {
  if (nums.length === 0) return -1;

  let maxIndex: number = 0;
  for (let i = 1; i < nums.length; i++) {
    if (nums[i] > nums[maxIndex]) maxIndex = i;
  }

  return maxIndex;
}
//sub: https://leetcode.com/problems/find-peak-element/submissions/1589635247/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/find-peak-element/solutions/6591239/162-find-peak-element-by-nalindalal2004-mcpc/
