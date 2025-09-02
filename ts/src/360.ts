//3025. Find the Number of Ways to Place People I
function numberOfPairs(points: number[][]): number {
  const n = points.length;
  let ans = 0;

  for (let i = 0; i < n; i++) {
    const A = points[i];
    for (let j = 0; j < n; j++) {
      if (i === j) continue;
      const B = points[j];

      // A must be top-left, B must be bottom-right
      if (!(A[0] <= B[0] && A[1] >= B[1])) continue;

      // If there are only two points and the orientation is valid,
      // it's a valid rectangle (no third point to invalidate it).
      if (n === 2) {
        ans++;
        continue;
      }

      let illegal = false;
      for (let k = 0; k < n; k++) {
        if (k === i || k === j) continue;
        const P = points[k];

        const xIn = P[0] >= A[0] && P[0] <= B[0];
        const yIn = P[1] <= A[1] && P[1] >= B[1];
        if (xIn && yIn) {
          illegal = true;
          break;
        }
      }

      if (!illegal) ans++;
    }
  }

  return ans;
}
//sub: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/submissions/1757046600/?envType=daily-question&envId=2025-09-02
//sol: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/solutions/7148156/3025-find-the-number-of-ways-to-place-pe-cw1y/
