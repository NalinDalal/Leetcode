//3151. Special Array I

function isArraySpecial(nums: number[]): boolean {
  if (nums.length == 1) {
    return true;
  }
  for (let i = 0; i < nums.length - 1; i++) {
    if (nums[i] % 2 == nums[i + 1] % 2) return false;
  }
  return true;
}

//sub: https://leetcode.com/problems/special-array-i/submissions/1527271031/?envType=daily-question&envId=2025-02-01
//sol: https://leetcode.com/problems/special-array-i/solutions/6356244/3151-special-array-i100-by-nalindalal200-p2s4/
