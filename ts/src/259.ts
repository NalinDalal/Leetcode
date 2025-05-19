//3024. Type of Triangle
function triangleType(nums: number[]): string {
  nums.sort((a, b) => a - b);
  const [a, b, c] = nums;

  if (a + b <= c) {
    return "none";
  }

  if (a === b && b === c) {
    return "equilateral";
  } else if (a === b || b === c || a === c) {
    return "isosceles";
  } else {
    return "scalene";
  }
}
//sub: https://leetcode.com/problems/type-of-triangle/submissions/1637718441/?envType=daily-question&envId=2025-05-19
