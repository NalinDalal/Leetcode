//452. Minimum Number of Arrows to Burst Balloons
function findMinArrowShots(points: number[][]): number {
  if (points.length === 0) return 0;

  // Sort by end coordinate
  points.sort((a, b) => a[1] - b[1]);

  let arrows = 1;
  let end = points[0][1];

  for (let i = 1; i < points.length; i++) {
    if (points[i][0] > end) {
      arrows++;
      end = points[i][1];
    }
  }

  return arrows;
}

function overlapGroupCount(points: number[][]): number {
  const total = points.length;
  const arrows = findMinArrowShots(points);
  return total - arrows;
}
//sub: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/submissions/1602556921/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/solutions/6636009/452-minimum-number-of-arrows-to-burst-ba-9inp/
