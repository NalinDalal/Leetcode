//812. Largest Triangle Area
function largestTriangleArea(points: number[][]): number {
  let N = points.length;
  let ans: number = 0;
  for (let i = 0; i < N; i++)
    for (let j = i + 1; j < N; ++j)
      for (let k = j + 1; k < N; ++k)
        ans = Math.max(ans, area(points[i], points[j], points[k]));

  return ans;
}

function area(P: number[], Q: number[], R: number[]): number {
  return (
    0.5 *
    Math.abs(
      P[0] * Q[1] +
        Q[0] * R[1] +
        R[0] * P[1] -
        P[1] * Q[0] -
        Q[1] * R[0] -
        R[1] * P[0],
    )
  );
}
//sub: https://leetcode.com/problems/largest-triangle-area/submissions/1783805670/?envType=daily-question&envId=2025-09-27
//sol: https://leetcode.com/problems/largest-triangle-area/solutions/7226991/812-largest-triangle-area-by-nalindalal2-o5u8/
