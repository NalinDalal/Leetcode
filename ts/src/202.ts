//149. Max Points on a Line
function gcd(a: number, b: number): number {
  return b === 0 ? a : gcd(b, a % b);
}

function maxPoints(points: number[][]): number {
  const n = points.length;
  if (n <= 1) return n;

  let maxCount = 1;

  for (let i = 0; i < n; i++) {
    const slopeMap = new Map<string, number>();
    let duplicate = 1,
      currMax = 0;

    for (let j = i + 1; j < n; j++) {
      let dx = points[j][0] - points[i][0];
      let dy = points[j][1] - points[i][1];

      if (dx === 0 && dy === 0) {
        duplicate++; // Same point
        continue;
      }

      const g = gcd(dx, dy);
      dx /= g;
      dy /= g;

      const slope = `${dy}/${dx}`;
      slopeMap.set(slope, (slopeMap.get(slope) || 0) + 1);
      currMax = Math.max(currMax, slopeMap.get(slope)!);
    }

    maxCount = Math.max(maxCount, currMax + duplicate);
  }

  return maxCount;
}

// Example Usage
const points = [
  [1, 1],
  [2, 2],
  [3, 3],
  [4, 1],
  [5, 2],
  [6, 3],
];
console.log("Max points on a straight line:", maxPoints(points));

//sub: https://leetcode.com/problems/max-points-on-a-line/submissions/1596180075/?envType=study-plan-v2&envId=top-interview-150
//sol: https://leetcode.com/problems/max-points-on-a-line/solutions/6613216/149-max-points-on-a-line-by-nalindalal20-bjlx/
