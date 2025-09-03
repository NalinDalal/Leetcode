//3027. Find the Number of Ways to Place People II
function numberOfPairs(points: number[][]): number {
  let ans = 0;

  points.sort((a, b) => a[0] - b[0] || b[1] - a[1]);

  for (let i = 0; i < points.length - 1; i++) {
    const pointA = points[i];
    const xRange = [pointA[0] - 1, Infinity];
    const yRange = [-Infinity, pointA[1] + 1];

    for (let j = i + 1; j < points.length; j++) {
      const pointB = points[j];

      if (
        pointB[0] > xRange[0] &&
        pointB[0] < xRange[1] &&
        pointB[1] > yRange[0] &&
        pointB[1] < yRange[1]
      ) {
        ans++;
        xRange[0] = pointB[0];
        yRange[0] = pointB[1];
      }
    }
  }

  return ans;
}
//sub: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/submissions/1758210401/?envType=daily-question&envId=2025-09-03
//sol: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/solutions/7151371/3027-find-the-number-of-ways-to-place-pe-ds67/
