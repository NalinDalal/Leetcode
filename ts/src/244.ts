//1007. Minimum Domino Rotations For Equal Row

function check(target: number, tops: number[], bottoms: number[]): number {
  let rotationsTop = 0;
  let rotationsBottom = 0;
  let n = tops.length;

  for (let i = 0; i < n; ++i) {
    if (tops[i] != target && bottoms[i] != target) {
      return -1; // Cannot make all values equal to target
    } else if (tops[i] != target) {
      rotationsTop++; // Need to rotate to bring target to top
    } else if (bottoms[i] != target) {
      rotationsBottom++; // Need to rotate to bring target to bottom
    }
  }
  return Math.min(rotationsTop, rotationsBottom);
}
function minDominoRotations(tops: number[], bottoms: number[]): number {
  let result = check(tops[0], tops, bottoms);
  if (result != -1) return result;
  if (tops[0] != bottoms[0]) result = check(bottoms[0], tops, bottoms);

  return result;
}
//sub: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/submissions/1624041328/?envType=daily-question&envId=2025-05-03
