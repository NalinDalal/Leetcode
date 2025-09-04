//3516. Find Closest Person
function findClosest(x: number, y: number, z: number): number {
  let aDist = Math.abs(z - x);
  let bDist = Math.abs(z - y);

  if (aDist < bDist) return 1;
  else if (aDist > bDist) return 2;
  else return 0;
}
//sub: https://leetcode.com/problems/find-closest-person/submissions/1758941498/?envType=daily-question&envId=2025-09-04
//sol: https://leetcode.com/problems/find-closest-person/solutions/7153442/3516-find-closest-person-by-nalindalal20-d66w/
