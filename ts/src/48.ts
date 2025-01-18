// 201. Bitwise AND of Numbers Range

function rangeBitwiseAnd(left: number, right: number): number {
  let shift = 0;
  // Find common prefix by shifting right until left equals right
  while (left < right) {
    left >>= 1;
    right >>= 1;
    shift++;
  }
  // Left and right are equal, shift back to the original position
  return left << shift;
}
//sub: https://leetcode.com/problems/bitwise-and-of-numbers-range/submissions/1512454858/
//sol: https://leetcode.com/problems/bitwise-and-of-numbers-range/solutions/6298601/201-bitwise-and-of-numbers-range100-by-n-mebi/
