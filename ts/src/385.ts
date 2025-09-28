//976. Largest Perimeter Triangle
function largestPerimeter(nums: number[]): number {
  nums.sort((a, b) => b - a); // sort descending
  const n = nums.length;

  for (let i = 0; i < n - 2; i++) {
    const a = nums[i],
      b = nums[i + 1],
      c = nums[i + 2];
    if (a < b + c) {
      return a + b + c;
    }
  }
  return 0;
}
//sub: https://leetcode.com/problems/largest-perimeter-triangle/submissions/1785397799/?envType=daily-question&envId=2025-09-28
//sol: https://leetcode.com/problems/largest-perimeter-triangle/solutions/7231449/976-largest-perimeter-triangle-by-nalind-9b47/
