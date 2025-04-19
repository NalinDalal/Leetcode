//2563. Count the Number of Fair Pairs
function countFairPairs(nums: number[], lower: number, upper: number): number {
  nums.sort((a, b) => a - b);
  let count = 0;

  const lowerBound = (arr: number[], target: number, start: number): number => {
    let left = start,
      right = arr.length;
    while (left < right) {
      let mid = Math.floor((left + right) / 2);
      if (arr[mid] < target) left = mid + 1;
      else right = mid;
    }
    return left;
  };

  const upperBound = (arr: number[], target: number, start: number): number => {
    let left = start,
      right = arr.length;
    while (left < right) {
      let mid = Math.floor((left + right) / 2);
      if (arr[mid] <= target) left = mid + 1;
      else right = mid;
    }
    return left;
  };

  for (let i = 0; i < nums.length; i++) {
    const left = lowerBound(nums, lower - nums[i], i + 1);
    const right = upperBound(nums, upper - nums[i], i + 1);
    count += right - left;
  }

  return count;
}
//sub: https://leetcode.com/problems/count-the-number-of-fair-pairs/submissions/1611126733/?envType=daily-question&envId=2025-04-19
//sol: https://leetcode.com/problems/count-the-number-of-fair-pairs/solutions/6665669/2563-count-the-number-of-fair-pairs-by-n-rk8n/
