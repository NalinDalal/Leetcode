//3000. Maximum Area of Longest Diagonal Rectangle
function areaOfMaxDiagonal(dimensions: number[][]): number {
  let ans: number = 0,
    maxDiagonalSq: number = 0;
  for (let i = 0; i < dimensions.length; i++) {
    let length: number = dimensions[i][0],
      width: number = dimensions[i][1];
    let diagonalSq = length * length + width * width;

    if (diagonalSq > maxDiagonalSq) {
      maxDiagonalSq = diagonalSq;
      ans = length * width;
    } else if (diagonalSq == maxDiagonalSq) {
      ans = Math.max(ans, length * width);
    }
  }
  return ans;
}
//sub: https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/submissions/1748421625/?envType=daily-question&envId=2025-08-26
//sol: https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/solutions/7122777/3000-maximum-area-of-longest-diagonal-re-96wl/
