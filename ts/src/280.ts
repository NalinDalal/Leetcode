//2616. Minimize the Maximum Difference of Pairs
function countValidPairs(nums: number[], threshold: number): number {
  let index = 0,
    count = 0;
  while (index < nums.length - 1) {
    if (nums[index + 1] - nums[index] <= threshold) {
      count++;
      index++;
    }
    index++;
  }
  return count;
}

function minimizeMax(nums: number[], p: number): number {
  nums.sort((a, b) => a - b);
  let left = 0,
    right = nums[nums.length - 1] - nums[0];

  while (left < right) {
    const mid = Math.floor(left + (right - left) / 2);
    if (countValidPairs(nums, mid) >= p) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

const result = minimizeMax([1, 3, 6, 19, 20], 2);
console.log(result);

//sub: https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/submissions/1662893916/?envType=daily-question&envId=2025-06-13
//sol: https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/solutions/6839534/2616-minimize-the-maximum-difference-of-zibpr/
